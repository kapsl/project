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
sumDelayGeneral=0
meanDelayGeneral=0
sumstdevGeneral=0
meanstdevGeneral=0
#
sumDelayAODV=0
meanDelayAODV=0
sumstdevAODV=0
meanstdevAODV=0
i=0
echo "30sec calculations General..."
echo -e "#interval(sec)\tmeanDelayGeneral\tmeanDelayAODV"> Delay${11}.dat
while read line
do 
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
numHost=$(echo $line | cut -d ' ' -f 4- )
if [ $numHost != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"statistic" && $line =~ "udpApp" && $line =~ "endToEndDelay:histogram" ]]
then
read line
read line
val=$(echo $line | cut -d ' ' -f 3- )
sumDelayGeneral=$(echo "scale=10;"$sumDelayGeneral+$val | bc -l)
fi
done < $1;
meanDelayGeneral=$(echo "scale=10;"$sumDelayGeneral/$i | bc -l)
echo "calculated mean delay General :"$meanDelayGeneral
#
#
#AODV
#
i=0
echo "30sec calculations AODV..."	
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
numHost=$(echo $line | cut -d ' ' -f 4- )
if [ $numHost != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi 
if [[ $line =~ ^"statistic" && $line =~ "udpApp" && $line =~ "endToEndDelay:histogram" ]]
then
read line
read line
val=$(echo $line | cut -d ' ' -f 3- )
sumDelayAODV=$(echo "scale=10;"$sumDelayAODV+$val | bc -l)
fi
done < $6;
meanDelayAODV=$(echo "scale=10;"$sumDelayAODV/$i | bc -l)
echo "calculated mean delay AODV :" $meanDelayAODV
echo -e "30\t"$meanDelayGeneral"\t"$meanDelayAODV >> Delay${11}.dat
#
####################################
##########1sec PacketLost##########
####################################
#
#General
#
val=0
sumDelayGeneral=0
meanDelayGeneral=0
sumstdevGeneral=0
meanstdevGeneral=0
#
sumDelayAODV=0
meanDelayAODV=0
sumstdevAODV=0
meanstdevAODV=0
i=0
echo "1sec calculations General..."
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
numHost=$(echo $line | cut -d ' ' -f 4- )
if [ $numHost != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi 
if [[ $line =~ ^"statistic" && $line =~ "udpApp" && $line =~ "endToEndDelay:histogram" ]]
then
read line
read line
val=$(echo $line | cut -d ' ' -f 3- )
sumDelayGeneral=$(echo "scale=10;"$sumDelayGeneral+$val | bc -l)
fi
done < $2;
meanDelayGeneral=$(echo "scale=10;"$sumDelayGeneral/$i | bc -l)
echo "calculated mean delay General :"$meanDelayGeneral
#
#
#AODV
#
i=0
echo "1sec calculations AODV..."	
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
numHost=$(echo $line | cut -d ' ' -f 4- )
if [ $numHost != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi 
if [[ $line =~ ^"statistic" && $line =~ "udpApp" && $line =~ "endToEndDelay:histogram" ]]
then
read line
read line
val=$(echo $line | cut -d ' ' -f 3- )
sumDelayAODV=$(echo "scale=10;"$sumDelayAODV+$val | bc -l)
fi
done < $7;
meanDelayAODV=$(echo "scale=10;"$sumDelayAODV/$i | bc -l)
echo "calculated mean delay AODV :" $meanDelayAODV
echo -e "1\t"$meanDelayGeneral"\t"$meanDelayAODV >> Delay${11}.dat
#
####################################
##########0.1sec PacketLost##########
####################################
#
#General
#
val=0
sumDelayGeneral=0
meanDelayGeneral=0
sumstdevGeneral=0
meanstdevGeneral=0
#
sumDelayAODV=0
meanDelayAODV=0
sumstdevAODV=0
meanstdevAODV=0
i=0
echo "0.5sec calculations General..."
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
numHost=$(echo $line | cut -d ' ' -f 4- )
if [ $numHost != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"statistic" && $line =~ "udpApp" && $line =~ "endToEndDelay:histogram" ]]
then
read line
read line
val=$(echo $line | cut -d ' ' -f 3- )
sumDelayGeneral=$(echo "scale=10;"$sumDelayGeneral+$val | bc -l)
fi
done < $3;
meanDelayGeneral=$(echo "scale=10;"$sumDelayGeneral/$i | bc -l)
echo "calculated mean delay General :"$meanDelayGeneral
#
#
#AODV
#
i=0
echo "0.5sec calculations AODV..."	
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
numHost=$(echo $line | cut -d ' ' -f 4- )
if [ $numHost != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"statistic" && $line =~ "udpApp" && $line =~ "endToEndDelay:histogram" ]]
then
read line
read line
val=$(echo $line | cut -d ' ' -f 3- )
sumDelayAODV=$(echo "scale=10;"$sumDelayAODV+$val | bc -l)
fi
done < $8;
meanDelayAODV=$(echo "scale=10;"$sumDelayAODV/$i | bc -l)
echo "calculated mean delay AODV :" $meanDelayAODV
echo -e "0.5\t"$meanDelayGeneral"\t"$meanDelayAODV >> Delay${11}.dat
#
####################################
##########0.05sec PacketLost########
####################################
#
#General
#
val=0
sumDelayGeneral=0
meanDelayGeneral=0
sumstdevGeneral=0
meanstdevGeneral=0
#
sumDelayAODV=0
meanDelayAODV=0
sumstdevAODV=0
meanstdevAODV=0
i=0
echo "0.1sec calculations General..."
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
numHost=$(echo $line | cut -d ' ' -f 4- )
if [ $numHost != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"statistic" && $line =~ "udpApp" && $line =~ "endToEndDelay:histogram" ]]
then
read line
read line
val=$(echo $line | cut -d ' ' -f 3- )
sumDelayGeneral=$(echo "scale=10;"$sumDelayGeneral+$val | bc -l)
fi
done < $4;
meanDelayGeneral=$(echo "scale=10;"$sumDelayGeneral/$i | bc -l)
echo "calculated mean delay General :"$meanDelayGeneral
#
#
#AODV
#
i=0
echo "0.1sec calculations AODV..."	
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
numHost=$(echo $line | cut -d ' ' -f 4- )
if [ $numHost != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi 
if [[ $line =~ ^"statistic" && $line =~ "udpApp" && $line =~ "endToEndDelay:histogram" ]]
then
read line
read line
val=$(echo $line | cut -d ' ' -f 3- )
sumDelayAODV=$(echo "scale=10;"$sumDelayAODV+$val | bc -l)
fi
done < $9;
meanDelayAODV=$(echo "scale=10;"$sumDelayAODV/$i | bc -l)
echo "calculated mean delay AODV :" $meanDelayAODV
echo -e "0.1\t"$meanDelayGeneral"\t"$meanDelayAODV >> Delay${11}.dat
#
####################################
##########0.05sec PacketLost########
####################################
#
#General
#
val=0
sumDelayGeneral=0
meanDelayGeneral=0
sumstdevGeneral=0
meanstdevGeneral=0
#
sumDelayAODV=0
meanDelayAODV=0
sumstdevAODV=0
meanstdevAODV=0
i=0
echo "0.05sec calculations General..."
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
numHost=$(echo $line | cut -d ' ' -f 4- )
if [ $numHost != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi
if [[ $line =~ ^"statistic" && $line =~ "udpApp" && $line =~ "endToEndDelay:histogram" ]]
then
read line
read line
val=$(echo $line | cut -d ' ' -f 3- )
sumDelayGeneral=$(echo "scale=10;"$sumDelayGeneral+$val | bc -l)
fi
done < $5;
meanDelayGeneral=$(echo "scale=10;"$sumDelayGeneral/$i | bc -l)
echo "calculated mean delay General :"$meanDelayGeneral
#
#
#AODV
#
i=0
echo "0.05sec calculations AODV..."	
while read line
do
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
numHost=$(echo $line | cut -d ' ' -f 4- )
if [ $numHost != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi 
if [[ $line =~ ^"statistic" && $line =~ "udpApp" && $line =~ "endToEndDelay:histogram" ]]
then
read line
read line
val=$(echo $line | cut -d ' ' -f 3- )
sumDelayAODV=$(echo "scale=10;"$sumDelayAODV+$val | bc -l)
fi
done < ${10};
meanDelayAODV=$(echo "scale=10;"$sumDelayAODV/$i | bc -l)
echo "calculated mean delay AODV :" $meanDelayAODV
echo -e "0.05\t"$meanDelayGeneral"\t"$meanDelayAODV >> Delay${11}.dat
