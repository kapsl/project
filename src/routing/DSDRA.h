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

#ifndef __NETWORKSTRUCTURES_DSDRA_H_
#define __NETWORKSTRUCTURES_DSDRA_H_

#include <omnetpp.h>
#include "InterfaceEntry.h"
#include "IPv4Address.h"
#include "IPv4Datagram.h"
#include "IPSocket.h"
#include "INetfilter.h"
#include "UDPPacket.h"
#include "AODVControlPackets_m.h"
#include "IPv4ControlInfo.h"
#include "RoutingServerControlData_m.h"
#include "IRoutingTable.h"
#include "IPv4Route.h"
#include "IInterfaceTable.h"
#include "RoutingTableAccess.h"
#include "InterfaceTableAccess.h"
#include "AODVRouteData.h"
#include "Coord.h"
#include "GraphUtil.h"

/**
 * I think, this class handles the basis station
 */
class D2DRA: public cSimpleModule {
public:
    std::map<IPv4Address, std::map<IPv4Address, double> > djkstraInfo;

    typedef std::pair<IPv4Address, MACAddress> RouteData;
    typedef std::list<RouteData> Route;
    Route route;

protected:
    bool isOperational;
    INetfilter *networkProtocol;
    cModule *host;
    IRoutingTable *routingTable;
    IInterfaceTable *interfaceTable;

    unsigned int sequenceNum; // nur für testzwecke
    unsigned int aodvUDPPort;
    simtime_t lastBroadcastTime;
    cPar *jitterPar;
    cPar *periodicJitter;

    typedef tNetworkTopologyGraph<IPv4Address> NetworkGraph;
    NetworkGraph networkGraph;

    /*
     * Simulaton Values
     */

    cOutVector delayofReceivedREEQ;
    int rreqIterator;
private:

    typedef std::map<IPv4Address, NodeCharacteristic> GraphInformations;
    typedef std::pair<IPv4Address, NodeCharacteristic> GraphInformationPair;
protected:
    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);
    virtual int numInitStages() const {
        return 5;
    }
    virtual void sendRoutingServerPacket(AODVControlPacket *packet,
            const IPv4Address& destAddr, unsigned int timeToLive, double delay);
    virtual void handleRouteRequest(AODVRREQ *rreq, IPv4Address& address);
    virtual void handleRegistrationRequest(RegistrationRequest *packet,
            const IPv4Address& address);
    virtual RouteResponse *createRouteReply(AODVRREQ *rreq, Route &route);
    virtual RegistrationConfirmation* createRegConfirmation(
            const IPv4Address& address);
    virtual void handleTopologyUpdate(NetworkTopologyUpdate *topologyUpdate,
            IPv4Address& address);
    virtual void updateNetworkTopologyGraph();
    private:
    virtual void clearState();
    virtual void positionHandling();
public:
    D2DRA();
    virtual ~D2DRA();
    virtual void finish();

    /*
     * Statistic section
     */
private:
    static simsignal_t rcvdRREQSignal;
    static simsignal_t sentRREPSignal;
};
#endif
