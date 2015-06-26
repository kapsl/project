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

package networkstructures.src.linklayer;

import inet.base.IHook;
import inet.linklayer.IWirelessNic;
//import inet.linklayer.ieee80211.mac.Ieee80211Mac;
import networkstructures.src.linklayer.Ieee80211Mac;
import inet.linklayer.ieee80211.mgmt.IIeee80211Mgmt;
import inet.linklayer.ieee80211.mgmt.Ieee80211AgentSTA;
import inet.linklayer.ieee80211.radio.Ieee80211Radio;

//
// Modified interface with the WLanPacketCapsulation SimpleModule
//
module D2DIeee80211Nic like IWirelessNic
{
    parameters:
        string mgmtType = default("Ieee80211MgmtSTA"); // name of the management module type (implements IIeee80211Mgmt)
        string opMode @enum("b","g","a","p") = default("g");
        double bitrate @unit("bps") = default(opMode == "b" ? 11Mbps : opMode == "p" ? 27Mbps : 54Mbps);
        int numOutputHooks = default(0);
        int numInputHooks = default(0);
        bool _agentNeeded = (mgmtType == "Ieee80211MgmtSTA");   // internal par. do not use, shows if optional agent module is needed
        @display("i=block/ifcard;bgb=336,409");
    gates:
        input upperLayerIn; // to upper layers
        output upperLayerOut; // from upper layers
        input radioIn @labels(AirFrame); // to receive AirFrames
    submodules:

        packetControl: WLanPacketCapsulation {
            @display("p=157,97");
        }
        outputHook[numOutputHooks]: <default("Nop")> like IHook if numOutputHooks>0 {
            @display("p=218,70");
        }
        inputHook[numInputHooks]: <default("Nop")> like IHook if numInputHooks>0 {
            @display("p=107,55");
        }
        // optional agent module (can be either 0 or 1 sized vector)
        agent: Ieee80211AgentSTA if _agentNeeded {
            parameters:
                @display("p=261,131");
        }
        mgmt: <mgmtType> like IIeee80211Mgmt {
            parameters:
                @display("p=157,192;q=wlanDataQueue");
        }
        mac: Ieee80211Mac {
            parameters:
                opMode = opMode;
                bitrate = bitrate;
                queueModule = "mgmt";
                @display("p=157,280");
                EDCA=false;
//                AIFSN0 = 1;
//AIFSN1=7;
        }
        radio: Ieee80211Radio {
            parameters:
                phyOpMode = opMode;
                bitrate = bitrate;
                @display("p=157,355");
        }
    connections:

        packetControl.mgmntIn <-- mgmt.upperLayerOut if numInputHooks == 0;
        packetControl.mgmntOut --> mgmt.upperLayerIn if numOutputHooks == 0;
        radioIn --> { @display("m=s"); } --> radio.radioIn;
        radio.upperLayerIn <-- mac.lowerLayerOut;
        radio.upperLayerOut --> mac.lowerLayerIn;

        mac.upperLayerOut --> mgmt.macIn;
        mac.upperLayerIn <-- mgmt.macOut;

        mgmt.agentOut --> agent.mgmtIn if _agentNeeded;
        mgmt.agentIn <-- agent.mgmtOut if _agentNeeded;

        packetControl.upperLayerOut --> { @display("m=n"); } --> upperLayerOut if numInputHooks == 0;
        packetControl.upperLayerIn <-- { @display("m=n"); } <-- upperLayerIn if numOutputHooks == 0;

        mgmt.upperLayerOut --> inputHook[0].in if numInputHooks > 0;
        for i=0..numInputHooks-2 {
            inputHook[i].out --> inputHook[i+1].in;
        }
        inputHook[numInputHooks-1].out --> { @display("m=n"); } --> upperLayerOut if numInputHooks > 0;
        outputHook[0].in <-- { @display("m=n"); } <-- upperLayerIn if numOutputHooks > 0;
        for i=0..numOutputHooks-2 {
            outputHook[i].out --> outputHook[i+1].in;
        }
        mgmt.upperLayerIn <-- outputHook[numOutputHooks-1].out if numOutputHooks > 0;
}
