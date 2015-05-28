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

#include <NeighborTopologyData.h>

/**
 * Inserts and updates the neighborhoodinformations with the received updateMSG of the Neighbors
 */
void NeighborTopologyData::updateLinkedNeighbor(IPv4Address originatorAddr,
        MACAddress macAddress, Coord position, simtime_t liveTime) {
    HostCharacteristic *linkedNeighbor = getNeighbor(originatorAddr);
    if (!linkedNeighbor) {
        linkedNeighbor = new HostCharacteristic;
        linkedNeighbor->setPosition(position);
        linkedNeighbor->setLifeTime(liveTime);
        linkedNeighbor->setOriginatorAddress(originatorAddr);
        linkedNeighbor->setMacAddress(macAddress);
        neighbors.insert(neighbors.end(), *linkedNeighbor);
    } else {
        linkedNeighbor->setPosition(position);
        linkedNeighbor->setLifeTime(liveTime);
    }

}

/**
 * Erases a neighbor 
 */
void NeighborTopologyData::deleteNeibor(HostCharacteristic *neighbor) {
    bool hasEntry = false;
    HostCharacteristic *tmp = 0;
    for (Neighbors::iterator it = neighbors.begin(); it != neighbors.end();) {
        *tmp = *it;

        if (tmp->getOriginatorAddress().operator ==(
                neighbor->getOriginatorAddress()) == true) {
            neighbors.erase(it);
            hasEntry = true;
        }
        it++;
    }
    if (!hasEntry) {
        delete tmp;
    }
}

 /**
  * Erases obsolete neighbors
  */
void NeighborTopologyData::updateNeighborhoodTopology(int allowedHelloLoss,
        int currentSimTime, double helloIntervall) {

    for (Neighbors::iterator it = neighbors.begin(); it != neighbors.end();) {

        if ((it->getLifeTime() + (helloIntervall * allowedHelloLoss)).operator <(
                simTime())) {
            it = neighbors.erase(it);
        } else {
            it++;
        }
    }

}

/**
 * returns the search HostCharacteristic
 */
HostCharacteristic *NeighborTopologyData::getNeighbor(IPv4Address& address) {
    for (Neighbors::iterator it = neighbors.begin(); it != neighbors.end();
            it++) {

        if (it->getOriginatorAddress().operator ==(address) == true) {
            return &(*it);
        }
    }
    return NULL;
}
void NeighborTopologyData::printTopologyUpdateData(IPv4Address hostAddress) {
    for (Neighbors::iterator it = neighbors.begin(); it != neighbors.end();) {
        it++;
    }
}
NeighborTopologyData::Neighbors NeighborTopologyData::getNetworkTopologyTable() {
    return neighbors;
}

bool NeighborTopologyData::AddrAreEqual(const IPv4Address& addr1,
        const IPv4Address& addr2) {
    if (addr1.getInt() == addr2.getInt()) {
        return true;
    }
    return false;
}

/**
 * Deletes the whole neighborhoodinfomations
 * ('If the node shuts down')
 */
void NeighborTopologyData::removeNeighborTopologyData() {
    neighbors.erase(neighbors.begin(), neighbors.end());
}
NeighborTopologyData::NeighborTopologyData() {

}

NeighborTopologyData::~NeighborTopologyData() {
    for (Neighbors::iterator it = neighbors.begin(); it != neighbors.end();
            it++) {
//        HostCharacteristic (*del) = (*it);
//        delete del;
    }
}

