//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "DSDRA.h"
#include "NodeStatus.h"

Define_Module(D2DRA);
simsignal_t D2DRA::rcvdRREQSignal = registerSignal("rcvdRREQD2DRS");
simsignal_t D2DRA::sentRREPSignal = registerSignal("sentRREPD2DRS");

void D2DRA::initialize(int stage) {
    if (stage == 0) {
        routingTable = RoutingTableAccess().get();
        interfaceTable = InterfaceTableAccess().get();
        sequenceNum = 0;
        lastBroadcastTime = SIMTIME_ZERO;
        aodvUDPPort = par("udpPort");

        /*
         * Statistic
         */
        delayofReceivedREEQ.setName("Number of RREQ received");
    } else if (stage == 4) {
        NodeStatus *nodeStatus = dynamic_cast<NodeStatus *>(host->getSubmodule(
                "status"));
        isOperational = !nodeStatus || nodeStatus->getState() == NodeStatus::UP;
        IPSocket socket(gate("d2dOut"));
        socket.registerProtocol(IP_PROT_MANET);
    }
}

/*
 * Method is invoked when a message is sent to the module
 * The looks after the type of message and invokes the corresponding method
 */
void D2DRA::handleMessage(cMessage *msg) {
    UDPPacket *udpPacket = dynamic_cast<UDPPacket *>(msg);
    AODVControlPacket *aodvControlData = check_and_cast<AODVControlPacket *>(
            udpPacket->decapsulate());
    IPv4ControlInfo *udpProtocolCtrlInfo =
            dynamic_cast<IPv4ControlInfo *>(udpPacket->getControlInfo());
    ASSERT(udpProtocolCtrlInfo != NULL);
    IPv4Address sourceAddr = udpProtocolCtrlInfo->getSrcAddr();
    if (aodvControlData->getPacketType() == RREQ) {

        handleRouteRequest(check_and_cast<AODVRREQ*>(aodvControlData),
                sourceAddr);
    } else if (aodvControlData->getPacketType() == RREP) {
        EV_INFO << "HELLOPACKAGE will be dicharged" << endl;
    } else if (aodvControlData->getPacketType() == NETWORKTOPOLOGYUPDATEMSG) {
        handleTopologyUpdate(
                check_and_cast<NetworkTopologyUpdate*>(aodvControlData),
                sourceAddr);
    } else if (aodvControlData->getPacketType() == REGISTRATIONREQUESTMSG) {
        handleRegistrationRequest(
                check_and_cast<RegistrationRequest *>(aodvControlData),
                sourceAddr);

    } else {
        throw cRuntimeError(
                "AODV Control Packet arrived with undefined packet type: %d",
                aodvControlData->getPacketType());
    }
    delete udpPacket;

}

/**
 * This method stores the IP of the UserEquipment in the routingTable
 * of the D2DRS
 */
void D2DRA::handleRegistrationRequest(RegistrationRequest *packet,
        const IPv4Address& address) {
    IPv4Route *newRoute = new IPv4Route;
    newRoute->setGateway(address);
    newRoute->setDestination(address);
    newRoute->setNetmask(IPv4Address::ALLONES_ADDRESS);
    newRoute->setSource(this);
    
    newRoute->setMetric(0);
    InterfaceEntry *ifEntry = interfaceTable->getInterfaceByName("umtsIface");
    newRoute->setInterface(ifEntry);
    routingTable->addRoute(newRoute);

    sendRoutingServerPacket(this->createRegConfirmation(address), address, 3,
            0);
    delete packet;

}

/*
 * Creates a new RegistrationConfirmationMessage
 */
RegistrationConfirmation* D2DRA::createRegConfirmation(
        const IPv4Address &address) {
    RegistrationConfirmation *regConfirmationMSG = new RegistrationConfirmation(
            "REGISTRATION_CONFIRMATION-MSG");
    regConfirmationMSG->setHopCount(0);
    regConfirmationMSG->setLifeTime(simTime());
    regConfirmationMSG->setPacketType(REGISTRATIONCONFIRMATIONMSG);

    return regConfirmationMSG;

}

/**
 * The Method sends meessagees to the UserEquipments
 */
void D2DRA::sendRoutingServerPacket(AODVControlPacket *packet,
        const IPv4Address& destAddr, unsigned int timeToLive, double delay) {
    ASSERT(timeToLive != 0);

    IPv4ControlInfo *networkProtocolControlInfo = new IPv4ControlInfo;

    networkProtocolControlInfo->setTimeToLive(timeToLive);

    networkProtocolControlInfo->setProtocol(IP_PROT_MANET);
    networkProtocolControlInfo->setDestAddr(destAddr);
    networkProtocolControlInfo->setSrcAddr(routingTable->getRouterId());

    InterfaceEntry *ifEntry = interfaceTable->getInterfaceByName("umtsIface");
    networkProtocolControlInfo->setInterfaceId(ifEntry->getInterfaceId());

    UDPPacket *udpPacket = new UDPPacket(packet->getName());
    udpPacket->encapsulate(packet);
    udpPacket->setSourcePort(aodvUDPPort);
    udpPacket->setDestinationPort(aodvUDPPort);
    udpPacket->setControlInfo(
            dynamic_cast<cObject *>(networkProtocolControlInfo));

    if (destAddr.isLimitedBroadcastAddress())
        lastBroadcastTime = simTime();

    if (delay == 0)
        send(udpPacket, "d2dOut");
    else
        sendDelayed(udpPacket, delay, "d2dOut");
}

