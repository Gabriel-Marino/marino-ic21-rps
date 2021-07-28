set terminal pdfcairo
set output "dft.pdf"

set decimalsign ","

unset xtics
unset ytics

set multiplot layout 2,3

plot "../dat/dft/1-cos.dat" u 1:3 w lp pt -1 lc rgb "red"   lw 1 ps 0.2 t""
plot "../dat/dft/2-cos.dat" u 1:3 w lp pt -1 lc rgb "green" lw 1 ps 0.2 t""
plot "../dat/dft/3-cos.dat" u 1:3 w lp pt -1 lc rgb "blue"  lw 1 ps 0.2 t""

set xrange[0:100]
set xtics 50

set yrange[0:0.01]
set ytics 0.01

plot "../dat/dft/dft-1-cos.dat"   w lp pt 3  lc rgb "green" lw 1 ps 0.2 t""
plot "../dat/dft/dft-2-cos.dat"   w lp pt 3 lc rgb "blue"   lw 1 ps 0.2 t""
plot "../dat/dft/dft-3-cos.dat"   w lp pt 3 lc  rgb "red"   lw 1 ps 0.2 t""

unset multiplot
unset output
unset terminal
