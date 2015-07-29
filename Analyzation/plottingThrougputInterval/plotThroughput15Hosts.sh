#!/bin/bash
#
set terminal pdf
set output "throughput15Hosts.pdf"
set title "Throughput (MBytes/sec) with 15 Sending UEs";
set xlabel "Sending Frequency in Seconds"
set ylabel "Sum Throughput"
set style histogram clustered gap 1 title textcolor lt -1
set style data histograms
set style fill transparent solid 0.5 
set grid
set yrange[0:10]
plot "throughput15Hosts.dat" using 2:xticlabels(1) title 'D2DRS' lc rgb"red", '' using 4 title 'AODV' lc rgb"orange";

