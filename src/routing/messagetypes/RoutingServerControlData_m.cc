//
// Generated file, do not edit! Created by nedtool 4.6 from src/routing/messagetypes/RoutingServerControlData.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "RoutingServerControlData_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(RoutingServerControlData);

RoutingServerControlData::RoutingServerControlData(const char *name, int kind) : ::cPacket(name,kind)
{
    this->packetType_var = 0;
}

RoutingServerControlData::RoutingServerControlData(const RoutingServerControlData& other) : ::cPacket(other)
{
    copy(other);
}

RoutingServerControlData::~RoutingServerControlData()
{
}

RoutingServerControlData& RoutingServerControlData::operator=(const RoutingServerControlData& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void RoutingServerControlData::copy(const RoutingServerControlData& other)
{
    this->packetType_var = other.packetType_var;
}

void RoutingServerControlData::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->packetType_var);
}

void RoutingServerControlData::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->packetType_var);
}

unsigned int RoutingServerControlData::getPacketType() const
{
    return packetType_var;
}

void RoutingServerControlData::setPacketType(unsigned int packetType)
{
    this->packetType_var = packetType;
}

class RoutingServerControlDataDescriptor : public cClassDescriptor
{
  public:
    RoutingServerControlDataDescriptor();
    virtual ~RoutingServerControlDataDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(RoutingServerControlDataDescriptor);

RoutingServerControlDataDescriptor::RoutingServerControlDataDescriptor() : cClassDescriptor("RoutingServerControlData", "cPacket")
{
}

RoutingServerControlDataDescriptor::~RoutingServerControlDataDescriptor()
{
}

bool RoutingServerControlDataDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RoutingServerControlData *>(obj)!=NULL;
}

const char *RoutingServerControlDataDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RoutingServerControlDataDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int RoutingServerControlDataDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *RoutingServerControlDataDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "packetType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int RoutingServerControlDataDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RoutingServerControlDataDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *RoutingServerControlDataDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int RoutingServerControlDataDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RoutingServerControlData *pp = (RoutingServerControlData *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RoutingServerControlDataDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RoutingServerControlData *pp = (RoutingServerControlData *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        default: return "";
    }
}

