#   Print the density of species;
set terminal pngcairo size 1280,800
set output "dst3.png"

set size ratio 0.5

set xlabel "Geração"
set xrange[0:5000]
set xtics 1000

set ylabel "Densidade"
set yrange[0:0.5]
set ytics 0.1

unset cbrange
unset cbtics
unset colorbox

set palette defined (0 "#000000",\
                     1 "#ff0000",\
                     2 "#0000ff",\
                     3 "#ffff00")

plot for [i=1:4] "../dat/dst3.dat" u 1:i+1 w l lw 1 lc palette t"Espécie ".(i-1)

unset output
unset terminal

#   Print the density of species;
set terminal pngcairo size 1280,800
set output "dst4.png"

set size ratio 0.5

set xlabel "Geração"
set xrange[0:5000]
set xtics 1000

set ylabel "Densidade"
set yrange[0:0.5]
set ytics 0.1

unset cbrange
unset cbtics
unset colorbox

set palette defined (0 "#000000",\
                     1 "#ff0000",\
                     2 "#0000ff",\
                     3 "#ffff00",\
                     4 "#ff00ff")

plot for [i=1:5] "../dat/dst4.dat" u 1:i+1 w l lw 1 lc palette t"Espécie ".(i-1)

unset output
unset terminal

#   Print the density of species;
set terminal pngcairo size 1280,800
set output "dst5.png"

set size ratio 0.5

set xlabel "Geração"
set xrange[0:5000]
set xtics 1000

set ylabel "Densidade"
set yrange[0:0.5]
set ytics 0.1

unset cbrange
unset cbtics
unset colorbox

set palette defined (0 "#000000",\
                     1 "#ff0000",\
                     2 "#0000ff",\
                     3 "#ffff00",\
                     4 "#ff00ff",\
                     5 "#00ffff")

plot for [i=1:6] "../dat/dst5.dat" u 1:i+1 w l lw 1 lc palette t"Espécie ".(i-1)

unset output
unset terminal