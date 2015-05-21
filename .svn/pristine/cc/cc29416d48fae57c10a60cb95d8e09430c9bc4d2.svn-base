#!/bin/bash
#
#
#
####################################
###############1 Host###############
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
echo -e "interval\tThroughputD2DRS\tCollD2DRS\tThroughputAODV\tCollAODV" > throughput${11}.dat
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdGeneral=$(($sumRcvdGeneral + $val))
if [ $val != "0" ]
then 
i=$(echo $i+1 | bc -l)
echo $i
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionGeneral=$(echo $val+$sumRcvdCollusionGeneral | bc -l)
fi
done < $1;
throughputGeneral=$(echo $sumRcvdGeneral*"512"/"890"/$i/"1024" | bc -l )
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
echo $i
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionAODV=$(echo $val+$sumRcvdCollusionAODV | bc -l)
fi
done < $6;
throughputAODV=$(echo $sumRcvdAODV*"512"/"890"/$i/"1024" | bc -l )
echo  "sum Rcvd packtes complete: "$sumRcvdAODV
echo "sum Rcvd collutions: "$sumRcvdCollusionAODV
echo "Throughput: "$throughputAODV
echo -e "1\t"$throughputGeneral"\t"$sumRcvdCollusionGeneral"\t"$throughputAODV"\t"$sumRcvdCollusionAODV >> throughput${11}.dat
#
####################################
##############10 Hosts##############
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
echo $i
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionGeneral=$(echo $val+$sumRcvdCollusionGeneral | bc -l)
fi
done < $2;
throughputGeneral=$(echo $sumRcvdGeneral*"512"/"890"/$i/"1024" | bc -l )
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
echo $i
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionAODV=$(echo $val+$sumRcvdCollusionAODV | bc -l)
fi
done < $7;
throughputAODV=$(echo $sumRcvdAODV*"512"/"890"/$i/"1024" | bc -l )
echo  "sum Rcvd packtes complete: "$sumRcvdAODV
echo "sum Rcvd collutions: "$sumRcvdCollusionAODV
echo "Throughput: "$throughputAODV
echo -e "7.5\t"$throughputGeneral"\t"$sumRcvdCollusionGeneral"\t"$throughputAODV"\t"$sumRcvdCollusionAODV >> throughput${11}.dat
#
####################################
##############20 Hosts##############
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
echo $i
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionGeneral=$(echo $val+$sumRcvdCollusionGeneral | bc -l)
fi
done < $3;
throughputGeneral=$(echo $sumRcvdGeneral*"512"/"890"/$i/"1024" | bc -l )
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
echo $i
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionAODV=$(echo $val+$sumRcvdCollusionAODV | bc -l)
fi
done < $8;
throughputAODV=$(echo $sumRcvdAODV*"512"/"890"/$i/"1024" | bc -l )
echo  "sum Rcvd packtes complete: "$sumRcvdAODV
echo "sum Rcvd collutions: "$sumRcvdCollusionAODV
echo "Throughput: "$throughputAODV
echo -e "15\t"$throughputGeneral"\t"$sumRcvdCollusionGeneral"\t"$throughputAODV"\t"$sumRcvdCollusionAODV >> throughput${11}.dat
#
####################################
##############20 Hosts##############
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
echo $i
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionGeneral=$(echo $val+$sumRcvdCollusionGeneral | bc -l)
fi
done < $4;
throughputGeneral=$(echo $sumRcvdGeneral*"512"/"890"/$i/"1024" | bc -l )
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
echo $i
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionAODV=$(echo $val+$sumRcvdCollusionAODV | bc -l)
fi
done < $9;
throughputAODV=$(echo $sumRcvdAODV*"512"/"890"/$i/"1024" | bc -l )
echo  "sum Rcvd packtes complete: "$sumRcvdAODV
echo "sum Rcvd collutions: "$sumRcvdCollusionAODV
echo "Throughput: "$throughputAODV
echo -e "22.5\t"$throughputGeneral"\t"$sumRcvdCollusionGeneral"\t"$throughputAODV"\t"$sumRcvdCollusionAODV >> throughput${11}.dat
#
####################################
##############30 Hosts##############
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
echo $i
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionGeneral=$(echo $val+$sumRcvdCollusionGeneral | bc -l)
fi
done < $5;
throughputGeneral=$(echo $sumRcvdGeneral*"512"/"890"/$i/"1024" | bc -l )
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
echo $i
fi
fi
if [[ $line =~ ^"scalar" && $line =~ "mac" && $line =~ "number of collisions" ]]
then
val=$(echo $line | cut -d ' ' -f 6- )
sumRcvdCollusionAODV=$(echo $val+$sumRcvdCollusionAODV | bc -l)
fi
done < ${10};
throughputAODV=$(echo $sumRcvdAODV*"512"/"890"/$i/"1024" | bc -l )
echo  "sum Rcvd packtes complete: "$sumSentAODV
echo "sum Rcvd collutions: "$sumRcvdCollusionAODV
echo "Throughput: "$throughputAODV
echo -e "30\t"$throughputGeneral"\t"$sumRcvdCollusionGeneral"\t"$throughputAODV"\t"$sumRcvdCollusionAODV >> throughput${11}.dat


