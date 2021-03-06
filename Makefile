#
# OMNeT++/OMNEST Makefile for NetworkStructures
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -I../inet/src/transport/tcp_common -I../inet/src/base -I../inet/src/util -I../inet/src/linklayer/ieee80211/mac -I../inet/src/transport/udp -I../inet/src/linklayer/ieee80211/radio/errormodel -I../inet/src/util/headerserializers -I../inet/src/linklayer/ieee80211/radio -I../inet/src/status -I../inet/src/transport/sctp -I../inet/src/networklayer/icmpv6 -I../inet/src/linklayer/radio/propagation -I../inet/src/transport/contract -I../inet/src/networklayer/ipv6tunneling -I../inet/src/world/radio -I../inet/src/linklayer/contract -I../inet/src/util/headerserializers/udp -I../inet/src/util/headerserializers/tcp -I../inet/src/linklayer/radio -I../inet/src/world/obstacles -I../inet/src/networklayer/common -I../inet/src/networklayer/ipv6 -I../inet/src/networklayer/arp -I../inet/src/networklayer/routing/aodv -I../inet/src/networklayer/contract -I../inet/src -I../inet/src/networklayer/xmipv6 -I../inet/src/util/headerserializers/sctp -I../inet/src/util/headerserializers/ipv6 -I../inet/src/battery/models -I../inet/src/networklayer/autorouting/ipv4 -I../inet/src/networklayer/ipv4 -I../inet/src/mobility/contract -I../inet/src/applications/pingapp -I../inet/src/linklayer/common -I../inet/src/util/headerserializers/ipv4 -I../inet/src/mobility/common -L../inet/out/$$\(CONFIGNAME\)/src -linet -DINET_IMPORT -KINET_PROJ=../inet
#

