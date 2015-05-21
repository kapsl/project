#!/bin/bash
#
#

echo -e "Running Script EndToEndDelay 30Sek Interval..."
./calcEndToEndDelayNumHost.sh "../SingleSDPairGeneral-0.sca" "../TenSDPairGeneral-0.sca" "../FifteenSDPairGeneral-0.sca" "../TwentySDPairGeneral-0.sca" "../ThirtySDPairGeneral-0.sca" "../SingleSDPairAODVNetwork-0.sca" "../TenSDPairAODVNetwork-0.sca" "../FifteenSDPairAODVNetwork-0.sca" "../TwentySDPairAODVNetwork-0.sca" "../ThirtySDPairAODVNetwork-0.sca" "30Sec" 
#
echo -e "Running Script EndToEndDelay 1Sek Interval..."
./calcEndToEndDelayNumHost.sh "../SingleSDPairGeneral-1.sca" "../TenSDPairGeneral-1.sca" "../FifteenSDPairGeneral-1.sca" "../TwentySDPairGeneral-1.sca" "../ThirtySDPairGeneral-1.sca" "../SingleSDPairAODVNetwork-1.sca" "../TenSDPairAODVNetwork-1.sca" "../FifteenSDPairAODVNetwork-1.sca" "../TwentySDPairAODVNetwork-1.sca" "../ThirtySDPairAODVNetwork-1.sca" "1Sec"
#
echo -e "Running Script EndToEndDelay 0.5Sek Interval..."
./calcEndToEndDelayNumHost.sh "../SingleSDPairGeneral-2.sca" "../TenSDPairGeneral-2.sca" "../FifteenSDPairGeneral-2.sca" "../TwentySDPairGeneral-2.sca" "../ThirtySDPairGeneral-2.sca" "../SingleSDPairAODVNetwork-2.sca" "../TenSDPairAODVNetwork-2.sca" "../FifteenSDPairAODVNetwork-2.sca" "../TwentySDPairAODVNetwork-2.sca" "../ThirtySDPairAODVNetwork-2.sca" "05Sec"
#
echo -e "Running Script EndToEndDelay 0.1ek Interval..."
./calcEndToEndDelayNumHost.sh "../SingleSDPairGeneral-3.sca" "../TenSDPairGeneral-3.sca" "../FifteenSDPairGeneral-3.sca" "../TwentySDPairGeneral-3.sca" "../ThirtySDPairGeneral-3.sca" "../SingleSDPairAODVNetwork-3.sca" "../TenSDPairAODVNetwork-3.sca" "../FifteenSDPairAODVNetwork-3.sca" "../TwentySDPairAODVNetwork-3.sca" "../ThirtySDPairAODVNetwork-3.sca" "01Sec"

echo -e "Running Script EndToEndDelay 0.05ek Interval..."
./calcEndToEndDelayNumHost.sh "../SingleSDPairGeneral-4.sca" "../TenSDPairGeneral-4.sca" "../FifteenSDPairGeneral-4.sca" "../TwentySDPairGeneral-4.sca" "../ThirtySDPairGeneral-4.sca" "../SingleSDPairAODVNetwork-4.sca" "../TenSDPairAODVNetwork-4.sca" "../FifteenSDPairAODVNetwork-4.sca" "../TwentySDPairAODVNetwork-4.sca" "../ThirtySDPairAODVNetwork-4.sca" "005Sec"



