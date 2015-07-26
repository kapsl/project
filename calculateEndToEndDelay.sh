#!/bin/bash

# TODO comments und aufhübschen

counter=0

echo "Calculate End to End delay..."

for filename in `ls -1v $1*.sca`
do

val=0
sumDelayGeneral=0
meanDelayGeneral=0
sumstdevGeneral=0
meanstdevGeneral=0
i=0

while read line
do 

if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
numHost=$(echo $line | cut -d ' ' -f 4- )

# If host received packages, i++
if [ $numHost != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi

fi

if [[ $line =~ ^"statistic" && $line =~ "udpApp" && $line =~ "endToEndDelay:histogram" ]]
then
read line
read line

# Get mean of end to end delay for this host
val=$(echo $line | cut -d ' ' -f 3- )
sumDelayGeneral=$(echo "scale=10;"$sumDelayGeneral+$val | bc -l)
fi

done < $filename;

# Sum of delays / nr. of receiving hosts
meanDelayGeneral=$(echo "scale=10;"$sumDelayGeneral/$i | bc -l)

#echo "calculated mean delay General :"$meanDelayGeneral

#echo -e "30\t"$meanDelayGeneral"\t"$meanDelayAODV

if [ $(($counter%3)) == 0 ] 
then
	echo -e ""
fi

echo -n $meanDelayGeneral " " 

((counter++))
done
