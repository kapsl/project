#!/bin/bash
#
set terminal pdf
set output "ReceivedPkts20Hosts.pdf"
set style histogram clustered gap 1 title textcolor lt -1
set style data histograms
set style fill transparent solid 0.5 
set grid
set xlabel "Sending Frequency in Seconds"
set ylabel "Received Packages %"
set title "Package Delivery Fraction with 20 Sending Hosts"
set yrange [0:100]
plot "RcvdPkts20Hosts.dat" using 3:xticlabels(1) title 'AODV' lc rgb"red", '' using 2 title 'D2DRS' lc rgb"orange";