bool RoutingServerControlDataDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RoutingServerControlData *pp = (RoutingServerControlData *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *RoutingServerControlDataDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *RoutingServerControlDataDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RoutingServerControlData *pp = (RoutingServerControlData *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("RSMessageTypes");
    if (!e) enums.getInstance()->add(e = new cEnum("RSMessageTypes"));
    e->insert(REGISTRATIONCONFIRMATIONMSG, "REGISTRATIONCONFIRMATIONMSG");
    e->insert(NETWORKTOPOLOGYUPDATEMSG, "NETWORKTOPOLOGYUPDATEMSG");
    e->insert(REGISTRATIONREQUESTMSG, "REGISTRATIONREQUESTMSG");
    e->insert(ROUTERESPONSEMSG, "ROUTERESPONSEMSG");
    e->insert(HELLOMESSAGE, "HELLOMESSAGE");
    e->insert(PAYLOADMSG, "PAYLOADMSG");
    e->insert(NEIGHBORUPDATEMESSAGE, "NEIGHBORUPDATEMESSAGE");
);

Register_Class(RegistrationConfirmation);

RegistrationConfirmation::RegistrationConfirmation(const char *name) : ::AODVControlPacket(name)
{
    this->packetType_var = REGISTRATIONCONFIRMATIONMSG;
    this->lifeTime_var = 0;
    this->hopCount_var = 0;
}

RegistrationConfirmation::RegistrationConfirmation(const RegistrationConfirmation& other) : ::AODVControlPacket(other)
{
    copy(other);
}

RegistrationConfirmation::~RegistrationConfirmation()
{
}

RegistrationConfirmation& RegistrationConfirmation::operator=(const RegistrationConfirmation& other)
{
    if (this==&other) return *this;
    ::AODVControlPacket::operator=(other);
    copy(other);
    return *this;
}

void RegistrationConfirmation::copy(const RegistrationConfirmation& other)
{
    this->packetType_var = other.packetType_var;
    this->lifeTime_var = other.lifeTime_var;
    this->hopCount_var = other.hopCount_var;
}

void RegistrationConfirmation::parsimPack(cCommBuffer *b)
{
    ::AODVControlPacket::parsimPack(b);
    doPacking(b,this->packetType_var);
    doPacking(b,this->lifeTime_var);
    doPacking(b,this->hopCount_var);
}

void RegistrationConfirmation::parsimUnpack(cCommBuffer *b)
{
    ::AODVControlPacket::parsimUnpack(b);
    doUnpacking(b,this->packetType_var);
    doUnpacking(b,this->lifeTime_var);
    doUnpacking(b,this->hopCount_var);
}

unsigned int RegistrationConfirmation::getPacketType() const
{
    return packetType_var;
}

void RegistrationConfirmation::setPacketType(unsigned int packetType)
{
    this->packetType_var = packetType;
}

simtime_t RegistrationConfirmation::getLifeTime() const
{
    return lifeTime_var;
}

void RegistrationConfirmation::setLifeTime(simtime_t lifeTime)
{
    this->lifeTime_var = lifeTime;
}

unsigned int RegistrationConfirmation::getHopCount() const
{
    return hopCount_var;
}

void RegistrationConfirmation::setHopCount(unsigned int hopCount)
{
    this->hopCount_var = hopCount;
}

class RegistrationConfirmationDescriptor : public cClassDescriptor
{
  public:
    RegistrationConfirmationDescriptor();
    virtual ~RegistrationConfirmationDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(RegistrationConfirmationDescriptor);

RegistrationConfirmationDescriptor::RegistrationConfirmationDescriptor() : cClassDescriptor("RegistrationConfirmation", "AODVControlPacket")
{
}

RegistrationConfirmationDescriptor::~RegistrationConfirmationDescriptor()
{
}

bool RegistrationConfirmationDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RegistrationConfirmation *>(obj)!=NULL;
}

const char *RegistrationConfirmationDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RegistrationConfirmationDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int RegistrationConfirmationDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *RegistrationConfirmationDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "packetType",
        "lifeTime",
        "hopCount",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int RegistrationConfirmationDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifeTime")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RegistrationConfirmationDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "simtime_t",
        "unsigned int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *RegistrationConfirmationDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int RegistrationConfirmationDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RegistrationConfirmation *pp = (RegistrationConfirmation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RegistrationConfirmationDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RegistrationConfirmation *pp = (RegistrationConfirmation *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return double2string(pp->getLifeTime());
        case 2: return ulong2string(pp->getHopCount());
        default: return "";
    }
}

bool RegistrationConfirmationDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RegistrationConfirmation *pp = (RegistrationConfirmation *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setLifeTime(string2double(value)); return true;
        case 2: pp->setHopCount(string2ulong(value)); return true;
        default: return false;
    }
}

