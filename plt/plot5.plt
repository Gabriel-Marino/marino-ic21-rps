#   Imprime imagens da posição dos individuos baseadas em cada dat gerado pela simulação
set terminal pngcairo size 1080,1080

set size ratio -1
set xrange[0:500]
unset xtics
set yrange[0:500]
unset ytics

unset cbrange
unset cbtics
unset colorbox

set palette defined (0 "#ffffff",\
                     1 "#ff0000",\
                     2 "#0000ff",\
                     3 "#ffff00",\
                     4 "#ff00ff",\
                     5 "#00ffff")

do for [t=0:1000] {
    set output sprintf("rps5-%d.png", t)
    plot sprintf("../dat/rps-%d.dat", t) u ($1+1):($2+1):($3) matrix w image t""
    unset output
}

unset output
unset terminal