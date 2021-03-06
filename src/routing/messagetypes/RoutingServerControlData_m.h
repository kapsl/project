//
// Generated file, do not edit! Created by nedtool 4.6 from src/routing/messagetypes/RoutingServerControlData.msg.
//

#ifndef _ROUTINGSERVERCONTROLDATA_M_H_
#define _ROUTINGSERVERCONTROLDATA_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "IPv4Address.h"
#include "simtime_t.h"
#include "HostCharacteristic.h"
#include "AODVControlPackets_m.h"
#include "NetworkTopologyGraph.h"
#include "UDPPacket.h"
#include "Coord.h"
#include "MACAddress.h"
#include <vector>
typedef std::list<IPv4Address> IPRoute;
typedef std::list<MACAddress> MACRoute;
typedef std::vector<HostCharacteristic> Neighbors; 
typedef std::list< std::pair<IPv4Address,MACAddress> > Route;
// }}

/**
 * Class generated from <tt>src/routing/messagetypes/RoutingServerControlData.msg:49</tt> by nedtool.
 * <pre>
 * packet RoutingServerControlData
 * {
 *     unsigned int packetType;
 * }
 * </pre>
 */
class RoutingServerControlData : public ::cPacket
{
  protected:
    unsigned int packetType_var;

  private:
    void copy(const RoutingServerControlData& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RoutingServerControlData&);

