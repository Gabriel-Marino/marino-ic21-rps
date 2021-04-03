/**
 * Created              :   2020.09.02;
 * Last Update          :   2021.04.03;
 * Author               :   Gabriel Marino de Oliveira <ra115114@uem.br>;
 * Supervisor/Advisor   :   Breno Ferraz de Oliveira <>;
 * Notes                :   
 * Compilation          :   gcc -O3 src/main.c -static -lgls -lglscblas -lm -o simulationRPS.out
 * Execution            :   time ./simulationRPS.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gsl/gsl_rng.h>

#define nlog    100     // Number of points which will be printed when used a logarithmic scale;
#define Ni      500     // Size of the grid in "i";
#define Nj      500     // Size of the grid in "j";
#define dt      0.1     // Time interval;
#define tf      10000   // Total Time, or number of generations;
#define Pp      0.1     // Predation probability;
#define Pm      0.8     // Mobility probability - for sthocastic method;
#define Cm      1.0     // Mobility coeficient  - for RK method;
#define Pr      0.4     // Reproduction probability;