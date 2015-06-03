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

#include "RoutingServerManagement.h"
#include "IPSocket.h"
#include <omnetpp.h>
#include <math.h>

Define_Module(RoutingServerManagement);

void RoutingServerManagement::initialize(int stage) {
    if (stage == 0) {
        lastBroadcastTime = SIMTIME_ZERO;
        topologyUpdate = new NeighborTopologyData;
        ownCharacteristic = new HostCharacteristic;
        routingTable = RoutingTableAccess().get();
        interfaceTable = InterfaceTableAccess().get();
        mobility = MobilityAccess().get();
        networkProtocol = check_and_cast<INetfilter *>(
                getModuleByPath(par("networkProtocolModule")));
        networkLayerIn = gate("rsMgmntNLIn");
        AODVRoutingIn = gate("rsMgmnAODVtIn");
        host = getContainingNode(this);
        delayTimeServerRegistration = par("delayTimeServerRegistration");
        delayTimeTopologyUpdate = par("delayTimeTopologyUpdate");
        isRegistrated = false;        //par("isRegistrated");
        allowedHelloLoss = par("allowedHelloLoss");
        defaultUDPPort = par("udpPort");
        timeToLive = par("timeToLive");
        periodicJitter = &par("periodicJitter");
        serverUpdateInteval = par("serverUpdateInterval");
        maxRoutesInCache = par("maxRouteCacheSize");
        helloInterval = par("helloInterval");
        useHelloMessages = par("useHelloMessages");
        serverRegRetryInterval = par("serverRegRetryInterval");
        myRouteTimeout = par("myRouteTimeout");
        rebootTime = SIMTIME_ZERO;

        speedParameterStudy = par("speedParameterStudy");

        /*
         * Evaluation
         */
        delayOfRREQ.setName("Delay of RREQ");
        numberOfRREP = 0;
        numberOfRREQSent = 0;

    } else if (stage == 4) {
        NodeStatus *nodeStatus = dynamic_cast<NodeStatus *>(host->getSubmodule(
                "status"));
        isOperational = !nodeStatus || nodeStatus->getState() == NodeStatus::UP;

        umtsAddress =
                interfaceTable->getInterfaceByName("umtsIface")->ipv4Data()->getIPAddress();

        networkTopologyUpdate = new cMessage("Topology-Update-MSG");
        checkServerRegistration = new cMessage(
                "Server-Registration-Request-MSG");
        if (!isRegistrated) {
            scheduleAt(simTime() + delayTimeServerRegistration,
                    checkServerRegistration);
        }
        if (useHelloMessages) {
            helloMsgTimer = new cMessage("HelloMsgTimer");
        }
    }
}

/*
 * Method is invoked when a message is sent to the module
 * The looks after the type of message and invokes the corresponding method
 */