/**
 * This method cosntructs and mantains the networkGraph
 */
void D2DRA::handleTopologyUpdate(NetworkTopologyUpdate *topologyUpdate,
        IPv4Address& address) {
    NetworkGraph subGraph;
    Neighbors neighbors = topologyUpdate->getNeighbors();

    GraphUtil::removeElement(
            topologyUpdate->getHostCharacteristic().getOriginatorAddress());

    // We have to create a nodeCharacteristics element and copy the data
    NodeCharacteristic *nodeCharacteristic = new NodeCharacteristic(
            topologyUpdate->getHostCharacteristic());

    // Detect congestion
    /*if (nodeCharacteristic->getCongestionState() == 1) {
        EV << "We have a congestion!!!";
    }*/

    GraphUtil::insertElement(
            topologyUpdate->getHostCharacteristic().getOriginatorAddress(),
            *nodeCharacteristic);

    networkGraph.remove_vertex(
            topologyUpdate->getHostCharacteristic().getOriginatorAddress());

    for (std::vector<HostCharacteristic>::iterator it = neighbors.begin();
            it != neighbors.end(); it++) {
        GraphUtil::removeElement(it->getOriginatorAddress());

        nodeCharacteristic = new NodeCharacteristic(*it);

        GraphUtil::insertElement(it->getOriginatorAddress(), *nodeCharacteristic);

        networkGraph.insert_edge(
                topologyUpdate->getHostCharacteristic().getOriginatorAddress(),
                it->getOriginatorAddress());
        networkGraph.insert_edge(it->getOriginatorAddress(),
                topologyUpdate->getHostCharacteristic().getOriginatorAddress());
    }

    delete topologyUpdate;
}

void D2DRA::handleRouteRequest(AODVRREQ *rreq, IPv4Address& address) {
    emit(rcvdRREQSignal, rreq);
    delayofReceivedREEQ.record(simTime() - rreq->getCreationTime());
    networkGraph.computeDijkstra(rreq->getOriginatorAddr());
    std::list<IPv4Address> &shortestPath = networkGraph.computeShortestPathTo(
            rreq->getDestAddr(), rreq->getOriginatorAddr());
//    networkGraph.printShortestPath();
    route.erase(route.begin(), route.end());
    for (std::list<IPv4Address>::iterator it = shortestPath.begin();
            it != shortestPath.end(); it++) {
//        std::cout << *it << endl;

        route.push_back(
                RouteData(*it,
                        GraphUtil::getElement(*it)->second.getMacAddress()));

    }
    for (Route::iterator it = route.begin(); it != route.end(); it++) {
//        std::cout << it->second << endl;
//        MACAddress test = it->second;
//        std::cout << test.str() << endl;
//        std::cout << test << endl;
    }
    RouteResponse *routeResponse = 0;
    if (route.size() != 0) {
        routeResponse = createRouteReply(rreq, route);
        sendRoutingServerPacket(routeResponse, address, 3, 0);
        emit(sentRREPSignal, routeResponse);
    } else {

/**
 * TODO !
 * If no route could be found 
 * The UserEquipment has to be infomed about that
 */
//        route.push_front(rreq->getOriginatorAddr());
//        route.push_back(IPv4Address::UNSPECIFIED_ADDRESS);
//        route.push_back(rreq->getDestAddr());
//        routeResponse = createRouteReply(rreq, route);
//        sendRoutingServerPacket(routeResponse, address, 3, 0);
    }

    delete rreq;
}

/*
 * Method creates and returns a a route
 */
RouteResponse *D2DRA::createRouteReply(AODVRREQ *rreq, Route &route) {
    RouteResponse *rrep = new RouteResponse("ROUTE-RESPONSE-MSG");
    rrep->setPacketType(ROUTERESPONSEMSG);
    rrep->setRoute(route);
    rrep->setLifeTime(simTime());
    rrep->setCreationTimeRREQ(rreq->getCreationTime());
    rrep->setIsHostWhoRequested(true);

    return rrep;
}

void D2DRA::updateNetworkTopologyGraph() {

}

void D2DRA::positionHandling() {

}

void D2DRA::finish() {
}
void D2DRA::clearState() {

}
D2DRA::~D2DRA() {
    clearState();
}
D2DRA::D2DRA() {

}

