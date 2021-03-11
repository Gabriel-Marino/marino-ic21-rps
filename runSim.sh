#!/bin/bash

for ((i = 3; i <= 5; i++))
    do    
        echo "Running sim ${i}"
        gcc -O3 src/mainSthocastic-${i}.c -static -lgsl -lgslcblas -lm -o simRPS-${i}.out
        time ./simRPS.out
        cd plt
        echo "Running sim ${i}"
        time gnuplot plot${i}.plt
        # time gnuplot plottex${i}.plt
        cd ..
        rm *.out
        rm dat/*.dat
    done