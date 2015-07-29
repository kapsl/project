#!/bin/bash
#
set terminal pdf
set output "RREQRREP30Sec.pdf"
set style line 1 lc rgb '#F5BF40' lt 1 lw 4 pt 1 pi -1 ps 0.5
set style line 2 lc rgb '#09FB25' lt 1 lw 4 pt 1 pi -1 ps 0.5
set pointintervalbox 2
set xlabel "Num Sender and Receiver Pair"
set ylabel "Num of Packages"
set xtics ("1 UE" 1,"10 UEs" 7.5,"15 UEs" 15,"20 UEs" 22.5,"30UEs" 30);
set title "Relation RREQ-RREP with Sending Frequency 30Sec";
plot "RREQRREP30Sec.dat" using 1:2 title 'RREQTORS' with linespoints ls 1, "RREQRREP30Sec.dat" using 1:3 title 'RRESP' with linespoints ls 2;

