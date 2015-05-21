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

//
// TODO auto-generated module
//
simple D2DRA
{
    parameters:
        string networkProtocolModule = default("^.networkLayer.ip");
              int udpPort = default(654);

//        double maxPeriodicJitter @unit("s") = default(helloInterval / 4); // it MUST NOT be negative; it MUST NOT be greater than MESSAGE_INTERVAL/2; it SHOULD NOT be greater than MESSAGE_INTERVAL/4.
//        volatile double periodicJitter @unit("s") = default(uniform(0s, maxPeriodicJitter)); // jitter for externally triggered message generation and message forwarding

        // RFC 5148:
        // need more revise: As well as the decision as to whether
        // to use jitter being dependent on the medium access control and
        // lower layers, the selection of the MAXJITTER parameter SHOULD
        // be appropriate to those mechanisms.
        double maxJitter @unit("s") = default(5ms);
        volatile double jitter @unit("s") = default(uniform(0ms, maxJitter)); // jitter for broadcasts
        
                //Statistic 
    gates:
        input d2dIn;
        output d2dOut;
}
