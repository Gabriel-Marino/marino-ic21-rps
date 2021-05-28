#   Print the lattice;
set terminal pdfcairo #size 1080,1080 crop

set size ratio 1
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
                     3 "#ffff00")

do for [t=0:1] {
    set output sprintf("rps3-%d.pdf", t)
    plot sprintf("../../dat/rps3-%d.dat", t) u ($1+1):($2+1):($3) matrix w image t""
    unset output
}

unset output
unset terminal

#   Print empty spots in the lattice;
set terminal pdfcairo #size 1080,1080 crop

set size ratio 1
set xrange[0:500]
unset xtics
set yrange[0:500]
unset ytics

set cbrange [0:1]
unset cbtics
unset colorbox

set palette gray

do for [t=0:1] {
    set output sprintf("rps3-emp-%d.pdf", t)
    plot sprintf("../../dat/rps3-%d.dat", t) u ($1+1):($2+1):($3) matrix w image t""
    unset output
}

unset output
unset terminal