void RoutingServerManagement::handleMessage(cMessage *msg) {

    if (msg->getKind() == IP_C_REGISTER_PROTOCOL) {
        send(msg, "rsMgmntNLOut");
    } else if (msg->isSelfMessage()) {
        if (checkServerRegistration == msg && !isRegistrated) {
            handleRegistrationRequest();
        } else if (msg == networkTopologyUpdate) {
            handleTopologyUpdateTable();
        } else if (msg == helloMsgTimer) {
            sendNeighborUpdateIfNeeded();
        }
    } else {
        UDPPacket *udpPacket = dynamic_cast<UDPPacket *>(msg);
        AODVControlPacket *aodvControlData =
                check_and_cast<AODVControlPacket *>(udpPacket->decapsulate());
        IPv4ControlInfo *udpProtocolCtrlInfo =
                dynamic_cast<IPv4ControlInfo *>(udpPacket->getControlInfo());
        ASSERT(udpProtocolCtrlInfo != NULL);
        IPv4Address sourceAddr = udpProtocolCtrlInfo->getSrcAddr();
        if ((aodvControlData->getPacketType() == RREQ)
                || (aodvControlData->getPacketType() == RREPACK)) {
            if (msg->getArrivalGate() == networkLayerIn) {
                delete udpPacket;
            }
            if (msg->getArrivalGate() == AODVRoutingIn) {
                handleRouteRequest(check_and_cast<AODVRREQ*>(aodvControlData));

            }
        } else if (aodvControlData->getPacketType() == RREP) {
            if (msg->getArrivalGate() == networkLayerIn) {
                AODVRREP *packet = check_and_cast<AODVRREP *>(aodvControlData);
                if (packet->getOriginatorAddr().isUnspecified()) {
                    /*
                     *AODV Hello MSG are not supported
                     */
                    throw cRuntimeError(
                            "Simulation only works without AODV's own  %d",
                            aodvControlData->getPacketType());

                }
                delete udpPacket;
            }
            if (msg->getArrivalGate() == AODVRoutingIn) {
                udpPacket->encapsulate(aodvControlData);
                send(udpPacket, "rsMgmntNLOut");

            }
        } else if (aodvControlData->getPacketType() == RERR) {
            if (msg->getArrivalGate() == networkLayerIn) {
                udpPacket->encapsulate(aodvControlData);
                send(udpPacket, "rsMgmntAODVOut");
            } else
                handleRoutError(check_and_cast<AODVRERR*>(aodvControlData),
                        sourceAddr);

        } else if (aodvControlData->getPacketType()

        == REGISTRATIONCONFIRMATIONMSG) {
            handleRegistrationConfirmation(
                    check_and_cast<RegistrationConfirmation*>(aodvControlData),
                    sourceAddr);
            delete udpPacket;
        } else if (aodvControlData->getPacketType()
                == NETWORKTOPOLOGYUPDATEMSG) {
            EV_INFO << "komisch" << endl;
            delete aodvControlData;
            delete udpPacket;
        } else if (aodvControlData->getPacketType() == REGISTRATIONREQUESTMSG) {
            EV
                      << "Server Registration Broadcast Request arrived. This is not the Routing Server. Packet will be deleted"
                      << endl;
            delete aodvControlData;
            delete udpPacket;

        } else if (aodvControlData->getPacketType() == ROUTERESPONSEMSG) {
            handleRouteResponse(
                    check_and_cast<RouteResponse*>(aodvControlData));
            delete udpPacket;
        } else if (aodvControlData->getPacketType() == NEIGHBORUPDATEMESSAGE) {
            handleHelloMessage(
                    check_and_cast<NeighborUpdateMessage*>(aodvControlData),
                    sourceAddr);
            delete udpPacket;
        } else {
            throw cRuntimeError(
                    "AODV Control Packet arrived with undefined packet type: %d",
                    aodvControlData->getPacketType());
        }
    }
}

/**
 * handleRouteResponse inserts the destination and the next hop
 * of the received route into the routingTable
 */
void RoutingServerManagement::handleRouteResponse(RouteResponse* routeResonse) {

    if (routeResonse->getIsHostWhoRequested()) {
        simtime_t creationTime = routeResonse->getCreationTimeRREQ();
        simtime_t delay = simTime() - creationTime;
        delayOfRREQ.record(delay);
        numberOfRREP = numberOfRREP + 1;
    }
//    std::cout << routeResonse->getRoute().begin()->first << endl;
//    std::cout << routingTable->getRouterId() << endl;
    if ((routeResonse->getRoute().begin()->first)
            == routingTable->getRouterId()) {
        if ((routeResonse->getRoute().size() > 1)) {
            routeResonse->getRoute().remove(*routeResonse->getRoute().begin());

            if (WLanPacketCapsulation::routeQueue.size() >= 1) {
//                std::cout << WLanPacketCapsulation::routeQueue.size() << endl;
            }

            for (typename std::set<Route*>::iterator it =
                    WLanPacketCapsulation::routeQueue.begin();
                    it != WLanPacketCapsulation::routeQueue.end(); it++) {
//                std::cout << *(*it)->rbegin() << endl;
//                std::cout << *(routeResonse->getRoute().rbegin()) << endl;
                if ((*it)->rbegin()->first
                        == (routeResonse->getRoute().rbegin()->first)) {
                    WLanPacketCapsulation::routeQueue.erase((*it));

                }
            }
//            std::cout << WLanPacketCapsulation::routeQueue.size() << endl;
            WLanPacketCapsulation::routeQueue.insert(&routeResonse->getRoute());
            AODVRREP* rrep = createRREP(
                    (routeResonse->getRoute().rbegin()->first), myRouteTimeout);
            sendLocalPacket(rrep, (routeResonse->getRoute().rbegin()->first), 1,
                    0, routeResonse->getRoute().begin()->first);
        } else {
            delete routeResonse;
        }

    }

}

