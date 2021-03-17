#   Print the density of species;
set terminal pngcairo size 1080,1080
set output "dst3.png"

set size ratio 1

set xlabel "Tempo"
#set xrange[0:100]
#set xtics 10

set ylabel "Densidade"
#set yrange[0:100]
#set  ytics 10

unset cbrange
unset cbtics
unset colorbox

plot for [i=1:4] "../dat/dst3.dat" u 1:i+1 w l lw 1 t"Espécie ".(i-1)

unset output
unset terminal

#   Print the density of species;
set terminal pngcairo size 1080,1080
set output "dst4.png"

set size ratio 1

set xlabel "Tempo"
#set xrange[0:100]
#set xtics 10

set ylabel "Densidade"
#set yrange[0:100]
#set  ytics 10

unset cbrange
unset cbtics
unset colorbox

plot for [i=1:5] "../dat/dst4.dat" u 1:i+1 w l lw 1 t"Espécie ".(i-1)

unset output
unset terminal

#   Print the density of species;
set terminal pngcairo size 1080,1080
set output "dst5.png"

set size ratio 1

set xlabel "Tempo"
#set xrange[0:100]
#set xtics 10

set ylabel "Densidade"
#set yrange[0:100]
#set  ytics 10

unset cbrange
unset cbtics
unset colorbox

plot for [i=1:6] "../dat/dst5.dat" u 1:i+1 w l lw 1 t"Espécie ".(i-1)

unset output
unset terminal