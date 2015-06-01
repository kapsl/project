#!/bin/bash
#

echo "Running Simulations ..."

for ((i = 0; i < 60; i++))
do
	./NetworkStructures -r $i -u Cmdenv -n .:../inet/examples:../inet/src -l ../inet/src/inet omnetpp.ini &
done 

wait

echo "All Simulations finished"
