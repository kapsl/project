#!/bin/bash
#

# First parameter gives first border, second gives second
# The String AODVNetwork is, when the AODV Simulation should run

echo "Running Simulations ..."

for ((i = $1; i < $2; i++))
do
	./NetworkStructures -r $i -u Cmdenv -n AODVNetwork .:../inet/examples:../inet/src -l ../inet/src/inet omnetpp.ini &
done 

wait

echo "All Simulations finished"
