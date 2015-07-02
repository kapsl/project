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

#ifndef __NETWORKSTRUCTURES_ROUTINGSERVERMANAGEMENT_H_
#define __NETWORKSTRUCTURES_ROUTINGSERVERMANAGEMENT_H_

#include <omnetpp.h>
#include "AODVRouting.h"
#include "IPv4Address.h"
#include "IInterfaceTable.h"
#include "IRoutingTable.h"
#include "INetfilter.h"
#include "RoutingTableAccess.h"
#include "InterfaceTableAccess.h"
#include "cgate.h"
#include "IPv4ControlInfo.h"
#include "RoutingServerControlData_m.h"
#include "AODVControlPackets_m.h"
#include "IPv4ControlInfo_m.h"
#include "ILifecycle.h"
#include "LifecycleOperation.h"
#include "NodeOperations.h"
#include "MACAddress.h"
#include "NeighborTopologyData.h"
#include "IPv4InterfaceData.h"
#include "InterfaceEntry.h"
#include "WLanPacketCapsulation.h"
#include "MobilityAccess.h"
#include "IMobility.h"

/**
 * This should be the class, that handles a device
 */
class RoutingServerManagement: public cSimpleModule, public ILifecycle {
protected:
    // environment
    cModule *host;
    IRoutingTable *routingTable;
    IInterfaceTable *interfaceTable;
    INetfilter *networkProtocol;
//    NotificationBoard *nb;
    cGate *networkLayerIn;
    cGate *AODVRoutingIn;
    NeighborTopologyData *topologyUpdate;
    HostCharacteristic *srcNode;
    IPv4Address umtsAddress;
    IMobility *mobility;

    bool isRegistrated;
    bool useHelloMessages;

    int defaultUDPPort;
    int timeToLive;

    double helloInterval;
    int allowedHelloLoss;

    unsigned int maxRoutesInCache;
    simtime_t delayTimeServerRegistration;
    simtime_t delayTimeTopologyUpdate;
    simtime_t lastBroadcastTime;
    simtime_t rebootTime;
    simtime_t serverRegRetryInterval;
    simtime_t myRouteTimeout;
    simtime_t serverUpdateInteval;
    bool isOperational;

    cPar *periodicJitter;

    cMessage *checkServerRegistration;
    cMessage *networkTopologyUpdate;
    cMessage *helloMsgTimer;

    /*
     * evtl more information
     */
    struct ServerInformation {
        IPv4Address serverAddress;
    };

    ServerInformation serverInformation;
    HostCharacteristic *ownCharacteristic;

    /*
     * Simulation Values
     */
    int rreqCount;
    int rerrCount;
    int rtCount;
    int ntCount;
    cStdDev numRT;
    cStdDev numNT;
    int numberOfRREP;
    int numberOfRREQSent;
    cOutVector delayOfRREQ;

    /**
     * Nr of given up packages in mac layer
     */
    int congestionState;

private:
    virtual void finish();

    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);
    virtual int numInitStages() const {
        return 5;
    }
    virtual void sendNeighborUpdateIfNeeded();
    virtual NeighborUpdateMessage *createNeighborUpdateMessage();
    virtual void handleRegistrationRequest();
    virtual RegistrationRequest* createRegistrationRequest();
    virtual void handleRegistrationConfirmation(
            RegistrationConfirmation *packet, IPv4Address& address);
    virtual NetworkTopologyUpdate* createNetworkTopologyUpdate();

    virtual void handleHelloMessage(NeighborUpdateMessage* packet,
            IPv4Address& srcAddress);
    virtual void handleTopologyUpdateTable();
    virtual void sendRoutingServerPacket(AODVControlPacket *packet,
            const IPv4Address& destAddr, unsigned int timeToLive, double delay);
    virtual void sendAODVPacket(AODVControlPacket *packet,
            const IPv4Address& destAddr, unsigned int timeToLive, double delay);
    virtual void sendLocalPacket(AODVControlPacket *packet,
            const IPv4Address& destAddr, unsigned int timeToLive, double delay,
            const IPv4Address& srcAddress);
    virtual void createRoute(const IPv4Address& destAddr,
            const IPv4Address& nextHop, unsigned int hopCount,
            bool hasValidDestNum, unsigned int destSeqNum, bool isActive,
            simtime_t lifeTime, bool isUMTS);
    virtual void handleRouteResponse(RouteResponse *routeResponse);
    virtual void handleRouteRequest(AODVRREQ* rreqq);
    virtual void handleRoutError(AODVRERR *rerr, IPv4Address &srcAddress);

    virtual double adaptSendingInterval(double speed, double minInterval, double maxInterval);

    /*
     * LifeCycle
     */
    virtual bool handleOperationStage(LifecycleOperation *operation, int stage,
            IDoneCallback *doneCallback);
    AODVRREP* createRREP(const IPv4Address& destAddress,
            simtime_t creationTime);

private:
    virtual void clearState();
    virtual void maintainRouteCache();

public:
    RoutingServerManagement();
    virtual ~RoutingServerManagement();
    virtual void congestionDetected(unsigned int givenUpSinceLast);
};

#endif
