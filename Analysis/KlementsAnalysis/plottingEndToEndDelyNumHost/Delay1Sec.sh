#!/bin/bash
#
set terminal pdf
set output "Delay1Sec.pdf"
set xtics ("1UEs" 1,"10UEs" 7.5,"15UEs" 15,"20UEs" 22.5,"30UEs" 30);
set title "End to End Delay with Sending Frequency 1Sec";
set xlabel "Number of Sender and Receiver Pair"
set ylabel " Delay in ms"
set yrange [0:0.1]
plot "Delay1Sec.dat" using 1:2 title 'D2DRS Network' with lines linestyle 1, "Delay1Sec.dat" using 1:3 title 'AODV Network' with lines linestyle 2

