#!/bin/bash
#
set terminal pdf
set output "PkRcvd1Sec.pdf"
set xlabel "Number of Sender and Receiver Pair"
set ylabel "Received Packages %"
set xtics ("1 UE" 1,"10 UEs" 7.5,"15 UEs" 15,"20 UEs" 22.5,"30UEs" 30);
set title "Package Delivery Fraction Sending Interval 1Sec"
set style line 1 lt 2 lw 2 pt 3 ps 0.5
set yrange [0:100]
plot "RcvdPkts1Sec.dat" using 1:2 title 'D2DRS Network' ls 1, "RcvdPkts1Sec.dat" using 1:3 title 'AODV Network' with lines linestyle 3


