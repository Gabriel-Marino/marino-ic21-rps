#!/bin/bash

    for ((i = 3; i <= 5; i++))
        do
            gcc -O3 src/sthocastic/spiral/mainSthocastic-${i}.c -static -lgsl -lgslcblas -lm -o simRPS-spiral-${i}.out
            gcc -O3 src/sthocastic/domain/mainSthocastic-${i}.c -static -lgsl -lgslcblas -lm -o simRPS-domain-${i}.out
            for ((j = 1; j <= 1; j++))
                do
                    ./simRPS-spiral-${i}.out ${j}
                    ./simRPS-domain-${i}.out ${j}
                    cd plt/pdf/
                    for file in *.plt;
                        do
                            gnuplot -persist -c $file ${j}
                        done
                    cd ../../
                done
            rm simRPS-spiral-${i}.out
            rm simRPS-domain-${i}.out
        done

    # cd plt/tex/
    # for file in *.plt;
    #     do
    #         gnuplot $file
    #     done
    # cd ../../
    cd plt/pdf/
    for file in *.plt;
        do
            gnuplot $file
        done
    cd ../../

    # rm dat/*

    # if [ -z "$(ls -A /tex)" ]; then
    #     exit 0
    # else
    #     cd tex/
    #     for file in *.tex;
    #         do
    #             lualatex $file
    #         done
    #     find . ! -name '*.pdf' -type f -exec rm -f {} +
    # fi

    # for file in rps*;
    #     do
    #         pdfcrop $file
    #     done
    # cd ../

# kill -9 $PPID
