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

#include "WLanPacketCapsulation.h"
#include "UDPControlInfo.h"

Define_Module(WLanPacketCapsulation);

void WLanPacketCapsulation::initialize(int stage) {
    if (stage == 0) {
        upperLayerIn = gate("upperLayerIn");
        interfaceTable = InterfaceTableAccess().get();
        arpCache = ArpAccess().get();
        host = getContainingNode(this);
        lastBroadcastTime = SIMTIME_ZERO;
        routingTable = RoutingTableAccess().get();
        defaultUDPPort = par("udpPort");
        delayTime = par("delayTime");
        timeToLive = par("timeToLive");
        hasPayload = false;
        rebootTime = SIMTIME_ZERO;

    } else if (stage == 4) {
        NodeStatus *nodeStatus = dynamic_cast<NodeStatus *>(host->getSubmodule(
                "status"));
        isOperational = !nodeStatus || nodeStatus->getState() == NodeStatus::UP;
        nb = NotificationBoardAccess().get();
        nb->subscribe(this, NF_IPv4_ROUTE_ADDED);
        nb->subscribe(this, NF_IPv4_ROUTE_CHANGED);
    }

}
/*
 * routeQueue stores routes while the next hop towards the
 * destination is inserted in the RoutingTable
 */
std::set<Route*> WLanPacketCapsulation::routeQueue;


/*
 * Method controls the incoming and outgoing traffic
 */
