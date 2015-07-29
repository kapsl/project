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
sumRcvdGeneral=0
sumRcvdCollusionGeneral=0
throughputGeneral=0
sumRcvdAODV=0
sumRcvdCollusionAODV=0
throughputAODV=0
val=0
i=0
#
echo "Throughput 30sec..."
echo -e "interval\tThroughputD2DRS\tCollD2DRS\troughputAODV\tCollAODV" > throughput${11}.dat
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdGeneral=$(($sumRcvdGeneral + $val))
if [ $val != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionGeneral=$(echo $val+$sumRcvdCollusionGeneral | bc -l)
fi
done < $1;
throughputGeneral=$(echo "scale=2;"$sumRcvdGeneral*"512"/"890"/$i/"1024"/1 | bc -l )
echo  "sum Rcvd packtes complete: "$sumRcvdGeneral
echo "sum Rcvd collutions: "$sumRcvdCollusionGeneral
echo "Throughput: "$throughputGeneral
#
#AODV
#
i=0
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdAODV=$(($sumRcvdAODV + $val))
if [ $val != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionAODV=$(echo $val+$sumRcvdCollusionAODV | bc -l)
fi
done < $6;
throughputAODV=$(echo "scale=2;"$sumRcvdAODV*"512"/"890"/$i/"1024"/1 | bc -l )
echo  "sum Rcvd packtes complete: "$sumRcvdAODV
echo "sum Rcvd collutions: "$sumRcvdCollusionAODV
echo "Throughput: "$throughputAODV
echo -e "30\t"$throughputGeneral"\t"$sumRcvdCollusionGeneral"\t"$throughputAODV"\t"$sumRcvdCollusionAODV >> throughput${11}.dat
#
####################################
##########1sec PacketLost##########
####################################
#
#General
#
sumRcvdGeneral=0
sumRcvdCollusionGeneral=0
throughputGeneral=0
sumRcvdAODV=0
sumRcvdCollusionAODV=0
throughputAODV=0
val=0
i=0
#
echo "Throughput 1sec..."
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdGeneral=$(($sumRcvdGeneral + $val))
if [ $val != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionGeneral=$(echo $val+$sumRcvdCollusionGeneral | bc -l)
fi
done < $2;
throughputGeneral=$(echo "scale=2;"$sumRcvdGeneral*"512"/"890"/$i/"1024"/1 | bc -l )
echo  "sum Rcvd packtes complete: "$sumRcvdGeneral
echo "sum Rcvd collutions: "$sumRcvdCollusionGeneral
echo "Throughput: "$throughputGeneral
#
#AODV
#
i=0
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdAODV=$(($sumRcvdAODV + $val))
if [ $val != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionAODV=$(echo $val+$sumRcvdCollusionAODV | bc -l)
fi
done < $7;
throughputAODV=$(echo "scale=2;"$sumRcvdAODV*"512"/"890"/$i/"1024"/1 | bc -l )
echo  "sum Rcvd packtes complete: "$sumRcvdAODV
echo "sum Rcvd collutions: "$sumRcvdCollusionAODV
echo "Throughput: "$throughputAODV
echo -e "1\t"$throughputGeneral"\t"$sumRcvdCollusionGeneral"\t"$throughputAODV"\t"$sumRcvdCollusionAODV >> throughput${11}.dat
#
####################################
##########0.1sec PacketLost##########
####################################
#
#General
#
sumRcvdGeneral=0
sumRcvdCollusionGeneral=0
throughputGeneral=0
sumRcvdAODV=0
sumRcvdCollusionAODV=0
throughputAODV=0
val=0
i=0
#
echo "Throughput 0.1sec..."
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdGeneral=$(($sumRcvdGeneral + $val))
if [ $val != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionGeneral=$(echo $val+$sumRcvdCollusionGeneral | bc -l)
fi
done < $3;
throughputGeneral=$(echo "scale=2;"$sumRcvdGeneral*"512"/"890"/$i/"1024"/1 | bc -l )
echo  "sum Rcvd packtes complete: "$sumRcvdGeneral
echo "sum Rcvd collutions: "$sumRcvdCollusionGeneral
echo "Throughput: "$throughputGeneral
#
#AODV
#
i=0
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdAODV=$(($sumRcvdAODV + $val))
if [ $val != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionAODV=$(echo $val+$sumRcvdCollusionAODV | bc -l)
fi
done < $8;
throughputAODV=$(echo "scale=2;"$sumRcvdAODV*"512"/"890"/$i/"1024"/1 | bc -l )
echo  "sum Rcvd packtes complete: "$sumRcvdAODV
echo "sum Rcvd collutions: "$sumRcvdCollusionAODV
echo "Throughput: "$throughputAODV
echo -e "0.5\t"$throughputGeneral"\t"$sumRcvdCollusionGeneral"\t"$throughputAODV"\t"$sumRcvdCollusionAODV >> throughput${11}.dat
#
####################################
##########0.05sec PacketLost##########
####################################
#
#General
#
sumRcvdGeneral=0
sumRcvdCollusionGeneral=0
throughputGeneral=0
sumRcvdAODV=0
sumRcvdCollusionAODV=0
throughputAODV=0
val=0
i=0
#
echo "Throughput 0.05sec..."
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdGeneral=$(($sumRcvdGeneral + $val))
if [ $val != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionGeneral=$(echo $val+$sumRcvdCollusionGeneral | bc -l)
fi
done < $4;
throughputGeneral=$(echo "scale=2;"$sumRcvdGeneral*"512"/"890"/$i/"1024"/1 | bc -l )
echo  "sum Rcvd packtes complete: "$sumRcvdGeneral
echo "sum Rcvd collutions: "$sumRcvdCollusionGeneral
echo "Throughput: "$throughputGeneral
#
#AODV
#
i=0
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdAODV=$(($sumRcvdAODV + $val))
if [ $val != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionAODV=$(echo $val+$sumRcvdCollusionAODV | bc -l)
fi
done < $9;
throughputAODV=$(echo "scale=2;"$sumRcvdAODV*"512"/"890"/$i/"1024"/1 | bc -l )
echo  "sum Rcvd packtes complete: "$sumSentAODV
echo "sum Rcvd collutions: "$sumRcvdCollusionAODV
echo "Throughput: "$throughputAODV
echo -e "0.1\t"$throughputGeneral"\t"$sumRcvdCollusionGeneral"\t"$throughputAODV"\t"$sumRcvdCollusionAODV >> throughput${11}.dat
#
####################################
##########0.05sec PacketLost##########
####################################
#
#General
#
sumRcvdGeneral=0
sumRcvdCollusionGeneral=0
throughputGeneral=0
sumRcvdAODV=0
sumRcvdCollusionAODV=0
throughputAODV=0
val=0
i=0
#
echo "Throughput 0.05sec..."
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdGeneral=$(($sumRcvdGeneral + $val))
if [ $val != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionGeneral=$(echo $val+$sumRcvdCollusionGeneral | bc -l)
fi
done < $5;
throughputGeneral=$(echo "scale=2;"$sumRcvdGeneral*"512"/"890"/$i/"1024"/1 | bc -l )
echo  "sum Rcvd packtes complete: "$sumRcvdGeneral
echo "sum Rcvd collutions: "$sumRcvdCollusionGeneral
echo "Throughput: "$throughputGeneral
#
#AODV
#
i=0
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdAODV=$(($sumRcvdAODV + $val))
if [ $val != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionAODV=$(echo $val+$sumRcvdCollusionAODV | bc -l)
fi
done < ${10};
throughputAODV=$(echo "scale=2;"$sumRcvdAODV*"512"/"890"/$i/"1024"/1 | bc -l )
echo  "sum Rcvd packtes complete: "$sumSentAODV
echo "sum Rcvd collutions: "$sumRcvdCollusionAODV
echo "Throughput: "$throughputAODV
echo -e "0.05\t"$throughputGeneral"\t"$sumRcvdCollusionGeneral"\t"$throughputAODV"\t"$sumRcvdCollusionAODV >> throughput${11}.dat

