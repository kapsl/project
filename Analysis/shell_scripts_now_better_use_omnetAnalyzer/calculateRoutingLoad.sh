#!/bin/bash

# Calculate routing load
# TODO parameters

counter=0

echo "Calculating routing load"	

for filename in `ls -1v $1*.sca`
do

val=0
sumSentPayloadGeneral=0
sumSentAODVPktsGeneral=0
routingLoadD2DRS=0
routingLoadAODV=0

#echo -e '#interval(sec)\t%RLGeneral\t%RLAODV\tPayloadD2DRS\tAODVAODV' > RoutingLoad${11}.dat;
#echo -e '#interval(sec)\t%RLGeneral\t%RLAODV\tPayloadD2DRS\tAODVAODV';

while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentPayloadGeneral=$(($sumSentPayloadGeneral + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "RREPSent:count" || $line =~ "RREQSent:count" || $line =~ "RERRSentNow" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODVPktsGeneral=$(($sumSentAODVPktsGeneral + $val))
fi
done < $filename;

#
#
#AODV
#
#sumSentAODVPktsAODV=0
#sumSentPayloadAODV=0
#val=0
#echo "30sec calculations AODV..."	
#while read line
#do 
#if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
#then
#val=$(echo $line | cut -d ' ' -f 4- )
#sumSentPayloadAODV=$(($sumSentPayloadAODV + $val))
#val=0
#fi
#if [[ $line =~ ^"scalar" && $line =~ "RREPSent:count" || $line =~ "RREQSent:count" || $line =~ "RERRSent:count" ]]
#then
#val=$(echo $line | cut -d ' ' -f 4- )
#sumSentAODVPktsAODV=$(($sumSentAODVPktsAODV + $val))
#fi
#done < $6;

# UDP packages + routing packages
# Calculate Routing load: (Routing Packages / All Packages) * 100
tmpValueD2DRS=$(echo $sumSentPayloadGeneral+$sumSentAODVPktsGeneral | bc -l)
tmpValueD2DRS=$(echo 100/$tmpValueD2DRS | bc -l)
routingLoadD2DRS=$(echo "scale=2; "$tmpValueD2DRS*$sumSentAODVPktsGeneral/1 | bc -l)
#echo "RoutingLoadD2DRS: "$routingLoadD2DRS

#tmpValueAODV=$(echo $sumSentPayloadAODV+$sumSentAODVPktsAODV | bc -l)
#tmpValueAODV=$(echo 100/$tmpValueAODV | bc -l)
#routingLoadAODV=$(echo "scale=2; "$tmpValueAODV*$sumSentAODVPktsAODV/1 | bc )
#echo $routingLoadAODV
#echo "Payload sent General: "$sumSentPayloadGeneral
#echo "AODVPackets sent General: "$sumSentAODVPktsGeneral
#echo "Payload sent AODV: " $sumSentPayloadAODV
#echo "AODVPackets sent AODV: "$sumSentAODVPktsAODV
#echo -e "30\t"$routingLoadD2DRS'\t'$routingLoadAODV'\t'$sumSentAODVPktsGeneral'\t'$sumSentAODVPktsAODV	 >> RoutingLoad${11}.dat;
#echo -e $routingLoadD2DRS'\t'$sumSentAODVPktsGeneral;

if [ $(($counter%3)) == 0 ] 
then
	echo -e ""
fi

echo -n $routingLoadD2DRS " " 

((counter++))
done