/*
 * method is invoked when a new NeighborUpdateMessage has to be sent
 */
void RoutingServerManagement::sendNeighborUpdateIfNeeded() {
    ASSERT(useHelloMessages);
    bool hasActiveRoute = false;

    for (int i = 0; i < routingTable->getNumRoutes(); i++) {
        IPv4Route *route = routingTable->getRoute(i);

        if (route->getSource() == this) {
            AODVRouteData *routeData = check_and_cast<AODVRouteData *>(
                    route->getProtocolData());

            if (routeData->isActive()) {
                hasActiveRoute = true;

                break;
            }
        }
    }

    if (hasActiveRoute
            && (lastBroadcastTime == 0
                    || simTime() - lastBroadcastTime > helloInterval)) {
        EV_INFO << "It is hello time, broadcasting Hello Messages with TTL=1"
                       << endl;

        NeighborUpdateMessage *neighborUpdate = createNeighborUpdateMessage();
        sendAODVPacket(neighborUpdate, IPv4Address::ALLONES_ADDRESS, 1, 0);
    }

    scheduleAt(simTime() + helloInterval - periodicJitter->doubleValue(),
            helloMsgTimer);
}

/*
 * createNeighborUpdateMessage creates and returns an object of the type
 * NeighborUpdateMessage
 */
NeighborUpdateMessage *RoutingServerManagement::createNeighborUpdateMessage() {
    NeighborUpdateMessage *neighborUpdate = new NeighborUpdateMessage(
            "NEIGHBOR_UPDATE_MSG");
    neighborUpdate->setPacketType(NEIGHBORUPDATEMESSAGE);
    neighborUpdate->setPosition(mobility->getCurrentPosition());
    neighborUpdate->setMacAddress(
            interfaceTable->getInterfaceByName("wlan0")->getMacAddress());

    return neighborUpdate;
}

/*
 * Method changes the destination of the RREQ and forwards the packet
 */ 
void RoutingServerManagement::handleRouteRequest(AODVRREQ *rreq) {
    sendRoutingServerPacket(rreq, serverInformation.serverAddress, 3, 0);

}

/*
 * Method is invoked by a self-msg.
 * Method sends a RegistrationRequest to the RoutingService
 */
void RoutingServerManagement::handleRegistrationRequest() {
    RegistrationRequest* regRequest = createRegistrationRequest();
    sendRoutingServerPacket(regRequest, IPv4Address::ALLONES_ADDRESS, 3, 0);
    scheduleAt(simTime() + serverRegRetryInterval, checkServerRegistration);
}

/**
 * Method creates and returns a RegistrationRequest 
 */
RegistrationRequest*
RoutingServerManagement::createRegistrationRequest() {
    RegistrationRequest *regRequest = new RegistrationRequest(
            "SERVER_REGISTRATION_MSG");
    regRequest->setPacketType(REGISTRATIONREQUESTMSG);
    regRequest->setLifeTime(simTime());
    regRequest->setHopCount(0);
    return regRequest;
}

void RoutingServerManagement::handleRegistrationConfirmation(
        RegistrationConfirmation *packet, IPv4Address& address) {
    IPv4Route *existingRoute = routingTable->findBestMatchingRoute(address);
    if (!existingRoute || existingRoute->getSource() != this) {
        createRoute(address, address, 0, true, 0, true, simTime(), true);
    }
    existingRoute = 0;
    isRegistrated = true;
    serverInformation.serverAddress = address;
    scheduleAt(simTime() + periodicJitter->doubleValue(), helloMsgTimer);
    scheduleAt(simTime() + delayTimeTopologyUpdate, networkTopologyUpdate);
    delete packet;
}

