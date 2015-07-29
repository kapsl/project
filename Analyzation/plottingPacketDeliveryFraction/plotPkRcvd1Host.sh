#!/bin/bash
#
set terminal pdf
set output "ReceivedPkts1Host.pdf"
set title "Package Delivery Fraction with 1 Sending Host"
set xlabel "Sending Frequency in Seconds"
set ylabel "Received Packages %"
set style histogram clustered gap 1 title textcolor lt -1
set style data histograms
set style fill transparent solid 0.5 
set grid
set yrange [0:100]
plot "RcvdPkts1Host.dat" using 3:xticlabels(1) title 'AODV' lc rgb"red", '' using 2 title 'D2DRS' lc rgb"orange";




