#!/bin/bash
#
set terminal pdf
set xlabel "Packet Sending Frequency in sec"
set ylabel "Delay in ms"
set output "Delay20Hosts.pdf"
set title "End To End Delay"
set style histogram clustered gap 1 title textcolor lt -1
set style data histograms
set style fill transparent solid 0.5 
set yrange [0:1]
set title "End To End Delay with 20 Sending Hosts";
plot "Delay20Hosts.dat" using 2:xticlabels(1) title 'D2DRS' lc rgb"green", '' using 3 title 'AODV' lc rgb"blue";
