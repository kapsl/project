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

#ifndef NETWORKTOPOLOGYUPDATE_H_
#define NETWORKTOPOLOGYUPDATE_H_

#include "HostCharacteristic.h"
#include "vector"
#include "AODVControlPackets_m.h"
#include "simtime_t.h"
#include "RoutingTable.h"
#include "Coord.h"
#include "MACAddress.h"

/**
 * I Think, this stores data about the neighbors of a host in the host
 */
class NeighborTopologyData: public cSimpleModule {

public:
    NeighborTopologyData();
    virtual ~NeighborTopologyData();

public:
    typedef std::vector<HostCharacteristic> Neighbors;
   Neighbors neighbors;

public:
    virtual void updateLinkedNeighbor(IPv4Address originatorAddr, MACAddress macAddress,
            Coord position,  simtime_t liveTime);
    virtual bool updateNeighborhoodTopology(int regRetries, int currentSimTime,
            double helloIntervall);
    virtual Neighbors getNetworkTopologyTable();
    virtual bool AddrAreEqual(const IPv4Address& addr1,
            const IPv4Address& addr2);
    void printTopologyUpdateData(IPv4Address hostAddress);
    void removeNeighborTopologyData();
private:
    virtual void deleteNeibor(HostCharacteristic *neighbor);
    HostCharacteristic *getNeighbor(IPv4Address& address);
};

#endif /* NETWORKTOPOLOGYUPDATE_H_ */
