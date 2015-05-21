#!/bin/bash
#
set terminal pdf
set output "RoutingLoad1Sec.pdf"
set xtics ("1 UE" 1,"10 UEs" 7.5,"15 UEs" 15,"20 UEs" 22.5,"30UEs" 30);
set style line 1 lc rgb '#F5BF40' lt 1 lw 4 pt 1 pi -1 ps 0.5
set style line 2 lc rgb '#09FB25' lt 1 lw 4 pt 1 pi -1 ps 0.5
set pointintervalbox 2
set xlabel "Num Sender and Receiver Pair"
set ylabel "Num of Packages"
set title "Routing Load with Sending Frequency 1Sec";
plot "RoutingLoad1Sec.dat" using 1:2 title 'D2DRS Routing Load' with linespoints ls 1, "RoutingLoad1Sec.dat" using 1:3 title 'AODV Routing Load' with linespoints ls 2;

