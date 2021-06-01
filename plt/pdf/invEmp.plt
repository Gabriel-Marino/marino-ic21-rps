#   Print the inverse of empty spots density in logarithmic scale;
set terminal pdfcairo
set output "../../pdf/invEmp.pdf"

numSim = ARG1

set key at graph 20,50 center Left samplen 1.0 width 1.0 spacing 1.25 
set size ratio 0.5
set decimalsign ","

set xlabel "Geração"
set xrange[1:10000]

set ylabel "I_{e}^{-1}"
set yrange[1:100]

set log x
set log y

unset cbrange
unset cbtics
unset colorbox

plot    sprintf("../../dat/emp/invEmp-spiral-3-%d.dat", numSim) u 1:2 w lp pt 5  lw 1 ps 0.5 t"N=3",\
        sprintf("../../dat/emp/invEmp-spiral-4-%d.dat", numSim) u 1:2 w lp pt 7  lw 1 ps 0.5 t"N=4",\
        sprintf("../../dat/emp/invEmp-spiral-5-%d.dat", numSim) u 1:2 w lp pt 13 lw 1 ps 0.5 t"N=5"

unset output
unset terminal