/**
 * Method handles the incomming NeighborUpdateMessages
 */
void RoutingServerManagement::handleHelloMessage(NeighborUpdateMessage *packet,
        IPv4Address& srcAddress) {
    EV_INFO << "Received Neighbor Update Data" << endl;
//livetime was hello allowedHelloLoss * helloInterval
//    std::cerr << host->getId() << endl;
    topologyUpdate->updateLinkedNeighbor(srcAddress, packet->getMacAddress(),
            packet->getPosition(), simTime());
    delete packet;

}

/**
 * updates the local neighborhoodTable
 */
void RoutingServerManagement::handleTopologyUpdateTable() {
    topologyUpdate->printTopologyUpdateData(routingTable->getRouterId());
    topologyUpdate->updateNeighborhoodTopology(allowedHelloLoss, timeToLive,
            helloInterval);

    // Probably here we have to calculate the speed and adapt the serverUpdateInterval
    double vx = mobility->getCurrentSpeed().x;
    double vy = mobility->getCurrentSpeed().y;

    double speed = sqrt(vx * vx + vy * vy);

    //std::cout << "Speed : " << speed << "\n";

    // TODO find some good value to adapt the interval
    // Make parameter study
    simtime_t adaptedServerUpdateInterval;

    switch (speedParameterStudy) {
    case 1: adaptedServerUpdateInterval = 0.3; break;
    case 2: adaptedServerUpdateInterval = 0.5; break;
    case 3: adaptedServerUpdateInterval = 1; break;
    case 4: adaptedServerUpdateInterval = 2; break;
    case 5: adaptedServerUpdateInterval = 5; break;
    case 6: adaptedServerUpdateInterval = 10; break;
    case 7: adaptedServerUpdateInterval = 15; break;
    case 8: adaptedServerUpdateInterval = 20; break;
    case 9: adaptedServerUpdateInterval = 30; break;
    case 10: adaptedServerUpdateInterval = this->adaptSendingInterval(speed, 1, 5); break;
    case 11: adaptedServerUpdateInterval = this->adaptSendingInterval(speed, 1, 10); break;
    case 12: adaptedServerUpdateInterval = this->adaptSendingInterval(speed, 1, 20); break;
    case 13: adaptedServerUpdateInterval = this->adaptSendingInterval(speed, 5, 15); break;
    }

    //std::cout << "Adapted Interval : " << adaptedServerUpdateInterval << "\n";

    scheduleAt(
            simTime() + adaptedServerUpdateInterval - delayTimeTopologyUpdate,
            networkTopologyUpdate);

    if (isRegistrated && topologyUpdate->getNetworkTopologyTable().size() > 0) {
        NetworkTopologyUpdate* neighborhodUpdate =
                createNetworkTopologyUpdate();

        sendRoutingServerPacket(neighborhodUpdate,
                serverInformation.serverAddress, 3, 0);
    }
}

/**
 * Get the sending interval from moving speed.
 */
double RoutingServerManagement::adaptSendingInterval(double speed, double minInterval, double maxInterval) {
    // If we are faster than 5 m/s don't send more often
    if (speed < 5.0) {
        return ((maxInterval - minInterval) / (-5)) * speed + maxInterval;
    } else {
        return minInterval;
    }
}

/**
 * creates  RREQ for each RERR
 */