const char *RegistrationConfirmationDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *RegistrationConfirmationDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RegistrationConfirmation *pp = (RegistrationConfirmation *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(NetworkTopologyUpdate);

NetworkTopologyUpdate::NetworkTopologyUpdate(const char *name) : ::AODVControlPacket(name)
{
    this->packetType_var = REGISTRATIONCONFIRMATIONMSG;
    this->lifeTime_var = 0;
    this->hopCount_var = 0;
}

NetworkTopologyUpdate::NetworkTopologyUpdate(const NetworkTopologyUpdate& other) : ::AODVControlPacket(other)
{
    copy(other);
}

NetworkTopologyUpdate::~NetworkTopologyUpdate()
{
}

NetworkTopologyUpdate& NetworkTopologyUpdate::operator=(const NetworkTopologyUpdate& other)
{
    if (this==&other) return *this;
    ::AODVControlPacket::operator=(other);
    copy(other);
    return *this;
}

void NetworkTopologyUpdate::copy(const NetworkTopologyUpdate& other)
{
    this->packetType_var = other.packetType_var;
    this->lifeTime_var = other.lifeTime_var;
    this->hopCount_var = other.hopCount_var;
    this->neighbors_var = other.neighbors_var;
    this->hostCharacteristic_var = other.hostCharacteristic_var;
}

void NetworkTopologyUpdate::parsimPack(cCommBuffer *b)
{
    ::AODVControlPacket::parsimPack(b);
    doPacking(b,this->packetType_var);
    doPacking(b,this->lifeTime_var);
    doPacking(b,this->hopCount_var);
    doPacking(b,this->neighbors_var);
    doPacking(b,this->hostCharacteristic_var);
}

void NetworkTopologyUpdate::parsimUnpack(cCommBuffer *b)
{
    ::AODVControlPacket::parsimUnpack(b);
    doUnpacking(b,this->packetType_var);
    doUnpacking(b,this->lifeTime_var);
    doUnpacking(b,this->hopCount_var);
    doUnpacking(b,this->neighbors_var);
    doUnpacking(b,this->hostCharacteristic_var);
}

unsigned int NetworkTopologyUpdate::getPacketType() const
{
    return packetType_var;
}

void NetworkTopologyUpdate::setPacketType(unsigned int packetType)
{
    this->packetType_var = packetType;
}

simtime_t NetworkTopologyUpdate::getLifeTime() const
{
    return lifeTime_var;
}

void NetworkTopologyUpdate::setLifeTime(simtime_t lifeTime)
{
    this->lifeTime_var = lifeTime;
}

unsigned int NetworkTopologyUpdate::getHopCount() const
{
    return hopCount_var;
}

void NetworkTopologyUpdate::setHopCount(unsigned int hopCount)
{
    this->hopCount_var = hopCount;
}

Neighbors& NetworkTopologyUpdate::getNeighbors()
{
    return neighbors_var;
}

void NetworkTopologyUpdate::setNeighbors(const Neighbors& neighbors)
{
    this->neighbors_var = neighbors;
}

HostCharacteristic& NetworkTopologyUpdate::getHostCharacteristic()
{
    return hostCharacteristic_var;
}

void NetworkTopologyUpdate::setHostCharacteristic(const HostCharacteristic& hostCharacteristic)
{
    this->hostCharacteristic_var = hostCharacteristic;
}

class NetworkTopologyUpdateDescriptor : public cClassDescriptor
{
  public:
    NetworkTopologyUpdateDescriptor();
    virtual ~NetworkTopologyUpdateDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NetworkTopologyUpdateDescriptor);

NetworkTopologyUpdateDescriptor::NetworkTopologyUpdateDescriptor() : cClassDescriptor("NetworkTopologyUpdate", "AODVControlPacket")
{
}

NetworkTopologyUpdateDescriptor::~NetworkTopologyUpdateDescriptor()
{
}

bool NetworkTopologyUpdateDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NetworkTopologyUpdate *>(obj)!=NULL;
}

const char *NetworkTopologyUpdateDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NetworkTopologyUpdateDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int NetworkTopologyUpdateDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *NetworkTopologyUpdateDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "packetType",
        "lifeTime",
        "hopCount",
        "neighbors",
        "hostCharacteristic",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int NetworkTopologyUpdateDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifeTime")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighbors")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "hostCharacteristic")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *NetworkTopologyUpdateDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "simtime_t",
        "unsigned int",
        "Neighbors",
        "HostCharacteristic",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *NetworkTopologyUpdateDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NetworkTopologyUpdateDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NetworkTopologyUpdate *pp = (NetworkTopologyUpdate *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string NetworkTopologyUpdateDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    NetworkTopologyUpdate *pp = (NetworkTopologyUpdate *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return double2string(pp->getLifeTime());
        case 2: return ulong2string(pp->getHopCount());
        case 3: {std::stringstream out; out << pp->getNeighbors(); return out.str();}
        case 4: {std::stringstream out; out << pp->getHostCharacteristic(); return out.str();}
        default: return "";
    }
}

bool NetworkTopologyUpdateDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NetworkTopologyUpdate *pp = (NetworkTopologyUpdate *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setLifeTime(string2double(value)); return true;
        case 2: pp->setHopCount(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NetworkTopologyUpdateDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 3: return opp_typename(typeid(Neighbors));
        case 4: return opp_typename(typeid(HostCharacteristic));
        default: return NULL;
    };
}

void *NetworkTopologyUpdateDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NetworkTopologyUpdate *pp = (NetworkTopologyUpdate *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getNeighbors()); break;
        case 4: return (void *)(&pp->getHostCharacteristic()); break;
        default: return NULL;
    }
}

Register_Class(RegistrationRequest);

RegistrationRequest::RegistrationRequest(const char *name) : ::AODVControlPacket(name)
{
    this->packetType_var = REGISTRATIONREQUESTMSG;
    this->lifeTime_var = 0;
    this->hopCount_var = 0;
}

RegistrationRequest::RegistrationRequest(const RegistrationRequest& other) : ::AODVControlPacket(other)
{
    copy(other);
}

RegistrationRequest::~RegistrationRequest()
{
}

RegistrationRequest& RegistrationRequest::operator=(const RegistrationRequest& other)
{
    if (this==&other) return *this;
    ::AODVControlPacket::operator=(other);
    copy(other);
    return *this;
}

void RegistrationRequest::copy(const RegistrationRequest& other)
{
    this->packetType_var = other.packetType_var;
    this->lifeTime_var = other.lifeTime_var;
    this->hopCount_var = other.hopCount_var;
}

void RegistrationRequest::parsimPack(cCommBuffer *b)
{
    ::AODVControlPacket::parsimPack(b);
    doPacking(b,this->packetType_var);
    doPacking(b,this->lifeTime_var);
    doPacking(b,this->hopCount_var);
}

void RegistrationRequest::parsimUnpack(cCommBuffer *b)
{
    ::AODVControlPacket::parsimUnpack(b);
    doUnpacking(b,this->packetType_var);
    doUnpacking(b,this->lifeTime_var);
    doUnpacking(b,this->hopCount_var);
}

unsigned int RegistrationRequest::getPacketType() const
{
    return packetType_var;
}

void RegistrationRequest::setPacketType(unsigned int packetType)
{
    this->packetType_var = packetType;
}

simtime_t RegistrationRequest::getLifeTime() const
{
    return lifeTime_var;
}

void RegistrationRequest::setLifeTime(simtime_t lifeTime)
{
    this->lifeTime_var = lifeTime;
}

unsigned int RegistrationRequest::getHopCount() const
{
    return hopCount_var;
}

void RegistrationRequest::setHopCount(unsigned int hopCount)
{
    this->hopCount_var = hopCount;
}

class RegistrationRequestDescriptor : public cClassDescriptor
{
  public:
    RegistrationRequestDescriptor();
    virtual ~RegistrationRequestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(RegistrationRequestDescriptor);

RegistrationRequestDescriptor::RegistrationRequestDescriptor() : cClassDescriptor("RegistrationRequest", "AODVControlPacket")
{
}

RegistrationRequestDescriptor::~RegistrationRequestDescriptor()
{
}

bool RegistrationRequestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RegistrationRequest *>(obj)!=NULL;
}

const char *RegistrationRequestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RegistrationRequestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int RegistrationRequestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *RegistrationRequestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "packetType",
        "lifeTime",
        "hopCount",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int RegistrationRequestDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifeTime")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RegistrationRequestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "simtime_t",
        "unsigned int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *RegistrationRequestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int RegistrationRequestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RegistrationRequest *pp = (RegistrationRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RegistrationRequestDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RegistrationRequest *pp = (RegistrationRequest *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return double2string(pp->getLifeTime());
        case 2: return ulong2string(pp->getHopCount());
        default: return "";
    }
}

bool RegistrationRequestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RegistrationRequest *pp = (RegistrationRequest *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setLifeTime(string2double(value)); return true;
        case 2: pp->setHopCount(string2ulong(value)); return true;
        default: return false;
    }
}

