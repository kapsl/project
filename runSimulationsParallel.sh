#!/bin/bash
#

# First parameter tells if d2drs or aodv should be simulated. -d for d2drs -a for aodv -ad for both
# Second parameter gives first border of run nr., third gives second
# eg ./runSimulationParallel.sh -ad 60 120 will run the omnetpp run nrs. 60 to 120 parallel

echo "Running Simulations ..."

# Run D2DRS Simulations
if [[ $1 =~ "d" ]] 
then
echo "Running D2DRS Simulations..."

for ((i = $2; i < $3; i++))
do
	./NetworkStructures -r $i -u Cmdenv -c General -n .:../inet/examples:../inet/src -l ../inet/src/inet omnetpp.ini &
done

echo "D2DRS Simulations finished..."
fi

# Run AODV Simulations
if [[ $1 =~ "a" ]] 
then
echo "Running AODV Simulations..."

for ((i = $2; i < $3; i++))
do
	./NetworkStructures -r $i -u Cmdenv -c AODVNetwork -n .:../inet/examples:../inet/src -l ../inet/src/inet omnetpp.ini &
done

echo "AODV Simulations finished..."
fi


wait

echo "All Simulations finished"