void RoutingServerManagement::handleRoutError(AODVRERR *rerr,
        IPv4Address &srcAddress) {
    for (int i = 0; i < rerr->getUnreachableNodesArraySize(); i++) {
        IPv4Route *inactiveRoute = routingTable->findBestMatchingRoute(
                rerr->getUnreachableNodes(i).addr);
        AODVRouteData *routeData =
                inactiveRoute ?
                        dynamic_cast<AODVRouteData *>(inactiveRoute->getProtocolData()) :
                        NULL;
        if (routeData) {
            routingTable->deleteRoute(inactiveRoute);
        }

        AODVRREQ *aodvRREQ = new AODVRREQ;
        aodvRREQ->setOriginatorAddr(routingTable->getRouterId());
        aodvRREQ->setDestAddr(rerr->getUnreachableNodes(i).addr);
        aodvRREQ->setName("ROUTE_REPAIR_MSG");
        sendRoutingServerPacket(aodvRREQ, serverInformation.serverAddress, 3,
                0);

    }
    delete rerr;
}

/**
 * Method sends NetworkTopologyUpdate-msgs to the server
 */
NetworkTopologyUpdate*
RoutingServerManagement::createNetworkTopologyUpdate() {
    NetworkTopologyUpdate *neighborhodUpdate = new NetworkTopologyUpdate(
            "TOPOLOGY-UPDATE-MSG");

    neighborhodUpdate->setPacketType(NETWORKTOPOLOGYUPDATEMSG);
    neighborhodUpdate->setHopCount(0);
    neighborhodUpdate->setLifeTime(simTime());
    neighborhodUpdate->setNeighbors(topologyUpdate->getNetworkTopologyTable());

    ownCharacteristic->setLifeTime(simTime());
    ownCharacteristic->setMacAddress(
            interfaceTable->getInterfaceByName("wlan0")->getMacAddress());
    ownCharacteristic->setOriginatorAddress(routingTable->getRouterId());
    ownCharacteristic->setPosition(mobility->getCurrentPosition());
    neighborhodUpdate->setHostCharacteristic(*ownCharacteristic);

    return neighborhodUpdate;
}

/**
 * The functionality of this method is not implemented yet.
 * the method should maintain the routingTable. Routes have to be
 * deleted depending on defined criteria
 */
void RoutingServerManagement::maintainRouteCache() {

    std::vector<std::pair<IPv4Address, SimTime> > orderedVector;
    while (routingTable->getNumRoutes() > 0
            && routingTable->getNumRoutes() < maxRoutesInCache) {

        for (int i = routingTable->getNumRoutes() - 1; i >= 0; i--) {
            IPv4Route *route = routingTable->getRoute(i);
            if (AODVRouteData *routeData =
                    dynamic_cast<AODVRouteData *>(route->getProtocolData())) {
                if (route->getSource() != this) {
                    if (!routeData->isActive()) {
                        routingTable->deleteRoute(route);
                        return;
                    }
                    orderedVector.push_back(
                            std::make_pair(route->getDestination(),
                                    routeData->getLifeTime()));

                }
            }
        }

    }
}

/**
 * creates a new route and inserts the route in the routingTable
 */
void RoutingServerManagement::createRoute(const IPv4Address& destAddr,
        const IPv4Address& nextHop, unsigned int hopCount, bool hasValidDestNum,
        unsigned int destSeqNum, bool isActive, simtime_t lifeTime,
        bool isUMTS) {
    IPv4Route *route = new IPv4Route;
    AODVRouteData *newProtocolData = new AODVRouteData;

    newProtocolData->setHasValidDestNum(hasValidDestNum);
    newProtocolData->setIsActive(isActive);
    newProtocolData->setLifeTime(lifeTime);
    newProtocolData->setDestSeqNum(destSeqNum);

    InterfaceEntry *ifEntry;
    if (isUMTS)
        ifEntry = interfaceTable->getInterfaceByName("umtsIface");
    else
        ifEntry = interfaceTable->getInterfaceByName("wlan0");

    if (ifEntry)
        route->setInterface(ifEntry);
    route->setProtocolData(newProtocolData);
    route->setDestination(destAddr);
    route->setSource(this);
    route->setMetric(0);
    route->setGateway(nextHop);
    route->setNetmask(IPv4Address::ALLONES_ADDRESS);

    EV_DETAIL << "Adding route to server " << route << endl;
    routingTable->addRoute(route);

}

