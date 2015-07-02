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

#ifndef LINKEDNEIGBOR_H_
#define LINKEDNEIGBOR_H_

#include "IPv4Address.h"
#include "string.h"
#include "Coord.h"
#include "MACAddress.h"
#include <omnetpp.h>

/**
 * This is the datastructure, that stores information about a host (for the hosts, a different structure
 * is used for storing node information on the basis station
 */
class HostCharacteristic {

private:
    simtime_t lifeTime;
    IPv4Address srcAddressIP;
    Coord position;
    MACAddress macAddress;

    /**
     * Is nr of givenup packages -- means if high --> congestion is high
     */
    int congestionState;

public:
    HostCharacteristic();
    virtual ~HostCharacteristic();

    virtual std::string info() const;

    const simtime_t& getLifeTime() const {
        return lifeTime;
    }

    void setLifeTime(const simtime_t& lifeTime) {
        this->lifeTime = lifeTime;
    }

    const IPv4Address& getOriginatorAddress() const {
        return srcAddressIP;
    }

    void setOriginatorAddress(const IPv4Address& originatorAddress) {
        this->srcAddressIP = originatorAddress;
    }

    const Coord& getPosition() const {
        return position;
    }

    void setPosition(const Coord& position) {
        this->position = position;
    }

    const MACAddress& getMacAddress() const {
        return macAddress;
    }

    void setMacAddress(const MACAddress& macAddress) {
        this->macAddress = macAddress;
    }

    const int getCongestionState() const {
        return congestionState;
    }

    void setCongestionState(const int congestionState) {
        this->congestionState = congestionState;
    }
};

#endif /* LINKEDNEIGBOR_H_ */
