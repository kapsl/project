#!/bin/bash
#
set terminal pdf
set xlabel "Packet Sending Frequency in Seconds"
set ylabel "Routingload in %"
set output "RoutingLoad10Hosts.pdf"
set title "Routingload per interval"
set style histogram clustered gap 1 title textcolor lt -1
set style data histograms
set style fill transparent solid 0.5 
set title "Routing Load with 10 Sending Hosts";
plot "RoutingLoad10Hosts.dat" using 2:xticlabels(1) title 'D2DRS' lc rgb"green", '' using 3 title 'AODV' lc rgb"blue";
