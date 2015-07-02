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

#ifndef NODECHARACTERISTIC_H_
#define NODECHARACTERISTIC_H_

#include "HostCharacteristic.h"
#include "Coord.h"
#include "MACAddress.h"

class NodeCharacteristic {
private:
    Coord position;
    MACAddress macAddress;

    /**
     * Is nr of givenup packages -- means if high --> congestion is high
     */
    int congestionState;

public:
    NodeCharacteristic();
    NodeCharacteristic(HostCharacteristic hostCharacteristic);

    virtual ~NodeCharacteristic();

    const Coord& getPosition() const {
        return this->position;
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

#endif /* NODECHARACTERISTICS_H_ */
