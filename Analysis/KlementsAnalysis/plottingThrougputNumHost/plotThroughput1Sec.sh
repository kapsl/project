#!/bin/bash
#
set terminal pdf
set output "plotThroughput1Sec.pdf"
set xtics ("1UEs" 1,"10UEs" 10,"20UEs" 20,"30UEs" 30);
set title "Throughput (Mbytes/sec) Sending Frequency 1Sec";
set xlabel "Sender and Receiver Pair"
set ylabel "Throughput MB"
set yrange[0:10]
plot "throughput1Sec.dat" using 1:2 title 'D2DRS Network' with lines linestyle 1, "throughput1Sec.dat" using 1:4 title 'AODV Network' with lines linestyle 2