const char *RegistrationRequestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *RegistrationRequestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RegistrationRequest *pp = (RegistrationRequest *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(RouteResponse);

RouteResponse::RouteResponse(const char *name) : ::AODVControlPacket(name)
{
    this->packetType_var = ROUTERESPONSEMSG;
    this->lifeTime_var = 0;
    this->creationTimeRREQ_var = 0;
    this->hopCount_var = 0;
    this->isHostWhoRequested_var = 0;
}

RouteResponse::RouteResponse(const RouteResponse& other) : ::AODVControlPacket(other)
{
    copy(other);
}

RouteResponse::~RouteResponse()
{
}

RouteResponse& RouteResponse::operator=(const RouteResponse& other)
{
    if (this==&other) return *this;
    ::AODVControlPacket::operator=(other);
    copy(other);
    return *this;
}

void RouteResponse::copy(const RouteResponse& other)
{
    this->packetType_var = other.packetType_var;
    this->lifeTime_var = other.lifeTime_var;
    this->creationTimeRREQ_var = other.creationTimeRREQ_var;
    this->hopCount_var = other.hopCount_var;
    this->isHostWhoRequested_var = other.isHostWhoRequested_var;
    this->route_var = other.route_var;
}

void RouteResponse::parsimPack(cCommBuffer *b)
{
    ::AODVControlPacket::parsimPack(b);
    doPacking(b,this->packetType_var);
    doPacking(b,this->lifeTime_var);
    doPacking(b,this->creationTimeRREQ_var);
    doPacking(b,this->hopCount_var);
    doPacking(b,this->isHostWhoRequested_var);
    doPacking(b,this->route_var);
}

void RouteResponse::parsimUnpack(cCommBuffer *b)
{
    ::AODVControlPacket::parsimUnpack(b);
    doUnpacking(b,this->packetType_var);
    doUnpacking(b,this->lifeTime_var);
    doUnpacking(b,this->creationTimeRREQ_var);
    doUnpacking(b,this->hopCount_var);
    doUnpacking(b,this->isHostWhoRequested_var);
    doUnpacking(b,this->route_var);
}

unsigned int RouteResponse::getPacketType() const
{
    return packetType_var;
}

void RouteResponse::setPacketType(unsigned int packetType)
{
    this->packetType_var = packetType;
}

simtime_t RouteResponse::getLifeTime() const
{
    return lifeTime_var;
}

void RouteResponse::setLifeTime(simtime_t lifeTime)
{
    this->lifeTime_var = lifeTime;
}

simtime_t RouteResponse::getCreationTimeRREQ() const
{
    return creationTimeRREQ_var;
}

void RouteResponse::setCreationTimeRREQ(simtime_t creationTimeRREQ)
{
    this->creationTimeRREQ_var = creationTimeRREQ;
}

unsigned int RouteResponse::getHopCount() const
{
    return hopCount_var;
}

void RouteResponse::setHopCount(unsigned int hopCount)
{
    this->hopCount_var = hopCount;
}

bool RouteResponse::getIsHostWhoRequested() const
{
    return isHostWhoRequested_var;
}

void RouteResponse::setIsHostWhoRequested(bool isHostWhoRequested)
{
    this->isHostWhoRequested_var = isHostWhoRequested;
}

Route& RouteResponse::getRoute()
{
    return route_var;
}

void RouteResponse::setRoute(const Route& route)
{
    this->route_var = route;
}

class RouteResponseDescriptor : public cClassDescriptor
{
  public:
    RouteResponseDescriptor();
    virtual ~RouteResponseDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(RouteResponseDescriptor);

RouteResponseDescriptor::RouteResponseDescriptor() : cClassDescriptor("RouteResponse", "AODVControlPacket")
{
}

RouteResponseDescriptor::~RouteResponseDescriptor()
{
}

bool RouteResponseDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RouteResponse *>(obj)!=NULL;
}

const char *RouteResponseDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RouteResponseDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int RouteResponseDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *RouteResponseDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "packetType",
        "lifeTime",
        "creationTimeRREQ",
        "hopCount",
        "isHostWhoRequested",
        "route",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int RouteResponseDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifeTime")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "creationTimeRREQ")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "isHostWhoRequested")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "route")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RouteResponseDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "simtime_t",
        "simtime_t",
        "unsigned int",
        "bool",
        "Route",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *RouteResponseDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int RouteResponseDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RouteResponse *pp = (RouteResponse *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RouteResponseDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RouteResponse *pp = (RouteResponse *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return double2string(pp->getLifeTime());
        case 2: return double2string(pp->getCreationTimeRREQ());
        case 3: return ulong2string(pp->getHopCount());
        case 4: return bool2string(pp->getIsHostWhoRequested());
        case 5: {std::stringstream out; out << pp->getRoute(); return out.str();}
        default: return "";
    }
}

bool RouteResponseDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RouteResponse *pp = (RouteResponse *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setLifeTime(string2double(value)); return true;
        case 2: pp->setCreationTimeRREQ(string2double(value)); return true;
        case 3: pp->setHopCount(string2ulong(value)); return true;
        case 4: pp->setIsHostWhoRequested(string2bool(value)); return true;
        default: return false;
    }
}

