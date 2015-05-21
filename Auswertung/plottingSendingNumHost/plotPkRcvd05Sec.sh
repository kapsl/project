#!/bin/bash
#
set terminal pdf
set output "PkRcvd05Sec.pdf"
set xlabel "Number of Sender and Receiver Pair"
set ylabel "Received Packages %"
set xtics ("1 UE" 1,"10 UEs" 7.5,"15 UEs" 15,"20 UEs" 22.5,"30UEs" 30);
set title "Package Delivery Fraction Sending Interval 0.5Sec"
set yrange [0:100]
plot "RcvdPkts05Sec.dat" using 1:2 title 'D2DRS Network' with lines linestyle 7, "RcvdPkts05Sec.dat" using 1:3 title 'AODV Network' with lines linestyle 6


