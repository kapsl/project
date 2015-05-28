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

#ifndef __NETWORKSTRUCTURES_ROUTECAPSULATION_H_
#define __NETWORKSTRUCTURES_ROUTECAPSULATION_H_

#include <omnetpp.h>
#include "IInterfaceTable.h"
#include "IPv4Datagram.h"
#include "ARPPacket_m.h"
#include "InterfaceTableAccess.h"
#include "UDPPacket.h"
#include "IPv4ControlInfo.h"
#include "AODVControlPackets_m.h"
#include "Ieee802Ctrl_m.h"
#include "RoutingServerControlData_m.h"
#include "IARPCache.h"
#include "ARP.h"
#include "IRoutingTable.h"
#include "RoutingTableAccess.h"
#include "AODVRouteData.h"
#include "ILifecycle.h"
#include "NodeOperations.h"
#include "NodeStatus.h"
#include "IARPCache.h"
#include "ARP.h"
/**
 * Class controls incoming and outgoing traffic.
 */
class WLanPacketCapsulation: public cSimpleModule, public INotifiable {

public:

    typedef std::pair<IPv4Address, MACAddress> RouteData;
    typedef std::list<RouteData> Route;
private:
    cGate *upperLayerIn;
    IInterfaceTable *interfaceTable;
    cModule *host;
    IARPCache *arpCache;
    IRoutingTable * routingTable;
    NotificationBoard *nb;
    IPv4Datagram *udpIpv4Datagram;

    unsigned int defaultUDPPort;
    simtime_t lastBroadcastTime;
    simtime_t delayTime;
    simtime_t rebootTime;
    int timeToLive;
    bool isOperational;
    bool hasPayload;


protected:
    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);
    virtual int numInitStages() const {
        return 5;
    }

    bool handleOperationStage(LifecycleOperation *operation, int stage,
            IDoneCallback *doneCallback);
    virtual void receiveChangeNotification(int category,
            const cObject *details);
private:
    virtual void clearState();

public:
    WLanPacketCapsulation();
    virtual ~WLanPacketCapsulation();
public:
    static std::set<Route*> routeQueue;
};

#endif