void WLanPacketCapsulation::handleMessage(cMessage *msg) {
    hasPayload = false;
    IPv4Datagram *datagram = NULL;
/*
 * if message is sent from upper layer
 * if message is an arp request an arp-reply is sent to the upper layer
 * if message is an aodv packet and has a route, route and data are sent to
 * the next hop
 */
    if (msg->getArrivalGate() == upperLayerIn) {
        if (dynamic_cast<ARPPacket *>(msg)) {

            bool hasKnownDest = false;
            InterfaceEntry *ie = interfaceTable->getInterfaceByName("wlan0");
            Ieee802Ctrl *controlInfo = new Ieee802Ctrl();

            for (std::set<Route*>::iterator it = routeQueue.begin();
                    it != routeQueue.end(); it++) {
                ARPPacket * arp = dynamic_cast<ARPPacket *>(msg);

                if ((*it)->begin()->first == arp->getDestIPAddress()) {
                    if (arp->getOpcode() == ARP_RARP_REQUEST
                            || arp->getOpcode() == ARP_REQUEST) {
                        hasKnownDest = true;
                        delete arp->removeControlInfo();

                        arp->setDestIPAddress(routingTable->getRouterId());
                        arp->setDestMACAddress(ie->getMacAddress());
                        controlInfo->setDest(ie->getMacAddress());
                        arp->setName("fakeArpReply");
                        arp->setSrcIPAddress((*it)->begin()->first);
                        arp->setSrcMACAddress((*it)->begin()->second);
                        arp->setOpcode(ARP_REPLY);
                        controlInfo->setEtherType(ETHERTYPE_ARP);
                        controlInfo->setInterfaceId(ie->getInterfaceId());
                        arp->setControlInfo(controlInfo);

                        send(arp, "upperLayerOut");

                        break;
                    }
                }

            }
            if (!hasKnownDest)
                send(msg, "mgmntOut");
        } else {
            datagram = dynamic_cast<IPv4Datagram*>(msg);
            Ieee802Ctrl *ieeeCtrInfo =
                    dynamic_cast<Ieee802Ctrl *>(datagram->removeControlInfo());

            if (UDPPacket *udpPacket =
                    dynamic_cast<UDPPacket*>(datagram->decapsulate())) {
                cPacket *CPacket =
                        dynamic_cast<cPacket*>(udpPacket->decapsulate());
                if (CPacket) {
                    udpPacket->encapsulate(CPacket);
                    AODVControlPacket* aodvControlPacket =
                            dynamic_cast<AODVControlPacket*>(udpPacket->decapsulate());
                    if (aodvControlPacket == NULL) {
                        udpPacket->encapsulate(CPacket);

                        Route *route = 0;

                        for (std::set<Route*>::iterator it = routeQueue.begin();
                                it != routeQueue.end(); it++) {
                            if ((*it)->begin()->first
                                    == arpCache->getIPv4AddressFor(
                                            ieeeCtrInfo->getDest())) {
                                route = (*it);
                            }

                        }

                        if (route) {
                            PayLoadData *payloadData = new PayLoadData;
                            payloadData->setRoute(*route);
                            routeQueue.erase(route);
                            UDPPacket *tmpUDPPacket = new UDPPacket;


                            payloadData->encapsulate(udpPacket);
                            tmpUDPPacket->encapsulate(payloadData);
                            datagram->encapsulate(tmpUDPPacket);
                            datagram->setControlInfo(ieeeCtrInfo);

                            send(datagram, "mgmntOut");
                        } else {
                            datagram->encapsulate(udpPacket);
                            datagram->setControlInfo(ieeeCtrInfo);
                            send(datagram, "mgmntOut");
                        }
                    } else {
                        udpPacket->encapsulate(aodvControlPacket);
                        datagram->setControlInfo(ieeeCtrInfo);
                        datagram->encapsulate(udpPacket);
                        send(datagram, "mgmntOut");
                    }
                }
            }

        }
    } else {
/*
 * if message is sent from lower layer
 * arp-packets are sent to the upper layer
 * aodv-packets which contain a route are splited and treated different
 */
        if (dynamic_cast<ARPPacket *>(msg)) {
            send(msg, "upperLayerOut");
        } else {

            datagram = dynamic_cast<IPv4Datagram*>(msg);
            Ieee802Ctrl *ieeee802CtrlInfo =
                    dynamic_cast<Ieee802Ctrl *>(datagram->removeControlInfo());
            UDPPacket* udpPacket =
                    dynamic_cast<UDPPacket*>(datagram->decapsulate());
            cPacket *CPacket = dynamic_cast<cPacket*>(udpPacket->decapsulate());

            if (CPacket) {
                udpPacket->encapsulate(CPacket);
                AODVControlPacket* aodvControlPacket =
                        dynamic_cast<AODVControlPacket*>(udpPacket->decapsulate());

                if (aodvControlPacket) {
                    if (aodvControlPacket->getPacketType() == PAYLOADMSG) {



                        PayLoadData *payloadData = check_and_cast<PayLoadData*>(
                                aodvControlPacket);

                        if ((payloadData->getRoute().begin()->first)
                                == routingTable->getRouterId()) {

                            UDPPacket *packet =
                                    dynamic_cast<UDPPacket*>(payloadData->decapsulate());
                            udpIpv4Datagram = datagram;
                            udpIpv4Datagram->encapsulate(packet);
                            udpIpv4Datagram->setControlInfo(ieeee802CtrlInfo);

                            if ((payloadData->getRoute().rbegin()->first)
                                    == routingTable->getRouterId()) {
                                send(udpIpv4Datagram, "upperLayerOut");
                            } else {
                                RouteResponse *routeResponse = new RouteResponse;
                                routeResponse->setRoute(
                                        (payloadData->getRoute()));
                                routeResponse->setLifeTime(simTime());
                                routeResponse->setName(
                                        "LOCAL-ROUTERESPONSE-MSG");
                                routeResponse->setIsHostWhoRequested(false);

                                UDPPacket *routeResponseUDPPacket =
                                        new UDPPacket(routeResponse->getName());
                                routeResponseUDPPacket->encapsulate(
                                        routeResponse);
                                routeResponseUDPPacket->setSourcePort(
                                        defaultUDPPort);
                                routeResponseUDPPacket->setDestinationPort(
                                        defaultUDPPort);

                                IPv4Datagram * ipv4Datatagram =
                                        new IPv4Datagram(
                                                "LOCAL-ROUTERESPONSE-MSG");
                                ipv4Datatagram->setByteLength(IP_HEADER_BYTES);
                                ipv4Datatagram->setDestAddress(
                                        routingTable->getRouterId());
                                ipv4Datatagram->setSrcAddress(
                                        routingTable->getRouterId());
                                ipv4Datatagram->setTransportProtocol(
                                        IP_PROT_MANET);

                                ipv4Datatagram->encapsulate(
                                        routeResponseUDPPacket);

                                Ieee802Ctrl *controlInfo = new Ieee802Ctrl();
                                controlInfo->setDest(
                                        arpCache->getMACAddressFor(
                                                routingTable->getRouterId()));
                                controlInfo->setEtherType(ETHERTYPE_IPv4);
                                ipv4Datatagram->setControlInfo(controlInfo);

                                hasPayload = true;
                                send(ipv4Datatagram, "upperLayerOut");
                            }
                        }

                        delete payloadData;
                        payloadData = NULL;
                        delete udpPacket;
                    } else {
                        udpPacket->encapsulate(aodvControlPacket);
                        datagram->encapsulate(udpPacket);
                        datagram->setControlInfo(ieeee802CtrlInfo);
                        send(datagram, "upperLayerOut");
                    }
                } else {
                    udpPacket->encapsulate(CPacket);
                    datagram->encapsulate(udpPacket);
                    datagram->setControlInfo(ieeee802CtrlInfo);
                    send(datagram, "upperLayerOut");
                }

            }

        }
    }
}

