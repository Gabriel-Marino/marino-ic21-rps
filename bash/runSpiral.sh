 #!/bin/bash

    declare -i n=$1
    declare -i f
    declare -i i=0
    declare -i rn=$((1 + $RANDOM % $n))

    gcc -O3 dft/dft.c dft/count_lines.c -static -lm -o dat/dst/dft.out
    gcc -O3 dft/meandft.c dft/count_lines.c -static -o dat/dst/dft/meandft.out

    # for ((i = 3; i <= 5; i++))
    #     do
    #         gcc -O3 src/sthocastic/spiral/mainSthocastic-${i}.c -static -lgsl -lgslcblas -lm -o simRPS-spiral-${i}.out
    #         # gcc -O3 src/sthocastic/domain/mainSthocastic-${i}.c -static -lgsl -lgslcblas -lm -o simRPS-domain-${i}.out
    #         for ((j = 1; j <= n; j++))
    #             do
    #                 ./simRPS-spiral-${i}.out ${j}
    #                 # ./simRPS-domain-${i}.out ${j}
    #             done
    #     done
        cd dat/dst/
        f=$(ls *.dat | wc -l)
        for file in *.dat;
            do
                ./dft.out $file
                ((i=i+1))
                echo "DFT: $((i/(f/100)))% - $i of $f."
            done
        cd dft/
        ./meandft.out ${n}
        cd ../../../plt/pdf/
        for file in *.plt;
            do
                gnuplot -c $file ${rn}
            done
        cd ../../


    # rm dat/*
    # rm dat/act/*
    # rm dat/dst/*
    # rm dat/dst/dft/*
    # rm dat/emp/*
    # rm *.out

#*----------------------------------------------------------------------------------*#
    # cd plt/tex/
    # for file in *.plt;
    #     do
    #         gnuplot $file
    #     done
    # cd ../../

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
#*----------------------------------------------------------------------------------*#

# kill -9 $PPID
