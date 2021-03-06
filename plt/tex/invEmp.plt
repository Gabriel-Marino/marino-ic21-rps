#   Print the inverse of empty spots density in logarithmic scale;
set terminal tikz fulldoc
set output "../../tex/invEmp.tex"

set key at graph 20,50 center Left samplen 1.0 width 1.0 spacing 1.25 
set size ratio 0.5
set decimalsign ","

set xlabel "Geração"
set xrange[1:10000]

set ylabel "$I_{e}^{-1}$"
set yrange[1:100]

set log xy

unset cbrange
unset cbtics
unset colorbox

plot    "../../dat/invEmp3.dat" u 1:2 w lp pt 5  lw 1 t"$\\mathcal{N}=3$",\
        "../../dat/invEmp4.dat" u 1:2 w lp pt 7  lw 1 t"$\\mathcal{N}=4$",\
        "../../dat/invEmp5.dat" u 1:2 w lp pt 13 lw 1 t"$\\mathcal{N}=5$"

unset output
unset terminal
