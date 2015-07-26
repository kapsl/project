#!/bin/bash

# Calculate Throughput in kbyte / s of a single host (middled over all hosts)

sumRcvdGeneral=0
throughputGeneral=0
val=0
i=0

echo "Calculating Throughput..."
#echo -e "interval\tThroughputD2DRS\tCollD2DRS\troughputAODV\tCollAODV"

while read line
do

# Total package count of payload packages
if [[ $line =~ ^"scalar" && $line =~ "udp" && $line =~ "rcvdPk:count" ]]
then
val=$(echo $line | cut -d ' ' -f 4- )
sumRcvdGeneral=$(($sumRcvdGeneral + $val))

# Nr. of senders that received / sent packages?!
if [ $val != "0" ]
then 
i=$(echo $i+1 | bc -l)
fi
fi

done < $1;

# *512 Message length of udp packages is 512 bytes
# :890 when we have 900s simulation time, the first 10 seconds are cut
# :i the number of sending, receiving hosts
# :1024 Bytes to Kilobytes
throughputGeneral=$(echo "scale=2;"$sumRcvdGeneral*"512"/"890"/$i/"1024"/1 | bc -l )

echo  "sum Rcvd packtes complete: "$sumRcvdGeneral
echo "Throughput: "$throughputGeneral
