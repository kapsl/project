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
sumSentRREQD2DRS=0
sumSentRERRD2DRS=0
sumRceivedRREPD2DRS=0
sumLinkBreaksD2DRS=0
sumLinkBreacksAODV=0
sumSentRERRAODV=0
echo "30sec calculations General..."	
echo -e '#interval(sec)\tsumRREQGeneral\tsumRREPGeneral\tsumRERRGeneral\tsumLinkBreackD2DRS\tsumRERRAODV\tsumLinkBreakAODV' > RREQRREP${11}.dat;
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "Number Sent RREQs" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumSentRREQD2DRS=$(($sumSentRREQD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentRERRD2DRS=$(($sumSentRERRD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number Received RouteResponses" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRceivedRREPD2DRS=$(($sumRceivedRREPD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number of LinkBreaks" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumLinkBreaksD2DRS=$(($sumLinkBreaksD2DRS + $val))
fi
done < $1;
#
#
#AODV
#
sumLinkBreacksAODV=0
sumSentRERRAODV=0
val=0
echo "30sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentRERRAODV=$(($sumSentRERRAODV + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number of LinkBreaks" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumLinkBreacksAODV=$(($sumLinkBreacksAODV + $val))
fi
done < $6;
#
echo "RREQ sent General: "$sumSentRREQD2DRS
echo "RREP sent General: "$sumRceivedRREPD2DRS
echo "RERR sent General: " $sumSentRERRD2DRS
echo "RERR sent AODV: "$sumSentRERRAODV
echo "LinkBreacks General: " $sumLinkBreaksD2DRS
echo "LinkBreacksAODV: "$sumLinkBreacksAODV
echo -e "30\t"$sumSentRREQD2DRS'\t'$sumRceivedRREPD2DRS'\t'$sumSentRERRD2DRS'\t'$sumLinkBreaksD2DRS'\t'$sumSentRERRAODV'\t'$sumLinkBreacksAODV	 >> RREQRREP${11}.dat;
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
sumSentRREQD2DRS=0
sumSentRERRD2DRS=0
sumRceivedRREPD2DRS=0
sumLinkBreaksD2DRS=0
routingLoadAODV=0
echo "1sec calculations General..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "Number Sent RREQs" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumSentRREQD2DRS=$(($sumSentRREQD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentRERRD2DRS=$(($sumSentRERRD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number Received RouteResponses" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRceivedRREPD2DRS=$(($sumRceivedRREPD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number of LinkBreaks" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumLinkBreaksD2DRS=$(($sumLinkBreaksD2DRS + $val))
fi
done < $2;
#
#
#AODV
#
sumLinkBreacksAODV=0
sumSentRERRAODV=0
val=0
echo "1sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentRERRAODV=$(($sumSentRERRAODV + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number of LinkBreaks" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumLinkBreacksAODV=$(($sumLinkBreacksAODV + $val))
fi
done < $7;
#
echo "RREQ sent General: "$sumSentRREQD2DRS
echo "RREP sent General: "$sumRceivedRREPD2DRS
echo "RERR sent General: " $sumSentRERRD2DRS
echo "RERR sent AODV: "$sumSentRERRAODV
echo "LinkBreacks General: " $sumLinkBreaksD2DRS
echo "LinkBreacksAODV: "$sumLinkBreacksAODV
echo -e "1\t"$sumSentRREQD2DRS'\t'$sumRceivedRREPD2DRS'\t'$sumSentRERRD2DRS'\t'$sumLinkBreaksD2DRS'\t'$sumSentRERRAODV'\t'$sumLinkBreacksAODV	 >> RREQRREP${11}.dat;
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
sumSentRREQD2DRS=0
sumSentRERRD2DRS=0
sumRceivedRREPD2DRS=0
sumLinkBreaksD2DRS=0
routingLoadAODV=0
echo "0.1sec calculations General..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "Number Sent RREQs" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumSentRREQD2DRS=$(($sumSentRREQD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentRERRD2DRS=$(($sumSentRERRD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number Received RouteResponses" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRceivedRREPD2DRS=$(($sumRceivedRREPD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number of LinkBreaks" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumLinkBreaksD2DRS=$(($sumLinkBreaksD2DRS + $val))
fi
done < $3;
#
#
#AODV
#
sumLinkBreacksAODV=0
sumSentRERRAODV=0
val=0
echo "0.1sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentRERRAODV=$(($sumSentRERRAODV + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number of LinkBreaks" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumLinkBreacksAODV=$(($sumLinkBreacksAODV + $val))
fi
done < $8;
#
echo "RREQ sent General: "$sumSentRREQD2DRS
echo "RREP sent General: "$sumRceivedRREPD2DRS
echo "RERR sent General: " $sumSentRERRD2DRS
echo "RERR sent AODV: "$sumSentRERRAODV
echo "LinkBreacks General: " $sumLinkBreaksD2DRS
echo "LinkBreacksAODV: "$sumLinkBreacksAODV
echo -e "0.5\t"$sumSentRREQD2DRS'\t'$sumRceivedRREPD2DRS'\t'$sumSentRERRD2DRS'\t'$sumLinkBreaksD2DRS'\t'$sumSentRERRAODV'\t'$sumLinkBreacksAODV	 >> RREQRREP${11}.dat;
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
sumSentRREQD2DRS=0
sumSentRERRD2DRS=0
sumRceivedRREPD2DRS=0
sumLinkBreaksD2DRS=0
routingLoadAODV=0
echo "0.05sec calculations General..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "Number Sent RREQs" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumSentRREQD2DRS=$(($sumSentRREQD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentRERRD2DRS=$(($sumSentRERRD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number Received RouteResponses" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRceivedRREPD2DRS=$(($sumRceivedRREPD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number of LinkBreaks" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumLinkBreaksD2DRS=$(($sumLinkBreaksD2DRS + $val))
fi
done < $4;
#
#
#AODV
#
sumLinkBreacksAODV=0
sumSentRERRAODV=0
val=0
echo "0.05sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentRERRAODV=$(($sumSentRERRAODV + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number of LinkBreaks" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumLinkBreacksAODV=$(($sumLinkBreacksAODV + $val))
fi
done < $9;
#
echo "RREQ sent General: "$sumSentRREQD2DRS
echo "RREP sent General: "$sumRceivedRREPD2DRS
echo "RERR sent General: " $sumSentRERRD2DRS
echo "RERR sent AODV: "$sumSentRERRAODV
echo "LinkBreacks General: " $sumLinkBreaksD2DRS
echo "LinkBreacksAODV: "$sumLinkBreacksAODV
echo -e "0.1\t"$sumSentRREQD2DRS'\t'$sumRceivedRREPD2DRS'\t'$sumSentRERRD2DRS'\t'$sumLinkBreaksD2DRS'\t'$sumSentRERRAODV'\t'$sumLinkBreacksAODV	 >> RREQRREP${11}.dat;
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
sumSentRREQD2DRS=0
sumSentRERRD2DRS=0
sumRceivedRREPD2DRS=0
sumLinkBreaksD2DRS=0
routingLoadAODV=0
echo "0.05sec calculations General..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "Number Sent RREQs" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumSentRREQD2DRS=$(($sumSentRREQD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentRERRD2DRS=$(($sumSentRERRD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number Received RouteResponses" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRceivedRREPD2DRS=$(($sumRceivedRREPD2DRS + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number of LinkBreaks" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumLinkBreaksD2DRS=$(($sumLinkBreaksD2DRS + $val))
fi
done < $5;
#
#
#AODV
#
sumLinkBreacksAODV=0
sumSentRERRAODV=0
val=0
echo "0.05sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "RERRSent:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentRERRAODV=$(($sumSentRERRAODV + $val))
fi
if [[ $line =~ ^"scalar" && $line =~ "Number of LinkBreaks" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumLinkBreacksAODV=$(($sumLinkBreacksAODV + $val))
fi
done < ${10};
#
echo "RREQ sent General: "$sumSentRREQD2DRS
echo "RREP sent General: "$sumRceivedRREPD2DRS
echo "RERR sent General: " $sumSentRERRD2DRS
echo "RERR sent AODV: "$sumSentRERRAODV
echo "LinkBreacks General: " $sumLinkBreaksD2DRS
echo "LinkBreacksAODV: "$sumLinkBreacksAODV
echo -e "0.05\t"$sumSentRREQD2DRS'\t'$sumRceivedRREPD2DRS'\t'$sumSentRERRD2DRS'\t'$sumLinkBreaksD2DRS'\t'$sumSentRERRAODV'\t'$sumLinkBreacksAODV	 >> RREQRREP${11}.dat;