/**
 * Method creates and returns a  RREP
 */
AODVRREP *
RoutingServerManagement::createRREP(const IPv4Address& destAddress,
        simtime_t creationTime) {
    AODVRREP *rrep = new AODVRREP("AODV-RREP");
    rrep->setPacketType(RREP);

// When generating a RREP message, a node copies the Destination IP
// IPv4Address and the Originator Sequence Number from the RREQ message into
// the corresponding fields in the RREP message.

    rrep->setDestAddr(destAddress);
    rrep->setOriginatorSeqNum(1);

// OriginatorAddr = The IP address of the node which originated the RREQ
// for which the route is supplied.
    rrep->setOriginatorAddr(routingTable->getRouterId());

// Processing is slightly different, depending on whether the node is
// itself the requested destination (see section 6.6.1), or instead
// if it is an intermediate node with an fresh enough route to the destination
// (see section 6.6.2).

// intermediate node
// it copies its known sequence number for the destination into
// the Destination Sequence Number field in the RREP message.

    rrep->setDestSeqNum(1);

// The intermediate node places its distance in hops from the
// destination (indicated by the hop count in the routing table)
// Hop Count field in the RREP.

    rrep->setHopCount(0);

// The Lifetime field of the RREP is calculated by subtracting the
// current time from the expiration time in its route table entry.

    rrep->setLifeTime(creationTime);

    return rrep;
}

/**
 * Method is invoked when a message has to be sent to the RoutingService
 */
void RoutingServerManagement::sendRoutingServerPacket(AODVControlPacket *packet,
        const IPv4Address& destAddr, unsigned int timeToLive, double delay) {
    IPv4ControlInfo *networkProtocolControlInfo = new IPv4ControlInfo();

    /*
     * Statistics
     */
    if (packet->getPacketType() == RREQ) {
        numberOfRREQSent = numberOfRREQSent + 1;
    }
    InterfaceEntry *ifEntry = interfaceTable->getInterfaceByName("umtsIface");
    networkProtocolControlInfo->setTimeToLive(timeToLive);
    networkProtocolControlInfo->setProtocol(IP_PROT_MANET);
    networkProtocolControlInfo->setDestAddr(destAddr);

    networkProtocolControlInfo->setSrcAddr(ifEntry->ipv4Data()->getIPAddress());
    networkProtocolControlInfo->setInterfaceId(ifEntry->getInterfaceId());

    UDPPacket *udpPacket = new UDPPacket(packet->getName());
    udpPacket->encapsulate(packet);
    udpPacket->setSourcePort(defaultUDPPort);
    udpPacket->setDestinationPort(defaultUDPPort);
    udpPacket->setControlInfo(
            dynamic_cast<cObject *>(networkProtocolControlInfo));

    if (delay == 0)
        send(udpPacket, "rsMgmntNLOut");
    else
        sendDelayed(udpPacket, delay, "rsMgmntNLOut");
}

/**
 * The method is invoked when a packet has to be sent to any nearby
 * UserEquipment
 */
void RoutingServerManagement::sendAODVPacket(AODVControlPacket *packet,
        const IPv4Address& destAddr, unsigned int timeToLive, double delay) {
    IPv4ControlInfo *networkProtocolControlInfo = new IPv4ControlInfo();

    networkProtocolControlInfo->setTimeToLive(timeToLive);

    networkProtocolControlInfo->setProtocol(IP_PROT_MANET);
    networkProtocolControlInfo->setDestAddr(destAddr);
    networkProtocolControlInfo->setSrcAddr(routingTable->getRouterId());

    InterfaceEntry *ifEntry = interfaceTable->getInterfaceByName("wlan0");
    networkProtocolControlInfo->setInterfaceId(ifEntry->getInterfaceId());

    UDPPacket *udpPacket = new UDPPacket(packet->getName());
    udpPacket->encapsulate(packet);
    udpPacket->setSourcePort(defaultUDPPort);
    udpPacket->setDestinationPort(defaultUDPPort);
    udpPacket->setControlInfo(
            dynamic_cast<cObject *>(networkProtocolControlInfo));
    if (packet->getPacketType() == NEIGHBORUPDATEMESSAGE) {
        if (destAddr.isLimitedBroadcastAddress())
            lastBroadcastTime = simTime();
    }
    if (delay == 0)
        send(udpPacket, "rsMgmntNLOut");
    else
        sendDelayed(udpPacket, delay, "rsMgmntNLOut");
}

