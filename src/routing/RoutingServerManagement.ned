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

package networkstructures.src.routing;

import inet.networklayer.routing.aodv.AODVRouting;
//
// TODO auto-generated module
//
// SimpleModule describes the client side D2DR-logic
simple RoutingServerManagement //extends  AODVRouting
{
    parameters:
        //        bool isRegistrated;	//Handles preregistration with the adaptiveServer

        int timeToLive = default(2);
        double serverUpdateInterval @unit("s") = default(1s);//defines the update interval between D2DRS and UserEquipment
        int maxRouteCacheSize = default(10); //NOT IMPLEMENTED YET. The routingTable should contain only a specific number of routes. 
        double helloInterval = default(1.0); // NeighborhoodUpdateMSG interval
        int allowedHelloLoss = default(2); 
        bool useHelloMessages = default(true);
        int serverRegRetryInterval @unit("s") = default(2s); //After 2sec, the ServerRegistrationMSG is sent again if no response
        double maxPeriodicJitter @unit("s") = default(serverUpdateInterval / 4); // it MUST NOT be negative; it MUST NOT be greater than MESSAGE_INTERVAL/2; it SHOULD NOT be greater than MESSAGE_INTERVAL/4.
        volatile double periodicJitter @unit("s") = default(uniform(0s, maxPeriodicJitter)); // jitter for externally triggered message generation and message forwarding
        double activeRouteTimeout @unit("s") = default(3s); // the timeout value for cached routes If Hello messages are used, then the
                                                            // ACTIVE_ROUTE_TIMEOUT parameter value MUST be more than the value
                                                            // (ALLOWED_HELLO_LOSS * HELLO_INTERVAL).
        double myRouteTimeout @unit("s") = default(2 * activeRouteTimeout); // the value of the lifetime field that a destination node places in RREPs
        int udpPort = default(654);

        double delayTimeServerRegistration @unit("s") = default(0s);
        double delayTimeTopologyUpdate @unit("s") = default(0s);
        string networkProtocolModule = default("^.networkLayer.ip");
        @class(RoutingServerManagement);

    gates:
        input rsMgmnAODVtIn;
        output rsMgmntAODVOut;

        input rsMgmntNLIn;
        output rsMgmntNLOut;

}
