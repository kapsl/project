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
sumSentGeneral=0
sumRcvdGeneral=0
sumLostGeneral=0
echo "30sec calculations General..."	
echo -e "#interval\t%RecievdD2DRS\t%ReveivdAODV\tSentD2DRS\tSentAODV" > RcvdPkts${11}.dat
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentGeneral=$(($sumSentGeneral + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdGeneral=$(($sumRcvdGeneral + $val))
fi
done < $1;
sumLostGeneral=$((100*$sumRcvdGeneral/$sumSentGeneral ))
#
#
#AODV
#
sumSentAODV=0
sumRcvdAODV=0
sumLostAODV=0
val=0
echo "30sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODV=$(($sumSentAODV + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdAODV=$(($sumRcvdAODV + $val))
fi
done < $6;
sumLostAODV=$(($sumRcvdAODV*100/$sumSentAODV))
#
echo "UDPPackets sent General: "$sumSentGeneral
echo "UDPPackets rcvd General: "$sumRcvdGeneral
echo "UDPPackets lost General: "$sumLostGeneral
echo "UDPPackets sent AODV: "$sumSentAODV
echo "UDPPackets rcvd AODV: "$sumRcvdAODV
echo "UDPPackets lost AODV: "$sumLostAODV
echo -e "30\t"$sumLostGeneral'\t'$sumLostAODV'\t'$sumSentGeneral'\t'$sumSentAODV >> RcvdPkts${11}.dat;
#
#
#
####################################
##########1sec PacketLost##########
####################################
#General
val=0
sumSentGeneral=0
sumRcvdGeneral=0
sumLostGeneral=0
echo "1sec calculations General..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentGeneral=$(($sumSentGeneral + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdGeneral=$(($sumRcvdGeneral + $val))
fi
done < $2;
sumLostGeneral=$((100*$sumRcvdGeneral/$sumSentGeneral ))
#
#
#AODV
#
sumSentAODV=0
sumRcvdAODV=0
sumLostAODV=0
val=0
echo "1sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODV=$(($sumSentAODV + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdAODV=$(( $sumRcvdAODV + $val))
fi
done < $7;
sumLostAODV=$(($sumRcvdAODV*100/$sumSentAODV))
echo "UDPPackets sent General: "$sumSentGeneral
echo "UDPPackets rcvd General: "$sumRcvdGeneral
echo "UDPPackets lost General: "$sumLostGeneral
echo "UDPPackets sent AODV: "$sumSentAODV
echo "UDPPackets rcvd AODV: "$sumRcvdAODV
echo "UDPPackets lost AODV: "$sumLostAODV
echo -e "1\t"$sumLostGeneral'\t'$sumLostAODV'\t'$sumSentGeneral'\t'$sumSentAODV >> RcvdPkts${11}.dat;
#
#
#
####################################
##########1sec PacketLost##########
####################################
#General
val=0
sumSentGeneral=0
sumRcvdGeneral=0
sumLostGeneral=0
echo "1sec calculations General..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentGeneral=$(($sumSentGeneral + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdGeneral=$(($sumRcvdGeneral + $val))
fi
done < $3;
sumLostGeneral=$((100*$sumRcvdGeneral/$sumSentGeneral ))
#
#
#AODV
#
sumSentAODV=0
sumRcvdAODV=0
sumLostAODV=0
val=0
echo "1sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODV=$(($sumSentAODV + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdAODV=$(( $sumRcvdAODV + $val))
fi
done < $8;
sumLostAODV=$(($sumRcvdAODV*100/$sumSentAODV))
echo "UDPPackets sent General: "$sumSentGeneral
echo "UDPPackets rcvd General: "$sumRcvdGeneral
echo "UDPPackets lost General: "$sumLostGeneral
echo "UDPPackets sent AODV: "$sumSentAODV
echo "UDPPackets rcvd AODV: "$sumRcvdAODV
echo "UDPPackets lost AODV: "$sumLostAODV
echo -e "0.5\t"$sumLostGeneral'\t'$sumLostAODV'\t'$sumSentGeneral'\t'$sumSentAODV >> RcvdPkts${11}.dat;
#
#
#
####################################
##########0.1sec PacketLost#########
####################################
val=0
sumSentGeneral=0
sumRcvdGeneral=0
sumLostGeneral=0
echo "0.1sec calculations General..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentGeneral=$(($sumSentGeneral + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdGeneral=$(($sumRcvdGeneral + $val))
fi
done < $4;
sumLostGeneral=$((100*$sumRcvdGeneral/$sumSentGeneral ))
#
#
#AODV
#
sumSentAODV=0
sumRcvdAODV=0
sumLostAODV=0
val=0
echo "0.1sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODV=$(($sumSentAODV + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdAODV=$(($sumRcvdAODV + $val))
fi
done < $9;
sumLostAODV=$(($sumRcvdAODV*100/$sumSentAODV))
echo "UDPPackets sent General: "$sumSentGeneral
echo "UDPPackets rcvd General: "$sumRcvdGeneral
echo "UDPPackets lost General: "$sumLostGeneral
echo "UDPPackets sent AODV: "$sumSentAODV
echo "UDPPackets rcvd AODV: "$sumRcvdAODV
echo "UDPPackets lost AODV: "$sumLostAODV
echo -e "0.1\t"$sumLostGeneral'\t'$sumLostAODV'\t'$sumSentGeneral'\t'$sumSentAODV >> RcvdPkts${11}.dat;
#
#
#
####################################
##########0.05sec PacketLost#########
####################################
#General
val=0
sumSentGeneral=0
sumRcvdGeneral=0
sumLostGeneral=0
echo "0.05sec calculations..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentGeneral=$(($sumSentGeneral + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdGeneral=$(($sumRcvdGeneral + $val))
fi
done < $5;
sumLostGeneral=$((100*$sumRcvdGeneral/$sumSentGeneral ))
#
#
#AODV
#
sumSentAODV=0
sumRcvdAODV=0
sumLostAODV=0
val=0
echo "0.05sec calculations AODV..."	
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "sentPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumSentAODV=$(($sumSentAODV + $val))
val=0
fi
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdAODV=$(($sumRcvdAODV + $val))
fi
done < ${10};
sumLostAODV=$(($sumRcvdAODV*100/$sumSentAODV))
echo "UDPPackets sent General: "$sumSentGeneral
echo "UDPPackets rcvd General: "$sumRcvdGeneral
echo "UDPPackets lost General: "$sumLostGeneral
echo "UDPPackets sent AODV: "$sumSentAODV
echo "UDPPackets rcvd AODV: "$sumRcvdAODV
echo "UDPPackets lost AODV: "$sumLostAODV
echo -e "0.05\t"$sumLostGeneral'\t'$sumLostAODV'\t'$sumSentGeneral'\t'$sumSentAODV >> RcvdPkts${11}.dat;

