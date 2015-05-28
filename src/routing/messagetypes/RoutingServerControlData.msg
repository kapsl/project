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






//
// This MSG-Class contains of all Message-Types generated for the D2DRS Algorithm
//
cplusplus {{
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
}}
class noncobject IPv4Address;
class noncobject HostCharacteristic;
class noncobject Route;
class noncobject PayLoadPacket;
class noncobject Neighbors;
class noncobject Coord;
class noncobject MACAddress;


packet AODVControlPacket;
packet RoutingServerControlData{
    unsigned int packetType;
}

enum RSMessageTypes {
    REGISTRATIONCONFIRMATIONMSG=5;
    NETWORKTOPOLOGYUPDATEMSG = 6;
   	REGISTRATIONREQUESTMSG = 7;
   	ROUTERESPONSEMSG = 8;
   	HELLOMESSAGE = 9;
   	PAYLOADMSG = 10;
   	NEIGHBORUPDATEMESSAGE = 11;
	}

class RegistrationConfirmation extends AODVControlPacket {
        unsigned int packetType = REGISTRATIONCONFIRMATIONMSG;
        simtime_t lifeTime;
    	unsigned int hopCount;
    	
	}

class NetworkTopologyUpdate extends AODVControlPacket{
      	unsigned int packetType = REGISTRATIONCONFIRMATIONMSG;
      	simtime_t lifeTime;
      	unsigned int hopCount;
		Neighbors neighbors;
		HostCharacteristic hostCharacteristic;
	}

class RegistrationRequest extends AODVControlPacket{
 		unsigned int packetType = REGISTRATIONREQUESTMSG;
    	simtime_t lifeTime;
    	unsigned int hopCount;
    }


class RouteResponse extends AODVControlPacket {
    unsigned int packetType= ROUTERESPONSEMSG;
      	simtime_t lifeTime;
      	simtime_t creationTimeRREQ;
      	unsigned int hopCount;
      	bool isHostWhoRequested;
    Route route;
    }

class PayLoadData extends AODVControlPacket {
      unsigned int packetType= PAYLOADMSG;
      Route route;
 }

// Local HelloMessage between the UserEquipments
class NeighborUpdateMessage extends AODVControlPacket {
    unsigned int packetType= NEIGHBORUPDATEMESSAGE;
    Coord position;
    MACAddress macAddress;
    
}
