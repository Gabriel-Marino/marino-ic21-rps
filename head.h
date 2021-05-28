/**
 * Created              :   2020.09.02;
 * Last Update          :   2021.05.28;
 * Author               :   Gabriel Marino de Oliveira <ra115114@uem.br>;
 * Supervisor/Advisor   :   Breno Ferraz de Oliveira <>;
 * Notes                :   
 * Compilation          :   gcc -O3 src/main.c -static -lgls -lglscblas -lm -o simulationRPS.out
 * Execution            :   time ./simulationRPS.out
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <complex.h>
#include <gsl/gsl_rng.h>

#define Ni  500     //  Size of the grid in "i", or abscissa axis;
#define Nj  500     //  Size of the grid in "j", or ordinate axis;
#define dt  0.1     //  Time interval;
#define tf  5000    //  Total Time, or number of generations;
#define Pp  0.3     //  Predation probability;
#define Pm  0.4     //  Mobility probability for sthocastic method;
                    /** Is not necessary to sthocastic method define the Reproduction probability, here we assume which "Pp + Pm + Pr = 1" or "Pr = 1 - (Pp + Pm)",
                     * and this is why Reproduction probability is only needed to define for RK method**/
#define Cm  1.0     //  Mobility coeficient for RK method;
#define Pr  0.4     //  Reproduction probability;

#define np  100                             //  Number of points which will be printed when used a logarithmic scale;
const double r = pow((tf/dt), (1.0/np));    //  r stands for ratio, will used to generate a arithmetic progression, useful to print equally spaced point
