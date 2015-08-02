#!/bin/bash
#
set terminal pdf
set output "plotRcvdColl01Sec.pdf"
set xtics ("1UEs" 1,"10UEs" 10, "15UE" 15,"20UEs" 20,"30UEs" 30);
set title "Collusion with Sending Frequency 0.1Sec";
set xlabel "Sum Collusion"
set ylabel "Sender and Receiver Pair"
plot "throughput01Sec.dat" using 1:3 title 'Collusion D2DRS' with lines linestyle 1,"throughput01Sec.dat" using 1:5 title 'Collusions AODV' with lines linestyle 2

