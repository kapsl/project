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

import inet.transport.IUDP;
import inet.applications.IUDPApp;
import inet.applications.IPingApp;


module Device2DeviceStandardHost extends Device2DeviceHostArchitecture
{
    parameters:
        int numUdpApps = default(0);  // no of UDP apps. Specify the app types in INI file with udpApp[0..1].typename="UDPVideoStreamCli" syntax
        int numPingApps = default(0);  // no of PING apps. Specify the app types in INI file with pingApp[0..1].typename="PingApp" syntax

        bool hasUdp = default(numUdpApps>0);
        string udpType = default(firstAvailable("UDP","UDP_None"));
        networkLayer.proxyARP = default(false);

    submodules:

        udpApp[numUdpApps]: <> like IUDPApp {
            parameters:
                @display("p=317,50,row,60");
        }
        udp: <udpType> like IUDP if hasUdp {
            parameters:
                @display("p=317,141");
        }
        pingApp[numPingApps]: <default("PingApp")> like IPingApp {
            parameters:
                @display("p=635,141,row,60");
        }

    connections allowunconnected:

        for i=0..numUdpApps-1 {
            udpApp[i].udpOut --> udp.appIn++;
            udpApp[i].udpIn <-- udp.appOut++;
        }

        udp.ipOut --> networkLayer.transportIn++ if hasUdp;
        udp.ipIn <-- networkLayer.transportOut++ if hasUdp;


        for i=0..numPingApps-1 {
            networkLayer.pingOut++ --> pingApp[i].pingIn;
            networkLayer.pingIn++ <-- pingApp[i].pingOut;
        }
}
