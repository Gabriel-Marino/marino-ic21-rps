#!/bin/bash

gcc -O3 dft.c -static -lgsl -lgslcblas -lm -o dft.out
gcc -O3 data_test.c -static -lgsl -lgslcblas -lm

./a.out

for ((i = 1; i <= 3; i++))
    do
        ./dft.out ${i}-cos.dat
    done

gnuplot dft.plt

rm *.dat
rm *.out
rm ../dat/dft/*.dat

clear
echo "made it!"