  public:
    RoutingServerControlData(const char *name=NULL, int kind=0);
    RoutingServerControlData(const RoutingServerControlData& other);
    virtual ~RoutingServerControlData();
    RoutingServerControlData& operator=(const RoutingServerControlData& other);
    virtual RoutingServerControlData *dup() const {return new RoutingServerControlData(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
};

inline void doPacking(cCommBuffer *b, RoutingServerControlData& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, RoutingServerControlData& obj) {obj.parsimUnpack(b);}

/**
 * Enum generated from <tt>src/routing/messagetypes/RoutingServerControlData.msg:53</tt> by nedtool.
 * <pre>
 * enum RSMessageTypes
 * {
 * 
 *     REGISTRATIONCONFIRMATIONMSG = 5;
 *     NETWORKTOPOLOGYUPDATEMSG = 6;
 *     REGISTRATIONREQUESTMSG = 7;
 *     ROUTERESPONSEMSG = 8;
 *     HELLOMESSAGE = 9;
 *     PAYLOADMSG = 10;
 *     NEIGHBORUPDATEMESSAGE = 11;
 * }
 * </pre>
 */
enum RSMessageTypes {
    REGISTRATIONCONFIRMATIONMSG = 5,
    NETWORKTOPOLOGYUPDATEMSG = 6,
    REGISTRATIONREQUESTMSG = 7,
    ROUTERESPONSEMSG = 8,
    HELLOMESSAGE = 9,
    PAYLOADMSG = 10,
    NEIGHBORUPDATEMESSAGE = 11
};

/**
 * Class generated from <tt>src/routing/messagetypes/RoutingServerControlData.msg:63</tt> by nedtool.
 * <pre>
 * class RegistrationConfirmation extends AODVControlPacket
 * {
 *     unsigned int packetType = REGISTRATIONCONFIRMATIONMSG;
 *     simtime_t lifeTime;
 *     unsigned int hopCount;
 * 
 * }
 * </pre>
 */
class RegistrationConfirmation : public ::AODVControlPacket
{
  protected:
    unsigned int packetType_var;
    simtime_t lifeTime_var;
    unsigned int hopCount_var;

  private:
    void copy(const RegistrationConfirmation& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RegistrationConfirmation&);

  public:
    RegistrationConfirmation(const char *name=NULL);
    RegistrationConfirmation(const RegistrationConfirmation& other);
    virtual ~RegistrationConfirmation();
    RegistrationConfirmation& operator=(const RegistrationConfirmation& other);
    virtual RegistrationConfirmation *dup() const {return new RegistrationConfirmation(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
    virtual simtime_t getLifeTime() const;
    virtual void setLifeTime(simtime_t lifeTime);
    virtual unsigned int getHopCount() const;
    virtual void setHopCount(unsigned int hopCount);
};

inline void doPacking(cCommBuffer *b, RegistrationConfirmation& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, RegistrationConfirmation& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>src/routing/messagetypes/RoutingServerControlData.msg:70</tt> by nedtool.
 * <pre>
 * class NetworkTopologyUpdate extends AODVControlPacket
 * {
 *     unsigned int packetType = REGISTRATIONCONFIRMATIONMSG;
 *     simtime_t lifeTime;
 *     unsigned int hopCount;
 *     Neighbors neighbors;
 *     HostCharacteristic hostCharacteristic;
 * }
 * </pre>
 */
class NetworkTopologyUpdate : public ::AODVControlPacket
{
  protected:
    unsigned int packetType_var;
    simtime_t lifeTime_var;
    unsigned int hopCount_var;
    Neighbors neighbors_var;
    HostCharacteristic hostCharacteristic_var;

  private:
    void copy(const NetworkTopologyUpdate& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const NetworkTopologyUpdate&);

  public:
    NetworkTopologyUpdate(const char *name=NULL);
    NetworkTopologyUpdate(const NetworkTopologyUpdate& other);
    virtual ~NetworkTopologyUpdate();
    NetworkTopologyUpdate& operator=(const NetworkTopologyUpdate& other);
    virtual NetworkTopologyUpdate *dup() const {return new NetworkTopologyUpdate(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
    virtual simtime_t getLifeTime() const;
    virtual void setLifeTime(simtime_t lifeTime);
    virtual unsigned int getHopCount() const;
    virtual void setHopCount(unsigned int hopCount);
    virtual Neighbors& getNeighbors();
    virtual const Neighbors& getNeighbors() const {return const_cast<NetworkTopologyUpdate*>(this)->getNeighbors();}
    virtual void setNeighbors(const Neighbors& neighbors);
    virtual HostCharacteristic& getHostCharacteristic();
    virtual const HostCharacteristic& getHostCharacteristic() const {return const_cast<NetworkTopologyUpdate*>(this)->getHostCharacteristic();}
    virtual void setHostCharacteristic(const HostCharacteristic& hostCharacteristic);
};

inline void doPacking(cCommBuffer *b, NetworkTopologyUpdate& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, NetworkTopologyUpdate& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>src/routing/messagetypes/RoutingServerControlData.msg:78</tt> by nedtool.
 * <pre>
 * class RegistrationRequest extends AODVControlPacket
 * {
 *     unsigned int packetType = REGISTRATIONREQUESTMSG;
 *     simtime_t lifeTime;
 *     unsigned int hopCount;
 * }
 * </pre>
 */
class RegistrationRequest : public ::AODVControlPacket
{
  protected:
    unsigned int packetType_var;
    simtime_t lifeTime_var;
    unsigned int hopCount_var;

  private:
    void copy(const RegistrationRequest& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RegistrationRequest&);

  public:
    RegistrationRequest(const char *name=NULL);
    RegistrationRequest(const RegistrationRequest& other);
    virtual ~RegistrationRequest();
    RegistrationRequest& operator=(const RegistrationRequest& other);
    virtual RegistrationRequest *dup() const {return new RegistrationRequest(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
    virtual simtime_t getLifeTime() const;
    virtual void setLifeTime(simtime_t lifeTime);
    virtual unsigned int getHopCount() const;
    virtual void setHopCount(unsigned int hopCount);
};

inline void doPacking(cCommBuffer *b, RegistrationRequest& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, RegistrationRequest& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>src/routing/messagetypes/RoutingServerControlData.msg:84</tt> by nedtool.
 * <pre>
 * class RouteResponse extends AODVControlPacket
 * {
 *     unsigned int packetType = ROUTERESPONSEMSG;
 *     simtime_t lifeTime;
 *     simtime_t creationTimeRREQ;
 *     unsigned int hopCount;
 *     bool isHostWhoRequested;
 *     Route route;
 * }
 * </pre>
 */
class RouteResponse : public ::AODVControlPacket
{
  protected:
    unsigned int packetType_var;
    simtime_t lifeTime_var;
    simtime_t creationTimeRREQ_var;
    unsigned int hopCount_var;
    bool isHostWhoRequested_var;
    Route route_var;

  private:
    void copy(const RouteResponse& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RouteResponse&);

  public:
    RouteResponse(const char *name=NULL);
    RouteResponse(const RouteResponse& other);
    virtual ~RouteResponse();
    RouteResponse& operator=(const RouteResponse& other);
    virtual RouteResponse *dup() const {return new RouteResponse(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
    virtual simtime_t getLifeTime() const;
    virtual void setLifeTime(simtime_t lifeTime);
    virtual simtime_t getCreationTimeRREQ() const;
    virtual void setCreationTimeRREQ(simtime_t creationTimeRREQ);
    virtual unsigned int getHopCount() const;
    virtual void setHopCount(unsigned int hopCount);
    virtual bool getIsHostWhoRequested() const;
    virtual void setIsHostWhoRequested(bool isHostWhoRequested);
    virtual Route& getRoute();
    virtual const Route& getRoute() const {return const_cast<RouteResponse*>(this)->getRoute();}
    virtual void setRoute(const Route& route);
};

inline void doPacking(cCommBuffer *b, RouteResponse& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, RouteResponse& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>src/routing/messagetypes/RoutingServerControlData.msg:93</tt> by nedtool.
 * <pre>
 * class PayLoadData extends AODVControlPacket
 * {
 *     unsigned int packetType = PAYLOADMSG;
 *     Route route;
 * }
 * </pre>
 */
class PayLoadData : public ::AODVControlPacket
{
  protected:
    unsigned int packetType_var;
    Route route_var;

  private:
    void copy(const PayLoadData& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PayLoadData&);

  public:
    PayLoadData(const char *name=NULL);
    PayLoadData(const PayLoadData& other);
    virtual ~PayLoadData();
    PayLoadData& operator=(const PayLoadData& other);
    virtual PayLoadData *dup() const {return new PayLoadData(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
    virtual Route& getRoute();
    virtual const Route& getRoute() const {return const_cast<PayLoadData*>(this)->getRoute();}
    virtual void setRoute(const Route& route);
};

inline void doPacking(cCommBuffer *b, PayLoadData& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PayLoadData& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>src/routing/messagetypes/RoutingServerControlData.msg:99</tt> by nedtool.
 * <pre>
 * // Local HelloMessage between the UserEquipments
 * class NeighborUpdateMessage extends AODVControlPacket
 * {
 *     unsigned int packetType = NEIGHBORUPDATEMESSAGE;
 *     Coord position;
 *     MACAddress macAddress;
 * 
 * }
 * </pre>
 */
class NeighborUpdateMessage : public ::AODVControlPacket
{
  protected:
    unsigned int packetType_var;
    Coord position_var;
    MACAddress macAddress_var;

  private:
    void copy(const NeighborUpdateMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const NeighborUpdateMessage&);

  public:
    NeighborUpdateMessage(const char *name=NULL);
    NeighborUpdateMessage(const NeighborUpdateMessage& other);
    virtual ~NeighborUpdateMessage();
    NeighborUpdateMessage& operator=(const NeighborUpdateMessage& other);
    virtual NeighborUpdateMessage *dup() const {return new NeighborUpdateMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual unsigned int getPacketType() const;
    virtual void setPacketType(unsigned int packetType);
    virtual Coord& getPosition();
    virtual const Coord& getPosition() const {return const_cast<NeighborUpdateMessage*>(this)->getPosition();}
    virtual void setPosition(const Coord& position);
    virtual MACAddress& getMacAddress();
    virtual const MACAddress& getMacAddress() const {return const_cast<NeighborUpdateMessage*>(this)->getMacAddress();}
    virtual void setMacAddress(const MACAddress& macAddress);
};

inline void doPacking(cCommBuffer *b, NeighborUpdateMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, NeighborUpdateMessage& obj) {obj.parsimUnpack(b);}


#endif // ifndef _ROUTINGSERVERCONTROLDATA_M_H_

