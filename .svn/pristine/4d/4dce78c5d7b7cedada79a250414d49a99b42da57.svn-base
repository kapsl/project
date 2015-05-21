#!/bin/bash
#
set terminal pdf
set output "RREQRREP1Sec.pdf"
set xtics ("1 UE" 1,"10 UEs" 7.5,"15 UEs" 15,"20 UEs" 22.5,"30UEs" 30);
set title "Relation RREQ-RREP";
set style line 1 lc rgb '#F5BF40' lt 1 lw 4 pt 1 pi -1 ps 0.5
set style line 2 lc rgb '#09FB25' lt 1 lw 4 pt 1 pi -1 ps 0.5
set pointintervalbox 2
set ylabel "Num of Packages"
set title "Relation RREQ-RREP with Sending Frequency 1Sec";
plot "RREQRREP1Sec.dat" using 1:2 title 'RREQTORS' with linespoints ls 1, "RREQRREP1Sec.dat" using 1:3 title 'RRESP' with linespoints ls 2;

