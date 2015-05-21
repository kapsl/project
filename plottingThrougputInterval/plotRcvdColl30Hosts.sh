#!/bin/bash
#
set terminal pdf
set output "rcvdColl30Hosts.pdf"
set xlabel "Sending Frequency in Seconds"
set ylabel "Number of Collusion"
set title "Collusion 30 Sending UEs";
set style histogram clustered gap 1 title textcolor lt -1
set style data histograms
set style fill transparent solid 0.5 
set grid
plot "throughput30Hosts.dat" using 5:xticlabels(1) title 'AODV' lc rgb"red", '' using 3 title 'D2DRS' lc rgb"green";
