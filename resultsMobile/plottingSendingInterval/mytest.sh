val=0
sumSentGeneral=0
sumRcvdGeneral=0
sumLostGeneral=0

echo "1sec calculations General..."	

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

done < $1;

sumLostGeneral=$((100*$sumRcvdGeneral/$sumSentGeneral ))

echo "UDPPackets sent General: "$sumSentGeneral
echo "UDPPackets rcvd General: "$sumRcvdGeneral
echo "UDPPackets lost General: "$sumLostGeneral