/**
 * the method send aodv-msgs within the own UserEquipment
 */
void RoutingServerManagement::sendLocalPacket(AODVControlPacket *packet,
        const IPv4Address& destAddr, unsigned int timeToLive, double delay,
        const IPv4Address& srcAddress) {
    IPv4ControlInfo *networkProtocolControlInfo = new IPv4ControlInfo();

    networkProtocolControlInfo->setTimeToLive(timeToLive);
    networkProtocolControlInfo->setProtocol(IP_PROT_MANET);
    networkProtocolControlInfo->setDestAddr(destAddr);
    networkProtocolControlInfo->setSrcAddr(srcAddress);

    UDPPacket *udpPacket = new UDPPacket(packet->getName());
    udpPacket->encapsulate(packet);
    udpPacket->setSourcePort(defaultUDPPort);
    udpPacket->setDestinationPort(defaultUDPPort);
    udpPacket->setControlInfo(
            dynamic_cast<cObject *>(networkProtocolControlInfo));

    if (delay == 0)
        send(udpPacket, "rsMgmntAODVOut");
    else
        sendDelayed(udpPacket, delay, "rsMgmntAODVOut");
}

/**
 * This method deactivates the UserEquipment
 */ 
bool RoutingServerManagement::handleOperationStage(
        LifecycleOperation *operation, int stage, IDoneCallback *doneCallback) {
    Enter_Method_Silent
    ();
    if (dynamic_cast<NodeStartOperation *>(operation)) {
        if (stage == NodeStartOperation::STAGE_APPLICATION_LAYER) {
            isOperational = true;
            rebootTime = simTime();
            clearState();
            if (!isRegistrated)
                scheduleAt(simTime(), checkServerRegistration);

            scheduleAt(
                    simTime() + serverUpdateInteval
                            - periodicJitter->doubleValue(),
                    networkTopologyUpdate);
        }

    } else if (dynamic_cast<NodeShutdownOperation *>(operation)) {
        if (stage == NodeShutdownOperation::STAGE_APPLICATION_LAYER) {
            isOperational = false;
            isRegistrated = false;
            topologyUpdate->removeNeighborTopologyData();
            clearState();
        }
    } else if (dynamic_cast<NodeCrashOperation *>(operation)) {
        if (stage == NodeCrashOperation::STAGE_CRASH) {
            isOperational = false;
            isRegistrated = false;
            clearState();
        }
    } else
        throw cRuntimeError("Unsupported lifecycle operation '%s'",
                operation->getClassName());

    return true;
}

void RoutingServerManagement::finish() {
    recordScalar("Number Received RouteResponses", numberOfRREP);
    recordScalar("Number Sent RREQs", numberOfRREQSent);
}
void RoutingServerManagement::clearState() {
    cancelEvent(checkServerRegistration);
    cancelEvent(networkTopologyUpdate);
    cancelEvent(helloMsgTimer);
}
RoutingServerManagement::RoutingServerManagement() {
    checkServerRegistration = NULL;
    networkTopologyUpdate = NULL;
    helloMsgTimer = NULL;
    interfaceTable = NULL;
    host = NULL;
    routingTable = NULL;
    topologyUpdate = NULL;
    mobility = NULL;
}
RoutingServerManagement::~RoutingServerManagement() {
    clearState();
    delete ownCharacteristic;
    delete networkTopologyUpdate;
    delete helloMsgTimer;
//    delete topologyUpdate; //hier muss noch eine lösung gefunden werden!!!
    delete checkServerRegistration;
    //    delete &umtsAddress;
}

