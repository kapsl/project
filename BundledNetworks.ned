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

package networkstructures;


import inet.base.LifecycleController;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.world.radio.ChannelControl;
import inet.world.scenario.ScenarioManager;
import inet.nodes.aodv.AODVRouter;

import networkstructures.src.nodes.D2DRS;

import networkstructures.src.nodes.Device2DeviceRouter;

network General
{
}
network BundledNetworks
{
    parameters:
        int numHosts;

        @display("bgi=background/EvaluatiomArea");
    submodules:
        channelControl: ChannelControl {
            parameters:
                @display("p=50,50");
        }
        configurator: IPv4NetworkConfigurator {
            parameters:
                config = xmldoc("IPv4AddressResolver/AODVIPv4Configuration.xml");
                @display("p=50,100");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=50,150");
        }
        lifecycleController: LifecycleController {
            parameters:
                @display("p=50,200");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xmldoc("simpleLifecycle.xml"));
                @display("p=50,250");
        }
        host[numHosts]: AODVRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070");
        }
}

network SemiDecentralized
{
    parameters:
        int numHosts;
        @display("bgi=background/EvaluatiomArea");
    submodules:
        channelControl: ChannelControl {
            parameters:
                @display("p=50,50");
        }
        configurator: IPv4NetworkConfigurator {
            parameters:
                addDefaultRoutes = false;
                addStaticRoutes = false;
                config = xmldoc("IPv4AddressResolver/SemiDecentralizedIPv4Configuration.xml");
                @display("p=50,100");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=50,150");
        }
        lifecycleController: LifecycleController {
            parameters:
                @display("p=50,200");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xmldoc("simpleLifecycle.xml"));
                @display("p=50,250");
        }
        host[numHosts]: Device2DeviceRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070");
        }

        RoutingService: D2DRS {
            parameters:
                @display("i=device/accesspoint");

        }

}