const char *RouteResponseDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 5: return opp_typename(typeid(Route));
        default: return NULL;
    };
}

void *RouteResponseDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RouteResponse *pp = (RouteResponse *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getRoute()); break;
        default: return NULL;
    }
}

Register_Class(PayLoadData);

PayLoadData::PayLoadData(const char *name) : ::AODVControlPacket(name)
{
    this->packetType_var = PAYLOADMSG;
}

PayLoadData::PayLoadData(const PayLoadData& other) : ::AODVControlPacket(other)
{
    copy(other);
}

PayLoadData::~PayLoadData()
{
}

PayLoadData& PayLoadData::operator=(const PayLoadData& other)
{
    if (this==&other) return *this;
    ::AODVControlPacket::operator=(other);
    copy(other);
    return *this;
}

void PayLoadData::copy(const PayLoadData& other)
{
    this->packetType_var = other.packetType_var;
    this->route_var = other.route_var;
}

void PayLoadData::parsimPack(cCommBuffer *b)
{
    ::AODVControlPacket::parsimPack(b);
    doPacking(b,this->packetType_var);
    doPacking(b,this->route_var);
}

void PayLoadData::parsimUnpack(cCommBuffer *b)
{
    ::AODVControlPacket::parsimUnpack(b);
    doUnpacking(b,this->packetType_var);
    doUnpacking(b,this->route_var);
}

unsigned int PayLoadData::getPacketType() const
{
    return packetType_var;
}

void PayLoadData::setPacketType(unsigned int packetType)
{
    this->packetType_var = packetType;
}

Route& PayLoadData::getRoute()
{
    return route_var;
}

void PayLoadData::setRoute(const Route& route)
{
    this->route_var = route;
}

class PayLoadDataDescriptor : public cClassDescriptor
{
  public:
    PayLoadDataDescriptor();
    virtual ~PayLoadDataDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PayLoadDataDescriptor);

PayLoadDataDescriptor::PayLoadDataDescriptor() : cClassDescriptor("PayLoadData", "AODVControlPacket")
{
}

PayLoadDataDescriptor::~PayLoadDataDescriptor()
{
}

bool PayLoadDataDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PayLoadData *>(obj)!=NULL;
}

const char *PayLoadDataDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PayLoadDataDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int PayLoadDataDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *PayLoadDataDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "packetType",
        "route",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int PayLoadDataDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "route")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PayLoadDataDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "Route",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *PayLoadDataDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PayLoadDataDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PayLoadData *pp = (PayLoadData *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PayLoadDataDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PayLoadData *pp = (PayLoadData *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: {std::stringstream out; out << pp->getRoute(); return out.str();}
        default: return "";
    }
}

bool PayLoadDataDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PayLoadData *pp = (PayLoadData *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *PayLoadDataDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1: return opp_typename(typeid(Route));
        default: return NULL;
    };
}

