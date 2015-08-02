#!/bin/bash
#
#
#
####################################
##########30sec PacketLost##########
####################################
#
#General
#
val=0
sumSentPayloadGeneral=0
sumSentAODVPktsGeneral=0
routingLoadD2DRS=0
routingLoadAODV=0
echo "30sec calculations General..."	
echo -e '#interval(sec)\t%RLGeneral\t%RLAODV\tPayloadD2DRS\tAODVAODV' > RoutingLoad${11}.dat;
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentPayloadGeneral=$(($sumSentPayloadGeneral + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "RREPSent:count" || $line =~ "RREQSent:count" || $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODVPktsGeneral=$(($sumSentAODVPktsGeneral + $val))
fi
done < $1;
#
#
#AODV
#
sumSentAODVPktsAODV=0
sumSentPayloadAODV=0
val=0
echo "30sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentPayloadAODV=$(($sumSentPayloadAODV + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "RREPSent:count" || $line =~ "RREQSent:count" || $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODVPktsAODV=$(($sumSentAODVPktsAODV + $val))
fi
done < $6;
#
tmpValueD2DRS=$(echo $sumSentPayloadGeneral+$sumSentAODVPktsGeneral | bc -l)
tmpValueD2DRS=$(echo 100/$tmpValueD2DRS | bc -l)
routingLoadD2DRS=$(echo "scale=2; "$tmpValueD2DRS*$sumSentAODVPktsGeneral/1 | bc -l)
echo $routingLoadD2DRS
tmpValueAODV=$(echo $sumSentPayloadAODV+$sumSentAODVPktsAODV | bc -l)
tmpValueAODV=$(echo 100/$tmpValueAODV | bc -l)
routingLoadAODV=$(echo "scale=2; "$tmpValueAODV*$sumSentAODVPktsAODV/1 | bc )
echo $routingLoadAODV
echo "Payload sent General: "$sumSentPayloadGeneral
echo "AODVPackets sent General: "$sumSentAODVPktsGeneral
echo "Payload sent AODV: " $sumSentPayloadAODV
echo "AODVPackets sent AODV: "$sumSentAODVPktsAODV
echo -e "30\t"$routingLoadD2DRS'\t'$routingLoadAODV'\t'$sumSentAODVPktsGeneral'\t'$sumSentAODVPktsAODV	 >> RoutingLoad${11}.dat;
#
#
#
####################################
##########1sec PacketLost##########
####################################
#
#General
#
val=0
sumSentPayloadGeneral=0
sumSentAODVPktsGeneral=0
routingLoadD2DRS=0
routingLoadAODV=0
echo "1sec calculations General..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentPayloadGeneral=$(($sumSentPayloadGeneral + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "RREPSent:count" || $line =~ "RREQSent:count" || $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODVPktsGeneral=$(($sumSentAODVPktsGeneral + $val))
fi
done < $2;
#
#
#AODV
#
sumSentAODVPktsAODV=0
sumSentPayloadAODV=0
val=0
echo "1sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentPayloadAODV=$(($sumSentPayloadAODV + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "RREPSent:count" || $line =~ "RREQSent:count" || $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODVPktsAODV=$(($sumSentAODVPktsAODV + $val))
fi
done < $7;
#
tmpValueD2DRS=$(echo $sumSentPayloadGeneral+$sumSentAODVPktsGeneral | bc -l)
tmpValueD2DRS=$(echo 100/$tmpValueD2DRS | bc -l)
routingLoadD2DRS=$(echo "scale=2; "$tmpValueD2DRS*$sumSentAODVPktsGeneral/1 | bc -l)
echo $routingLoadD2DRS
tmpValueAODV=$(echo $sumSentPayloadAODV+$sumSentAODVPktsAODV | bc -l)
tmpValueAODV=$(echo 100/$tmpValueAODV | bc -l)
routingLoadAODV=$(echo "scale=2; "$tmpValueAODV*$sumSentAODVPktsAODV/1 | bc )
echo $routingLoadAODV
echo "Payload sent General: "$sumSentPayloadGeneral
echo "AODVPackets sent General: "$sumSentAODVPktsGeneral
echo "Payload sent AODV: " $sumSentPayloadAODV
echo "AODVPackets sent AODV: "$sumSentAODVPktsAODV
echo -e "1\t"$routingLoadD2DRS'\t'$routingLoadAODV'\t'$sumSentAODVPktsGeneral'\t'$sumSentAODVPktsAODV	 >> RoutingLoad${11}.dat;
#
#
#
####################################
##########0.1sec PacketLost#########
####################################
#
#General
#
val=0
sumSentPayloadGeneral=0
sumSentAODVPktsGeneral=0
routingLoadD2DRS=0
routingLoadAODV=0
echo "0.1sec calculations General..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentPayloadGeneral=$(($sumSentPayloadGeneral + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "RREPSent:count" || $line =~ "RREQSent:count" || $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODVPktsGeneral=$(($sumSentAODVPktsGeneral + $val))
fi
done < $3;
#
#
#AODV
#
sumSentAODVPktsAODV=0
sumSentPayloadAODV=0
val=0
echo "0.1sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentPayloadAODV=$(($sumSentPayloadAODV + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "RREPSent:count" || $line =~ "RREQSent:count" || $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODVPktsAODV=$(($sumSentAODVPktsAODV + $val))
fi
done < $8;
#
tmpValueD2DRS=$(echo $sumSentPayloadGeneral+$sumSentAODVPktsGeneral | bc -l)
tmpValueD2DRS=$(echo 100/$tmpValueD2DRS | bc -l)
routingLoadD2DRS=$(echo "scale=2; "$tmpValueD2DRS*$sumSentAODVPktsGeneral/1 | bc -l)
echo $routingLoadD2DRS
tmpValueAODV=$(echo $sumSentPayloadAODV+$sumSentAODVPktsAODV | bc -l)
tmpValueAODV=$(echo 100/$tmpValueAODV | bc -l)
routingLoadAODV=$(echo "scale=2; "$tmpValueAODV*$sumSentAODVPktsAODV/1 | bc )
echo $routingLoadAODV
echo "Payload sent General: "$sumSentPayloadGeneral
echo "AODVPackets sent General: "$sumSentAODVPktsGeneral
echo "Payload sent AODV: " $sumSentPayloadAODV
echo "AODVPackets sent AODV: "$sumSentAODVPktsAODV
echo -e "0.5\t"$routingLoadD2DRS'\t'$routingLoadAODV'\t'$sumSentAODVPktsGeneral'\t'$sumSentAODVPktsAODV	 >> RoutingLoad${11}.dat;
#
#
#
####################################
##########0.05sec PacketLost#########
####################################
#
#General
#
val=0
sumSentPayloadGeneral=0
sumSentAODVPktsGeneral=0
routingLoadD2DRS=0
routingLoadAODV=0
echo "0.05sec calculations General..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentPayloadGeneral=$(($sumSentPayloadGeneral + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "RREPSent:count" || $line =~ "RREQSent:count" || $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODVPktsGeneral=$(($sumSentAODVPktsGeneral + $val))
fi
done < $4;
#
#
#AODV
#
sumSentAODVPktsAODV=0
sumSentPayloadAODV=0
val=0
echo "0.05sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentPayloadAODV=$(($sumSentPayloadAODV + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "RREPSent:count" || $line =~ "RREQSent:count" || $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODVPktsAODV=$(($sumSentAODVPktsAODV + $val))
fi
done < $9;
#
tmpValueD2DRS=$(echo $sumSentPayloadGeneral+$sumSentAODVPktsGeneral | bc -l)
tmpValueD2DRS=$(echo 100/$tmpValueD2DRS | bc -l)
routingLoadD2DRS=$(echo "scale=2; "$tmpValueD2DRS*$sumSentAODVPktsGeneral/1 | bc -l)
echo $routingLoadD2DRS
tmpValueAODV=$(echo $sumSentPayloadAODV+$sumSentAODVPktsAODV | bc -l)
tmpValueAODV=$(echo 100/$tmpValueAODV | bc -l)
routingLoadAODV=$(echo "scale=2; "$tmpValueAODV*$sumSentAODVPktsAODV/1 | bc )
echo $routingLoadAODV
echo "Payload sent General: "$sumSentPayloadGeneral
echo "AODVPackets sent General: "$sumSentAODVPktsGeneral
echo "Payload sent AODV: " $sumSentPayloadAODV
echo "AODVPackets sent AODV: "$sumSentAODVPktsAODV
echo -e "0.1\t"$routingLoadD2DRS'\t'$routingLoadAODV'\t'$sumSentAODVPktsGeneral'\t'$sumSentAODVPktsAODV	 >> RoutingLoad${11}.dat;
#
#
#
####################################
##########0.05sec PacketLost#########
####################################
#
#General
#
val=0
sumSentPayloadGeneral=0
sumSentAODVPktsGeneral=0
routingLoadD2DRS=0
routingLoadAODV=0
echo "0.05sec calculations General..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentPayloadGeneral=$(($sumSentPayloadGeneral + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "RREPSent:count" || $line =~ "RREQSent:count" || $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODVPktsGeneral=$(($sumSentAODVPktsGeneral + $val))
fi
done < $5;
#
#
#AODV
#
sumSentAODVPktsAODV=0
sumSentPayloadAODV=0
val=0
echo "0.05sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentPayloadAODV=$(($sumSentPayloadAODV + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "RREPSent:count" || $line =~ "RREQSent:count" || $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODVPktsAODV=$(($sumSentAODVPktsAODV + $val))
fi
done < ${10};
#
tmpValueD2DRS=$(echo $sumSentPayloadGeneral+$sumSentAODVPktsGeneral | bc -l)
tmpValueD2DRS=$(echo 100/$tmpValueD2DRS | bc -l)
routingLoadD2DRS=$(echo "scale=2; "$tmpValueD2DRS*$sumSentAODVPktsGeneral/1 | bc -l)
echo $routingLoadD2DRS
tmpValueAODV=$(echo $sumSentPayloadAODV+$sumSentAODVPktsAODV | bc -l)
tmpValueAODV=$(echo 100/$tmpValueAODV | bc -l)
routingLoadAODV=$(echo "scale=2; "$tmpValueAODV*$sumSentAODVPktsAODV/1 | bc )
echo $routingLoadAODV
echo "Payload sent General: "$sumSentPayloadGeneral
echo "AODVPackets sent General: "$sumSentAODVPktsGeneral
echo "Payload sent AODV: " $sumSentPayloadAODV
echo "AODVPackets sent AODV: "$sumSentAODVPktsAODV
echo -e "0.05\t"$routingLoadD2DRS'\t'$routingLoadAODV'\t'$sumSentAODVPktsGeneral'\t'$sumSentAODVPktsAODV	 >> RoutingLoad${11}.dat;