# Name of target to be created (-o option)
TARGET = NetworkStructures$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../inet/src/transport/tcp_common \
    -I../inet/src/base \
    -I../inet/src/util \
    -I../inet/src/linklayer/ieee80211/mac \
    -I../inet/src/transport/udp \
    -I../inet/src/linklayer/ieee80211/radio/errormodel \
    -I../inet/src/util/headerserializers \
    -I../inet/src/linklayer/ieee80211/radio \
    -I../inet/src/status \
    -I../inet/src/transport/sctp \
    -I../inet/src/networklayer/icmpv6 \
    -I../inet/src/linklayer/radio/propagation \
    -I../inet/src/transport/contract \
    -I../inet/src/networklayer/ipv6tunneling \
    -I../inet/src/world/radio \
    -I../inet/src/linklayer/contract \
    -I../inet/src/util/headerserializers/udp \
    -I../inet/src/util/headerserializers/tcp \
    -I../inet/src/linklayer/radio \
    -I../inet/src/world/obstacles \
    -I../inet/src/networklayer/common \
    -I../inet/src/networklayer/ipv6 \
    -I../inet/src/networklayer/arp \
    -I../inet/src/networklayer/routing/aodv \
    -I../inet/src/networklayer/contract \
    -I../inet/src \
    -I../inet/src/networklayer/xmipv6 \
    -I../inet/src/util/headerserializers/sctp \
    -I../inet/src/util/headerserializers/ipv6 \
    -I../inet/src/battery/models \
    -I../inet/src/networklayer/autorouting/ipv4 \
    -I../inet/src/networklayer/ipv4 \
    -I../inet/src/mobility/contract \
    -I../inet/src/applications/pingapp \
    -I../inet/src/linklayer/common \
    -I../inet/src/util/headerserializers/ipv4 \
    -I../inet/src/mobility/common \
    -I. \
    -IAnalysis \
    -IAnalysis/KlementsAnalysis \
    -IAnalysis/KlementsAnalysis/plottingEndToEndDelyInterval \
    -IAnalysis/KlementsAnalysis/plottingEndToEndDelyNumHost \
    -IAnalysis/KlementsAnalysis/plottingPacketDeliveryFraction \
    -IAnalysis/KlementsAnalysis/plottingPacketDeliveryFractionNumHost \
    -IAnalysis/KlementsAnalysis/plottingRREQRREPInterval \
    -IAnalysis/KlementsAnalysis/plottingRREQRREPNumHost \
    -IAnalysis/KlementsAnalysis/plottingRoutingLoadInterval \
    -IAnalysis/KlementsAnalysis/plottingRoutingLoadNumHost \
    -IAnalysis/KlementsAnalysis/plottingThrougputInterval \
    -IAnalysis/KlementsAnalysis/plottingThrougputNumHost \
    -IAnalysis/omnetAnalyzer \
    -IAnalysis/omnetAnalyzer/Test \
    -IAnalysis/omnetAnalyzer/bin \
    -IAnalysis/omnetAnalyzer/bin/omnetAnalyzer \
    -IAnalysis/omnetAnalyzer/bin/omnetAnalyzer/analyzer \
    -IAnalysis/omnetAnalyzer/libs \
    -IAnalysis/omnetAnalyzer/src \
    -IAnalysis/omnetAnalyzer/src/omnetAnalyzer \
    -IAnalysis/omnetAnalyzer/src/omnetAnalyzer/analyzer \
    -IAnalysis/shell_scripts_now_better_use_omnetAnalyzer \
    -IIPv4AddressResolver \
    -IMobileSingleSourceDest \
    -IMobileTenSourceDest \
    -IMobileThirtySourceDest \
    -IMobileTwentySourceDest \
    -ISimulation \
    -IStaticFifteenSourceDest \
    -IStaticThirtySourceDest \
    -IStaticTwentySourceDest \
    -Icopy_to_inet \
    -Ihtml \
    -Ihtml/search \
    -Isrc \
    -Isrc/hosts \
    -Isrc/linklayer \
    -Isrc/networklayer \
    -Isrc/networklayer/D2DRS \
    -Isrc/nodes \
    -Isrc/routing \
    -Isrc/routing/messagetypes

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../inet/out/$(CONFIGNAME)/src  -linet
LIBS += -Wl,-rpath,`abspath ../inet/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/src/hosts/HostCharacteristic.o \
    $O/src/hosts/NeighborTopologyData.o \
    $O/src/linklayer/MyIeee80211Mac.o \
    $O/src/linklayer/WLanPacketCapsulation.o \
    $O/src/networklayer/D2DRS/GraphUtil.o \
    $O/src/networklayer/D2DRS/LinkedNeighbor.o \
    $O/src/networklayer/D2DRS/NodeCharacteristic.o \
    $O/src/routing/DSDRA.o \
    $O/src/routing/RoutingServerManagement.o \
    $O/src/routing/messagetypes/RoutingServerControlData_m.o

# Message files
MSGFILES = \
    src/routing/messagetypes/RoutingServerControlData.msg

# Other makefile variables (-K)
INET_PROJ=../inet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f NetworkStructures NetworkStructures.exe libNetworkStructures.so libNetworkStructures.a libNetworkStructures.dll libNetworkStructures.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f Analysis/*_m.cc Analysis/*_m.h
	$(Q)-rm -f Analysis/KlementsAnalysis/*_m.cc Analysis/KlementsAnalysis/*_m.h
	$(Q)-rm -f Analysis/KlementsAnalysis/plottingEndToEndDelyInterval/*_m.cc Analysis/KlementsAnalysis/plottingEndToEndDelyInterval/*_m.h
	$(Q)-rm -f Analysis/KlementsAnalysis/plottingEndToEndDelyNumHost/*_m.cc Analysis/KlementsAnalysis/plottingEndToEndDelyNumHost/*_m.h
	$(Q)-rm -f Analysis/KlementsAnalysis/plottingPacketDeliveryFraction/*_m.cc Analysis/KlementsAnalysis/plottingPacketDeliveryFraction/*_m.h
	$(Q)-rm -f Analysis/KlementsAnalysis/plottingPacketDeliveryFractionNumHost/*_m.cc Analysis/KlementsAnalysis/plottingPacketDeliveryFractionNumHost/*_m.h
	$(Q)-rm -f Analysis/KlementsAnalysis/plottingRREQRREPInterval/*_m.cc Analysis/KlementsAnalysis/plottingRREQRREPInterval/*_m.h
	$(Q)-rm -f Analysis/KlementsAnalysis/plottingRREQRREPNumHost/*_m.cc Analysis/KlementsAnalysis/plottingRREQRREPNumHost/*_m.h
	$(Q)-rm -f Analysis/KlementsAnalysis/plottingRoutingLoadInterval/*_m.cc Analysis/KlementsAnalysis/plottingRoutingLoadInterval/*_m.h
	$(Q)-rm -f Analysis/KlementsAnalysis/plottingRoutingLoadNumHost/*_m.cc Analysis/KlementsAnalysis/plottingRoutingLoadNumHost/*_m.h
	$(Q)-rm -f Analysis/KlementsAnalysis/plottingThrougputInterval/*_m.cc Analysis/KlementsAnalysis/plottingThrougputInterval/*_m.h
	$(Q)-rm -f Analysis/KlementsAnalysis/plottingThrougputNumHost/*_m.cc Analysis/KlementsAnalysis/plottingThrougputNumHost/*_m.h
	$(Q)-rm -f Analysis/omnetAnalyzer/*_m.cc Analysis/omnetAnalyzer/*_m.h
	$(Q)-rm -f Analysis/omnetAnalyzer/Test/*_m.cc Analysis/omnetAnalyzer/Test/*_m.h
	$(Q)-rm -f Analysis/omnetAnalyzer/bin/*_m.cc Analysis/omnetAnalyzer/bin/*_m.h
	$(Q)-rm -f Analysis/omnetAnalyzer/bin/omnetAnalyzer/*_m.cc Analysis/omnetAnalyzer/bin/omnetAnalyzer/*_m.h
	$(Q)-rm -f Analysis/omnetAnalyzer/bin/omnetAnalyzer/analyzer/*_m.cc Analysis/omnetAnalyzer/bin/omnetAnalyzer/analyzer/*_m.h
	$(Q)-rm -f Analysis/omnetAnalyzer/libs/*_m.cc Analysis/omnetAnalyzer/libs/*_m.h
	$(Q)-rm -f Analysis/omnetAnalyzer/src/*_m.cc Analysis/omnetAnalyzer/src/*_m.h
	$(Q)-rm -f Analysis/omnetAnalyzer/src/omnetAnalyzer/*_m.cc Analysis/omnetAnalyzer/src/omnetAnalyzer/*_m.h
	$(Q)-rm -f Analysis/omnetAnalyzer/src/omnetAnalyzer/analyzer/*_m.cc Analysis/omnetAnalyzer/src/omnetAnalyzer/analyzer/*_m.h
	$(Q)-rm -f Analysis/shell_scripts_now_better_use_omnetAnalyzer/*_m.cc Analysis/shell_scripts_now_better_use_omnetAnalyzer/*_m.h
	$(Q)-rm -f IPv4AddressResolver/*_m.cc IPv4AddressResolver/*_m.h
	$(Q)-rm -f MobileSingleSourceDest/*_m.cc MobileSingleSourceDest/*_m.h
	$(Q)-rm -f MobileTenSourceDest/*_m.cc MobileTenSourceDest/*_m.h
	$(Q)-rm -f MobileThirtySourceDest/*_m.cc MobileThirtySourceDest/*_m.h
	$(Q)-rm -f MobileTwentySourceDest/*_m.cc MobileTwentySourceDest/*_m.h
	$(Q)-rm -f Simulation/*_m.cc Simulation/*_m.h
	$(Q)-rm -f StaticFifteenSourceDest/*_m.cc StaticFifteenSourceDest/*_m.h
	$(Q)-rm -f StaticThirtySourceDest/*_m.cc StaticThirtySourceDest/*_m.h
	$(Q)-rm -f StaticTwentySourceDest/*_m.cc StaticTwentySourceDest/*_m.h
	$(Q)-rm -f copy_to_inet/*_m.cc copy_to_inet/*_m.h
	$(Q)-rm -f html/*_m.cc html/*_m.h
	$(Q)-rm -f html/search/*_m.cc html/search/*_m.h
	$(Q)-rm -f src/*_m.cc src/*_m.h
	$(Q)-rm -f src/hosts/*_m.cc src/hosts/*_m.h
	$(Q)-rm -f src/linklayer/*_m.cc src/linklayer/*_m.h
	$(Q)-rm -f src/networklayer/*_m.cc src/networklayer/*_m.h
	$(Q)-rm -f src/networklayer/D2DRS/*_m.cc src/networklayer/D2DRS/*_m.h
	$(Q)-rm -f src/nodes/*_m.cc src/nodes/*_m.h
	$(Q)-rm -f src/routing/*_m.cc src/routing/*_m.h
	$(Q)-rm -f src/routing/messagetypes/*_m.cc src/routing/messagetypes/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc Analysis/*.cc Analysis/KlementsAnalysis/*.cc Analysis/KlementsAnalysis/plottingEndToEndDelyInterval/*.cc Analysis/KlementsAnalysis/plottingEndToEndDelyNumHost/*.cc Analysis/KlementsAnalysis/plottingPacketDeliveryFraction/*.cc Analysis/KlementsAnalysis/plottingPacketDeliveryFractionNumHost/*.cc Analysis/KlementsAnalysis/plottingRREQRREPInterval/*.cc Analysis/KlementsAnalysis/plottingRREQRREPNumHost/*.cc Analysis/KlementsAnalysis/plottingRoutingLoadInterval/*.cc Analysis/KlementsAnalysis/plottingRoutingLoadNumHost/*.cc Analysis/KlementsAnalysis/plottingThrougputInterval/*.cc Analysis/KlementsAnalysis/plottingThrougputNumHost/*.cc Analysis/omnetAnalyzer/*.cc Analysis/omnetAnalyzer/Test/*.cc Analysis/omnetAnalyzer/bin/*.cc Analysis/omnetAnalyzer/bin/omnetAnalyzer/*.cc Analysis/omnetAnalyzer/bin/omnetAnalyzer/analyzer/*.cc Analysis/omnetAnalyzer/libs/*.cc Analysis/omnetAnalyzer/src/*.cc Analysis/omnetAnalyzer/src/omnetAnalyzer/*.cc Analysis/omnetAnalyzer/src/omnetAnalyzer/analyzer/*.cc Analysis/shell_scripts_now_better_use_omnetAnalyzer/*.cc IPv4AddressResolver/*.cc MobileSingleSourceDest/*.cc MobileTenSourceDest/*.cc MobileThirtySourceDest/*.cc MobileTwentySourceDest/*.cc Simulation/*.cc StaticFifteenSourceDest/*.cc StaticThirtySourceDest/*.cc StaticTwentySourceDest/*.cc copy_to_inet/*.cc html/*.cc html/search/*.cc src/*.cc src/hosts/*.cc src/linklayer/*.cc src/networklayer/*.cc src/networklayer/D2DRS/*.cc src/nodes/*.cc src/routing/*.cc src/routing/messagetypes/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/src/hosts/HostCharacteristic.o: src/hosts/HostCharacteristic.cc \
	src/hosts/HostCharacteristic.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET_PROJ)/src/util/FWMath.h
$O/src/hosts/NeighborTopologyData.o: src/hosts/NeighborTopologyData.cc \
	src/hosts/HostCharacteristic.h \
	src/hosts/NeighborTopologyData.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/ILifecycle.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET_PROJ)/src/networklayer/ipv4/RoutingTable.h \
	$(INET_PROJ)/src/networklayer/routing/aodv/AODVControlPackets_m.h \
	$(INET_PROJ)/src/util/FWMath.h
$O/src/linklayer/MyIeee80211Mac.o: src/linklayer/MyIeee80211Mac.cc \
	src/hosts/HostCharacteristic.h \
	src/hosts/NeighborTopologyData.h \
	src/linklayer/MyIeee80211Mac.h \
	src/linklayer/WLanPacketCapsulation.h \
	src/networklayer/D2DRS/GraphUtil.h \
	src/networklayer/D2DRS/NetworkTopologyGraph.h \
	src/networklayer/D2DRS/NodeCharacteristic.h \
	src/networklayer/D2DRS/setops.h \
	src/routing/RoutingServerManagement.h \
	src/routing/messagetypes/RoutingServerControlData_m.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/FSMA.h \
	$(INET_PROJ)/src/base/ILifecycle.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/IPassiveQueue.h \
	$(INET_PROJ)/src/base/LifecycleOperation.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/base/NodeOperations.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	$(INET_PROJ)/src/linklayer/common/MACBase.h \
	$(INET_PROJ)/src/linklayer/common/WirelessMacBase.h \
	$(INET_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/linklayer/contract/PhyControlInfo_m.h \
	$(INET_PROJ)/src/linklayer/contract/RadioState.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/IQoSClassifier.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Consts.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/Ieee80211DataRate.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/Ieee80211eClassifier.h \
	$(INET_PROJ)/src/linklayer/ieee80211/mac/WifiMode.h \
	$(INET_PROJ)/src/linklayer/ieee80211/radio/WifiPreambleType.h \
	$(INET_PROJ)/src/linklayer/radio/AirFrame_m.h \
	$(INET_PROJ)/src/linklayer/radio/ModulationType.h \
	$(INET_PROJ)/src/linklayer/radio/Radio80211aControlInfo_m.h \
	$(INET_PROJ)/src/mobility/common/MobilityAccess.h \
	$(INET_PROJ)/src/mobility/contract/IMobility.h \
	$(INET_PROJ)/src/networklayer/arp/ARP.h \
	$(INET_PROJ)/src/networklayer/arp/ARPPacket_m.h \
	$(INET_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET_PROJ)/src/networklayer/ipv4/RoutingTable.h \
	$(INET_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET_PROJ)/src/networklayer/routing/aodv/AODVControlPackets_m.h \
	$(INET_PROJ)/src/networklayer/routing/aodv/AODVRouteData.h \
	$(INET_PROJ)/src/networklayer/routing/aodv/AODVRouting.h \
	$(INET_PROJ)/src/status/NodeStatus.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket_m.h \
	$(INET_PROJ)/src/util/FWMath.h \
	$(INET_PROJ)/src/util/opp_utils.h
$O/src/linklayer/WLanPacketCapsulation.o: src/linklayer/WLanPacketCapsulation.cc \
	src/hosts/HostCharacteristic.h \
	src/linklayer/WLanPacketCapsulation.h \
	src/networklayer/D2DRS/GraphUtil.h \
	src/networklayer/D2DRS/NetworkTopologyGraph.h \
	src/networklayer/D2DRS/NodeCharacteristic.h \
	src/networklayer/D2DRS/setops.h \
	src/routing/messagetypes/RoutingServerControlData_m.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/ILifecycle.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/LifecycleOperation.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/base/NodeOperations.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	$(INET_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/networklayer/arp/ARP.h \
	$(INET_PROJ)/src/networklayer/arp/ARPPacket_m.h \
	$(INET_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET_PROJ)/src/networklayer/routing/aodv/AODVControlPackets_m.h \
	$(INET_PROJ)/src/networklayer/routing/aodv/AODVRouteData.h \
	$(INET_PROJ)/src/status/NodeStatus.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket_m.h \
	$(INET_PROJ)/src/util/FWMath.h
$O/src/networklayer/D2DRS/GraphUtil.o: src/networklayer/D2DRS/GraphUtil.cc \
	src/hosts/HostCharacteristic.h \
	src/networklayer/D2DRS/GraphUtil.h \
	src/networklayer/D2DRS/NodeCharacteristic.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET_PROJ)/src/util/FWMath.h
$O/src/networklayer/D2DRS/LinkedNeighbor.o: src/networklayer/D2DRS/LinkedNeighbor.cc \
	src/networklayer/D2DRS/LinkedNeighbor.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET_PROJ)/src/util/FWMath.h
$O/src/networklayer/D2DRS/NodeCharacteristic.o: src/networklayer/D2DRS/NodeCharacteristic.cc \
	src/hosts/HostCharacteristic.h \
	src/networklayer/D2DRS/NodeCharacteristic.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET_PROJ)/src/util/FWMath.h
$O/src/routing/DSDRA.o: src/routing/DSDRA.cc \
	src/hosts/HostCharacteristic.h \
	src/networklayer/D2DRS/GraphUtil.h \
	src/networklayer/D2DRS/NetworkTopologyGraph.h \
	src/networklayer/D2DRS/NodeCharacteristic.h \
	src/networklayer/D2DRS/setops.h \
	src/routing/DSDRA.h \
	src/routing/messagetypes/RoutingServerControlData_m.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/ILifecycle.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPSocket.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET_PROJ)/src/networklayer/routing/aodv/AODVControlPackets_m.h \
	$(INET_PROJ)/src/networklayer/routing/aodv/AODVRouteData.h \
	$(INET_PROJ)/src/status/NodeStatus.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket_m.h \
	$(INET_PROJ)/src/util/FWMath.h
$O/src/routing/RoutingServerManagement.o: src/routing/RoutingServerManagement.cc \
	src/hosts/HostCharacteristic.h \
	src/hosts/NeighborTopologyData.h \
	src/linklayer/WLanPacketCapsulation.h \
	src/networklayer/D2DRS/GraphUtil.h \
	src/networklayer/D2DRS/NetworkTopologyGraph.h \
	src/networklayer/D2DRS/NodeCharacteristic.h \
	src/networklayer/D2DRS/setops.h \
	src/routing/RoutingServerManagement.h \
	src/routing/messagetypes/RoutingServerControlData_m.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/ILifecycle.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/LifecycleOperation.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/base/NodeOperations.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	$(INET_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/mobility/common/MobilityAccess.h \
	$(INET_PROJ)/src/mobility/contract/IMobility.h \
	$(INET_PROJ)/src/networklayer/arp/ARP.h \
	$(INET_PROJ)/src/networklayer/arp/ARPPacket_m.h \
	$(INET_PROJ)/src/networklayer/arp/IARPCache.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/networklayer/common/INetfilter.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPSocket.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4ControlInfo.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4ControlInfo_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Datagram.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Datagram_m.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4Route.h \
	$(INET_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET_PROJ)/src/networklayer/ipv4/RoutingTable.h \
	$(INET_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	$(INET_PROJ)/src/networklayer/routing/aodv/AODVControlPackets_m.h \
	$(INET_PROJ)/src/networklayer/routing/aodv/AODVRouteData.h \
	$(INET_PROJ)/src/networklayer/routing/aodv/AODVRouting.h \
	$(INET_PROJ)/src/status/NodeStatus.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket_m.h \
	$(INET_PROJ)/src/util/FWMath.h
$O/src/routing/messagetypes/RoutingServerControlData_m.o: src/routing/messagetypes/RoutingServerControlData_m.cc \
	src/hosts/HostCharacteristic.h \
	src/networklayer/D2DRS/GraphUtil.h \
	src/networklayer/D2DRS/NetworkTopologyGraph.h \
	src/networklayer/D2DRS/NodeCharacteristic.h \
	src/networklayer/D2DRS/setops.h \
	src/routing/messagetypes/RoutingServerControlData_m.h \
	$(INET_PROJ)/src/base/Compat.h \
	$(INET_PROJ)/src/base/Coord.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv4Address.h \
	$(INET_PROJ)/src/networklayer/routing/aodv/AODVControlPackets_m.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket_m.h \
	$(INET_PROJ)/src/util/FWMath.h

