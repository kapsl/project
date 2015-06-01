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

package networkstructures.src.nodes;

import inet.nodes.inet.WirelessHost;
import inet.networklayer.routing.aodv.AODVRouting;
import networkstructures.src.routing.RoutingServerManagement;
//import networkstructures.src.routing.AODVRoutingManipulated;
//import networkstructures.src.routing.AODVRouting;
//import inet.src.networklayer.routing.aodv.

module Device2DeviceRouter extends Device2DeviceStandardHost
{
    parameters:
        int udpPort = default(654);
        double delayTime @unit("s") = default(0s);
        int timeToLive = default(2);
        IPForward = true;
        numRadios = 1;
        wlanIface.mgmtType = default("Ieee80211MgmtAdhoc");

    submodules:
        aodv: AODVRouting {
            @display("p=582,287");
        }
        rsmgmnt: RoutingServerManagement {
            @display("p=461,287;i=block/routing");
        }
    connections:
        rsmgmnt.rsMgmntNLOut --> networkLayer.transportIn++;
        rsmgmnt.rsMgmntNLIn <-- networkLayer.transportOut++;

        aodv.ipIn <-- rsmgmnt.rsMgmntAODVOut;
        aodv.ipOut --> rsmgmnt.rsMgmnAODVtIn;

}
