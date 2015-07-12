#!/bin/bash
#

val=0
sumSentGeneral=0
sumRcvdGeneral=0
sumLostGeneral=100
counter=0

echo "Calculating packet loss..."	

for filename in `ls -1v $1*.sca`
do

sumSentGeneral=0
sumRcvdGeneral=0
val=0

while read line
do 

#echo -e "$line \n"

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

done < $filename

if [ $sumSentGeneral == 0 ]
then
	sumLostGeneral=100
else
	sumLostGeneral=$((100*$sumRcvdGeneral/$sumSentGeneral ))
fi

#echo $filename
#echo "UDPPackets sent: "$sumSentGeneral
#echo "UDPPackets received: "$sumRcvdGeneral
#echo "UDPPackets lost: " $((100 - $sumLostGeneral))
#echo -e "\n"

#echo -n $((100 - $sumLostGeneral)) " "

if [ $(($counter%3)) == 0 ] 
then
	echo -e ""
fi

echo -n $((100 - $sumLostGeneral)) " "

((counter++))
done
