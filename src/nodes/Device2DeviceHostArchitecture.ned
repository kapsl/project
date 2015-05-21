//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

package networkstructures.src.nodes;

import inet.base.NotificationBoard;
import inet.battery.IBattery;
import inet.linklayer.IExternalNic;
import inet.linklayer.IWiredNic;
import inet.linklayer.IWirelessNic;
import inet.linklayer.loopback.LoopbackInterface;
import inet.mobility.contract.IMobility;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.RoutingTable;
import inet.status.NodeStatus;
import inet.util.PcapRecorder;
import inet.nodes.inet.NetworkLayer;



//
// Contains the common lower layers (linklayer and networklayer)
// of Router, StandardHost, WirelessHost etc.
//
// NOTE:
//    - IPForward is turned on by default.
//    - use this model only as a base type. In simulations use ~Router,
//      ~StandardHost, ~WirelessHost and ~AdhocHost
//
module Device2DeviceHostArchitecture
{
    parameters:
        @display("bgb=,448");
        @node;
        @labels(node,ethernet-node,wireless-node);
        bool hasStatus = default(false);
        int numExtInterfaces = default(0);
        int numRadios = default(1);               // the number of radios in the router. by default no wireless
        int numPcapRecorders = default(0); // no of PcapRecorders.
        string mobilityType = default(numRadios > 0 ? "StationaryMobility" : "");
        string routingFile = default("");
        bool IPForward = default(true);
        bool forwardMulticast = default(false);
        string batteryType = default("");
    gates:
        input radioIn[2] @directIn;
    submodules:

        status: NodeStatus if hasStatus {
            @display("p=50,50");
        }

        notificationBoard: NotificationBoard {
            parameters:
                @display("p=53,155;is=s");
        }

        battery: <batteryType> like IBattery if batteryType != "" {
            parameters:
                @display("p=53,77;i=block/plug;is=s");
        }

        // optional mobility module. Required only if wireless cards are present
        mobility: <mobilityType> like IMobility if mobilityType != "" {
            parameters:
                @display("p=53,111");
        }

        // network layer
        networkLayer: NetworkLayer {
            parameters:
                @display("p=317,295;q=queue");
        }

        routingTable: RoutingTable {
            parameters:
                @display("p=53,225;is=s");
                IPForward = IPForward;
                forwardMulticast = forwardMulticast;
                routingFile = routingFile;
        }

        // linklayer
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=53,287;is=s");
        }

        pcapRecorder[numPcapRecorders]: PcapRecorder {
            @display("p=53,338,r,10");
        }

        lo0: LoopbackInterface {
            @display("p=42,406");
        }
        wlan[1]: <default("D2DIeee80211Nic")> like IWirelessNic {
            parameters:
                @display("p=249,406,row,60;q=queue");
        }

        umtsIface: <default("Ieee80211Nic")> like IWirelessNic {
            //            UMTSTerrestrialRadioAccessNic
            parameters:
                @display("p=331,406,row,60;q=queue");
        }


    connections allowunconnected:
        // connections to network outside
        networkLayer.ifOut++ --> lo0.upperLayerIn;
        lo0.upperLayerOut --> networkLayer.ifIn++;



        radioIn[0] --> { @display("m=s"); } --> wlan[0].radioIn;
        wlan[0].upperLayerOut --> networkLayer.ifIn++;
        wlan[0].upperLayerIn <-- networkLayer.ifOut++;

        radioIn[1] --> { @display("m=s"); } --> umtsIface.radioIn;
        umtsIface.upperLayerOut --> networkLayer.ifIn++;
        umtsIface.upperLayerIn <-- networkLayer.ifOut++;

}

