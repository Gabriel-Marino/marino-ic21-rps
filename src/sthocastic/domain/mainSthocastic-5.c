/**
 * Created              :   2020.09.02;
 * Last Update          :   2021.03.16;
 * Author               :   Gabriel Marino de Oliveira <ra115114@uem.br>;
 * Supervisor/Advisor   :   Breno Ferraz de Oliveira <>;
 * Notes                :   based in RPS game rules sthocastic simulation of 5 species competing between then;
 */

#include "../../../head.h"

//  Output (op) function, print the results into .dat archives;
void op(int t, int *phi) {
    int i, j;
    FILE *file;
    char name[100];

    sprintf(name, "dat/rps5-%d.dat", t);
    file = fopen(name, "w");
    for (i = 0; i < Ni; i++) {
        for (j = 0; j < Nj; j++) {
            fprintf(file, "%d ", phi[i*Nj+j]);
        };
        fprintf(file, "\n");
    };
    fclose(file);
};

int main(int argc, char **argv) {

    double action;
    int i, j,
        k = 0,
        l, t,
        gd,         //  gd      -> grid;
        act,        //  act     -> Active;
        pas,        //  pas     -> Passive;
        nebr,       //  nebr    -> Neighboor;
        temp,       //  temp    -> Temporary;
        dst0 = 0,   //  Densinty of empty spots;
        dst1 = 0,   //  Densinty of specie 1;
        dst2 = 0,   //  Densinty of specie 2;
        dst3 = 0,   //  Densinty of specie 3;
        dst4 = 0,   //  Densinty of specie 4;
        dst5 = 0,   //  Densinty of specie 5;
        *phi = calloc(Ni*Nj, sizeof(int));  //  phi -> pointer that locates each individual in the grid;

    gsl_rng_default_seed = (argc == 2) ? atoi(argv[1]) : time(NULL);
    gsl_rng *rng = gsl_rng_alloc(gsl_rng_taus);

    FILE *file = fopen("dat/dst5.dat", "w");

//  Initial conditions;
    for (i = 0; i < Ni; i++) {
        for (j = 0; j < Nj; j++) {
            phi[i*Nj+j] = gsl_rng_uniform(rng)*6;
            (phi[i*Nj+j] == 0) ? dst0++ : (
            (phi[i*Nj+j] == 1) ? dst1++ : (
            (phi[i*Nj+j] == 2) ? dst2++ : (
            (phi[i*Nj+j] == 3) ? dst3++ : (
            (phi[i*Nj+j] == 4) ? dst4++ : dst5++))));
        };
    };
//  printing initial conditions;
    // op(k, phi);

//  Main Loop;
    for (t = 0; t < tf+1; t++) {
        gd = 0;
        fprintf(file, "%d %e %e %e %e %e %e\n", t,  (double) dst0/(Ni*Nj),
                                                    (double) dst1/(Ni*Nj),
                                                    (double) dst2/(Ni*Nj),
                                                    (double) dst3/(Ni*Nj),
                                                    (double) dst4/(Ni*Nj),
                                                    (double) dst5/(Ni*Nj));
        while (gd < Ni*Nj) {
            do {
                i = gsl_rng_uniform(rng)*Ni;
                j = gsl_rng_uniform(rng)*Nj;
                act = i*Nj+j;
            } while (phi[act] == 0);
            nebr = gsl_rng_uniform(rng)*4;
            switch (nebr) {
                case 0:
                    pas = ((i+1)%Ni)*Nj+j;
                    break;
                case 1:
                    pas = ((i-1+Ni)%Ni)*Nj+j;
                    break;
                case 2:
                    pas = i*Nj+(j+1)%Nj;
                    break;
                default:
                    pas = i*Nj+(j-1+Nj)%Nj;
            };
            action = gsl_rng_uniform(rng);
//          Mobility
            if (action < Pm) {
                temp = phi[act];
                phi[act] = phi[pas];
                phi[pas] = temp;
                gd++;
            } else {
//              Predation
                if (action <= Pm+Pp) {
                    if (phi[act] != phi[pas] && phi[pas] != 0) {
                        phi[pas] = 0;
                        gd++;
                    };
//              Reproduction
                } else {
                    if (phi[pas] == 0) {
                        phi[pas] = phi[act];
                        gd++;
                    };
                };
            };
        };
        
        (phi[i*Nj+j] == 0) ? dst0++ : (
        (phi[i*Nj+j] == 1) ? dst1++ : (
        (phi[i*Nj+j] == 2) ? dst2++ : (
        (phi[i*Nj+j] == 3) ? dst3++ : (
        (phi[i*Nj+j] == 4) ? dst4++ : dst5++))));
        if (t%(tf/1000) == 0) {
            // op(k++, phi);
            printf("%d%%\n", t/(tf/100));
        };
    };

    gsl_rng_free(rng);
    free(phi);
    return 0;
};