void *PayLoadDataDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PayLoadData *pp = (PayLoadData *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getRoute()); break;
        default: return NULL;
    }
}

Register_Class(NeighborUpdateMessage);

NeighborUpdateMessage::NeighborUpdateMessage(const char *name) : ::AODVControlPacket(name)
{
    this->packetType_var = NEIGHBORUPDATEMESSAGE;
}

NeighborUpdateMessage::NeighborUpdateMessage(const NeighborUpdateMessage& other) : ::AODVControlPacket(other)
{
    copy(other);
}

NeighborUpdateMessage::~NeighborUpdateMessage()
{
}

NeighborUpdateMessage& NeighborUpdateMessage::operator=(const NeighborUpdateMessage& other)
{
    if (this==&other) return *this;
    ::AODVControlPacket::operator=(other);
    copy(other);
    return *this;
}

void NeighborUpdateMessage::copy(const NeighborUpdateMessage& other)
{
    this->packetType_var = other.packetType_var;
    this->position_var = other.position_var;
    this->macAddress_var = other.macAddress_var;
}

void NeighborUpdateMessage::parsimPack(cCommBuffer *b)
{
    ::AODVControlPacket::parsimPack(b);
    doPacking(b,this->packetType_var);
    doPacking(b,this->position_var);
    doPacking(b,this->macAddress_var);
}

void NeighborUpdateMessage::parsimUnpack(cCommBuffer *b)
{
    ::AODVControlPacket::parsimUnpack(b);
    doUnpacking(b,this->packetType_var);
    doUnpacking(b,this->position_var);
    doUnpacking(b,this->macAddress_var);
}

unsigned int NeighborUpdateMessage::getPacketType() const
{
    return packetType_var;
}

void NeighborUpdateMessage::setPacketType(unsigned int packetType)
{
    this->packetType_var = packetType;
}

Coord& NeighborUpdateMessage::getPosition()
{
    return position_var;
}

void NeighborUpdateMessage::setPosition(const Coord& position)
{
    this->position_var = position;
}

MACAddress& NeighborUpdateMessage::getMacAddress()
{
    return macAddress_var;
}

void NeighborUpdateMessage::setMacAddress(const MACAddress& macAddress)
{
    this->macAddress_var = macAddress;
}

class NeighborUpdateMessageDescriptor : public cClassDescriptor
{
  public:
    NeighborUpdateMessageDescriptor();
    virtual ~NeighborUpdateMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NeighborUpdateMessageDescriptor);

NeighborUpdateMessageDescriptor::NeighborUpdateMessageDescriptor() : cClassDescriptor("NeighborUpdateMessage", "AODVControlPacket")
{
}

NeighborUpdateMessageDescriptor::~NeighborUpdateMessageDescriptor()
{
}

bool NeighborUpdateMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NeighborUpdateMessage *>(obj)!=NULL;
}

const char *NeighborUpdateMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NeighborUpdateMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int NeighborUpdateMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *NeighborUpdateMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "packetType",
        "position",
        "macAddress",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int NeighborUpdateMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "position")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "macAddress")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *NeighborUpdateMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "Coord",
        "MACAddress",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *NeighborUpdateMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NeighborUpdateMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NeighborUpdateMessage *pp = (NeighborUpdateMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string NeighborUpdateMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    NeighborUpdateMessage *pp = (NeighborUpdateMessage *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: {std::stringstream out; out << pp->getPosition(); return out.str();}
        case 2: {std::stringstream out; out << pp->getMacAddress(); return out.str();}
        default: return "";
    }
}

bool NeighborUpdateMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NeighborUpdateMessage *pp = (NeighborUpdateMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NeighborUpdateMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1: return opp_typename(typeid(Coord));
        case 2: return opp_typename(typeid(MACAddress));
        default: return NULL;
    };
}

void *NeighborUpdateMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NeighborUpdateMessage *pp = (NeighborUpdateMessage *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getPosition()); break;
        case 2: return (void *)(&pp->getMacAddress()); break;
        default: return NULL;
    }
}


