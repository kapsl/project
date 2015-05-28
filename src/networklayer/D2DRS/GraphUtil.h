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

#ifndef GRAPHUTIL_H_
#define GRAPHUTIL_H_
#include "NodeCharacteristic.h"
#include "IPv4Address.h"

class GraphUtil {
private:
    static std::map<IPv4Address, NodeCharacteristic> graphInformations;
public:
    GraphUtil();
    virtual ~GraphUtil();
    static void insertElement(IPv4Address address, NodeCharacteristic characteristic);
    static std::map<IPv4Address, NodeCharacteristic>::iterator getElement(IPv4Address address);
    static void removeElement(IPv4Address address);
};


#endif /* GRAPHUTIL_H_ */
