#   Print the density of species;
set terminal tikz fulldoc
set output "../../tex/dst3.tex"

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

plot for [i=1:4] "../../dat/dst3.dat" u 1:i+1 w l lw 1 lc palette cb (i-1) t"Espécie ".(i-1)

unset output
unset terminal

#   Print the density of species;
set terminal tikz fulldoc
set output "../../tex/dst4.tex"

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

plot for [i=1:5] "../../dat/dst4.dat" u 1:i+1 w l lw 1 lc palette cb (i-1) t"Espécie ".(i-1)

unset output
unset terminal

#   Print the density of species;
set terminal tikz fulldoc
set output "../../tex/dst5.tex"

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

plot for [i=1:6] "../../dat/dst5.dat" u 1:i+1 w l lw 1 lc palette cb (i-1) t"Espécie ".(i-1)

unset output
unset terminal
