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

#include <GraphUtil.h>
std::map<IPv4Address, NodeCharacteristic> GraphUtil::graphInformations;
GraphUtil::GraphUtil() {
}

GraphUtil::~GraphUtil() {
}

std::map<IPv4Address, NodeCharacteristic>::iterator GraphUtil::getElement(
        IPv4Address address) {
    return GraphUtil::graphInformations.find(address);
}

void GraphUtil::insertElement(IPv4Address address,
        NodeCharacteristic characteristic) {
    graphInformations.insert(
            std::pair<IPv4Address, NodeCharacteristic>(address,
                    characteristic));
}

void GraphUtil::removeElement(IPv4Address address) {
    graphInformations.erase(address);
}
