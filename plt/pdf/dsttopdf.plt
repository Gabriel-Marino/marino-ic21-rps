#   Print the density of species;
set terminal pdfcairo #size 1280,800
set output "../../pdf/dst3.pdf"

numSim = ARG1

set size ratio 0.5

set xlabel "Geração"
set xrange[0:5000]
set xtics 1000

set ylabel "Densidade"
set yrange[0:0.5]
set ytics 0.1

set cbrange [0:3]
unset cbtics
unset colorbox

set palette defined (0 "#000000",\
                     1 "#FF0000",\
                     2 "#0000FF",\
                     3 "#FFFF00")

plot for [i=1:4] sprintf("../../dat/dst/dst-spiral-3-%d.dat", numSim) u 1:i+1 w l lw 1 lc palette cb (i-1) t"Espécie ".(i-1)

unset output
unset terminal

#   Print the density of species;
set terminal pdfcairo #size 1280,800
set output "../../pdf/dst4.pdf"

set size ratio 0.5

set xlabel "Geração"
set xrange[0:5000]
set xtics 1000

set ylabel "Densidade"
set yrange[0:0.5]
set ytics 0.1

set cbrange [0:4]
unset cbtics
unset colorbox

set palette defined (0 "#000000",\
                     1 "#FF0000",\
                     2 "#0000FF",\
                     3 "#FFFF00",\
                     4 "#FF00FF")

plot for [i=1:5] sprintf("../../dat/dst/dst-spiral-4-%d.dat", numSim) u 1:i+1 w l lw 1 lc palette cb (i-1) t"Espécie ".(i-1)

unset output
unset terminal

#   Print the density of species;
set terminal pdfcairo #size 1280,800
set output "../../pdf/dst5.pdf"

set size ratio 0.5

set xlabel "Geração"
set xrange[0:5000]
set xtics 1000

set ylabel "Densidade"
set yrange[0:0.5]
set ytics 0.1

set cbrange [0:5]
unset cbtics
unset colorbox

set palette defined ( 0 "#000000",\
                     1 "#FF0000",\
                     2 "#0000FF",\
                     3 "#FFFF00",\
                     4 "#FF00FF",\
                     5 "#00FFFF")

plot for [i=1:6] sprintf("../../dat/dst/dst-spiral-5-%d.dat", numSim) u 1:i+1 w l lw 1 lc palette cb (i-1) t"Espécie ".(i-1)

unset output
unset terminal