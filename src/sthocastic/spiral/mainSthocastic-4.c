/**
 * Created              :   2020.09.02;
 * Last Update          :   2021.05.28;
 * Author               :   Gabriel Marino de Oliveira <ra115114@uem.br>;
 * Supervisor/Advisor   :   Breno Ferraz de Oliveira <>;
 * Notes                :   based in RPS game rules sthocastic simulation of 4 species competing between then;
 */

#include "../../../head.h"

#define Ns 4                                    //  Number of species;
const double p[Ns*Ns] = {0.0, 1.0, 1.0, 0.0,    //  Predation matrix, each line represent one predator specie and each column prey specie;
                         0.0, 0.0, 1.0, 1.0,    //  where have 1.0 indicates that exist predation interacting;
                         1.0, 0.0, 0.0, 1.0,
                         1.0, 1.0, 0.0, 0.0};

//  Output (op) function, print the results into .dat archives;
void op(int numSim, int t, int *phi) {
    int i, j;
    FILE *file;
    char name[100];

    sprintf(name, "dat/rps%d-%d-%d.dat", Ns, t, numSim);
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

    double action, inv_emp, a = r;
    int i, j,
        k = 0,
        l, t,
        gd,         //  gd      -> grid;
        act,        //  act     -> Active;
        pas,        //  pas     -> Passive;
        nebr,       //  nebr    -> Neighboor;
        temp,       //  temp    -> Temporary;
        dst0 = 0,   //  Counter of empty spots;
        dst1 = 0,   //  Counter of specie 1;
        dst2 = 0,   //  Counter of specie 2;
        dst3 = 0,   //  Counter of specie 3;
        dst4 = 0,   //  Counter of specie 4;
        rep  = 0,   //  Counter of repoduction;
        pre  = 0,   //  Counter of predation;
        mob  = 0,   //  Counter of mobility;
        numSim = atoi(argv[1]),
        *phi = calloc(Ni*Nj, sizeof(int));  //  phi -> pointer that locates each individual in the grid;
    char namedst[100], nameInvEmp[100], nameAct[100];

    gsl_rng_default_seed = (argc == 2) ? atoi(argv[1]) : time(NULL);
    gsl_rng *rng = gsl_rng_alloc(gsl_rng_taus);

    sprintf(namedst, "dat/dst-%d-%d.dat", Ns, numSim);
    sprintf(nameInvEmp, "dat/invEmp-%d-%d.dat", Ns, numSim);
    sprintf(nameAct, "dat/act-cont-%d-%d.dat", Ns, numSim);
    FILE *filedst = fopen(namedst, "w");        //  File where the densities will be printed;
    FILE *fileInvEmp = fopen(nameInvEmp, "w");  //  File where the inverse of the empty spots density in logarithmic scale will be printed;
    FILE *fileact = fopen(nameAct, "w");

//  Initial conditions;
    for (i = 0; i < Ni; i++) {
        for (j = 0; j < Nj; j++) {
            phi[i*Nj+j] = gsl_rng_uniform(rng)*(Ns+1);
            (phi[i*Nj+j] == 0) ? dst0++ : (
            (phi[i*Nj+j] == 1) ? dst1++ : (
            (phi[i*Nj+j] == 2) ? dst2++ : (
            (phi[i*Nj+j] == 3) ? dst3++ : dst4++)));
        };
    };
//  printing initial conditions;
    op(numSim, k, phi);

//  Main Loop;
    for (t = 0; t < tf+1; t++) {
        gd = 0;

        fprintf(filedst, "%d %e %e %e %e %e\n", t, (double) dst0/(Ni*Nj), 
                                                (double) dst1/(Ni*Nj), 
                                                (double) dst2/(Ni*Nj), 
                                                (double) dst3/(Ni*Nj), 
                                                (double) dst4/(Ni*Nj));

        inv_emp = ((double) Ni*Nj)/dst0;
        if (a <= t) {
            fprintf(fileInvEmp, "%d %e\n", t, inv_emp);
            a *= r;
        };

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
                mob++;
            } else {
//              Predation
                if (action <= Pm+Pp) {
                    // if (phi[act]%4+1 == phi[pas] || (phi[act]+1)%4+1 == phi[pas]) {
                    if (phi[pas] != 0 && action < p[(phi[act]-1)*Ns+phi[pas]-1]) {
                        phi[pas] = 0;
                        gd++;
                        pre++;
                    };
//              Reproduction
                } else {
                    if (phi[pas] == 0) {
                        phi[pas] = phi[act];
                        gd++;
                        rep++;
                    };
                };
            };
        };
        fprintf(fileact, "%d %d %d %d\n", t, mob, pre, rep);
        dst0 = 0; dst1 = 0; dst2 = 0; dst3 = 0; dst4 = 0;
        for (i = 0; i < Ni; i++) {
            for (j = 0; j < Nj; j++) {
                (phi[i*Nj+j] == 0) ? dst0++ : (
                (phi[i*Nj+j] == 1) ? dst1++ : (
                (phi[i*Nj+j] == 2) ? dst2++ : (
                (phi[i*Nj+j] == 3) ? dst3++ : dst4++)));
            };
        };
        if (t%(tf/1000) == 0) {
            // op(numSim, k++, phi);
            t == 0 ? op(numSim, t, phi) : (t%tf == 0 ? op(numSim, t, phi) : NULL);
            printf("%d %d%%\n", numSim, t/(tf/100));
        };
    };
    // op(1, phi);

    gsl_rng_free(rng);
    fclose(filedst);
    fclose(fileInvEmp);
    fclose(fileact);
    free(phi);
    return 0;
};