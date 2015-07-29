#!/bin/bash
#
set logscale x;
set xtics ("30sec" 30,"1sec" 1,"0.1sec" 0.1,"0.05sec" 0.05);
set title "Control Routing load per interval";
plot "Delay1Host.dat" using 1:2 title 'EndToEndGeneral' with lines linestyle 1, "Delay1Host.dat" using 1:3 title 'EndToEndAODV' with lines linestyle 2
set term postscript enhanced color
set output "Delay1Host.ps"
replot
set term x11
