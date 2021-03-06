#!/bin/bash
#
set title "Relation RREQ - RREP with 30 Sending Hosts";
set xlabel "Packet Sending Frequency in Seconds"
set ylabel "Test"
set grid
set terminal pdf
set output "RREQRREP30Hosts.pdf"
set style histogram clustered gap 1 title textcolor lt -1
set style data histograms
set style fill transparent solid 0.5 
plot "RREQRREP30Hosts.dat" using 2:xticlabels(1) title 'RREQTORS' lc rgb"green", '' using 3 title 'RRESP' lc rgb"orange";

