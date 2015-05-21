#!/bin/bash
#
set terminal pdf
set output "plotRcvdColl05Sec.pdf"
set xtics ("1UEs" 1,"10UEs" 10, "15UE" 15,"20UEs" 20,"30UEs" 30);
set title "Collusion with Sending Frequency 0.5Sec";
set xlabel "Sum Collusion"
set ylabel "Sender and Receiver Pair"
plot "throughput05Sec.dat" using 1:3 title 'Collusion D2DRS' with lines linestyle 9,"throughput05Sec.dat" using 1:5 title 'Collusions AODV' with lines linestyle 5