bool WLanPacketCapsulation::handleOperationStage(LifecycleOperation *operation,
        int stage, IDoneCallback *doneCallback) {
    Enter_Method_Silent
    ();
    if (dynamic_cast<NodeStartOperation *>(operation)) {
        if (stage == NodeStartOperation::STAGE_APPLICATION_LAYER) {
            isOperational = true;
            rebootTime = simTime();

        }

    } else if (dynamic_cast<NodeShutdownOperation *>(operation)) {
        if (stage == NodeShutdownOperation::STAGE_APPLICATION_LAYER) {
            isOperational = false;

            clearState();
        }
    } else if (dynamic_cast<NodeCrashOperation *>(operation)) {
        if (stage == NodeCrashOperation::STAGE_CRASH) {
            isOperational = false;

            clearState();
        }
    } else
        throw cRuntimeError("Unsupported lifecycle operation '%s'",
                operation->getClassName());

    return true;
}
/*
 * This method is invoked when a new route is inserted in the routingTable
 * if the inserted destination and destination of the payload are the same
 * the payload is sent to the upper layer
 */
void WLanPacketCapsulation::receiveChangeNotification(int category,
        const cObject *details) {
    Enter_Method
    ("receiveChangeNotification");
    if (hasPayload) {
        if (category == NF_IPv4_ROUTE_ADDED
                || category == NF_IPv4_MROUTE_CHANGED) {
            IPv4Route *ipv4Route = check_and_cast<IPv4Route*>(details);
            if (ipv4Route) {
                AODVRouteData *routeData =
                        ipv4Route ?
                                dynamic_cast<AODVRouteData *>(ipv4Route->getProtocolData()) :
                                NULL;
                if (routeData) {

                    Route *route = 0;

                    for (std::set<Route*>::iterator it = routeQueue.begin();
                            it != routeQueue.end(); it++) {

                        if ((*it)->rbegin()->first
                                == udpIpv4Datagram->getDestAddress()) {
                            route = ((*it));
                        }
                    }

                    if (route
                            && ipv4Route->getDestination()
                                    == udpIpv4Datagram->getDestAddress()) {
                        hasPayload = false;

                        send(udpIpv4Datagram, "upperLayerOut");

                    }
                }

            }
        }
    }
}
void WLanPacketCapsulation::clearState() {

}
WLanPacketCapsulation::WLanPacketCapsulation() {
    udpIpv4Datagram = NULL;
    upperLayerIn = NULL;
    interfaceTable = NULL;
    host = NULL;
    arpCache = NULL;
    routingTable = NULL;
    nb = NULL;
}

WLanPacketCapsulation::~WLanPacketCapsulation() {
    clearState();
}

