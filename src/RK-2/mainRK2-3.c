/**'
 * Created              :   2020.09.02;
 * Last Update          :   2021.01.18;
 * Author               :   Gabriel Marino de Oliveira <ra115114@uem.br>;
 * Supervisor/Advisor   :   Breno Ferraz de Oliveira <>;
 * Notes                :   Simulation of dynamic populations with Rock-Paper-Scissor model using Runge-Kutta method;
 */

#include "../head.h"

//  Output (op) function, print the results into .dat archives;
void op(int t, double *p1, double *p2, double *p3, double *p0) {
    int i, j;
    FILE *file;
    char name[100];

    sprintf(name, "dat/rps-%d.dat", t);
    file = fopen(name, "w");
    for (i = 0; i < Ni; i++) {
        for (j = 0; j < Nj; j++) {
            fprintf(file, "%e ", 1.0*p1[i*Nj+j]+2.0*p2[i*Nj+j]+3.0*p3[i*Nj+j]);
        };
        fprintf(file, "\n");
    };
    fclose(file);

//  Printing empty spots of the lattice;
    sprintf(name, "dat/emp-%d.dat", t);
    file = fopen(name, "w");
    for (i = 0; i < Ni; i++) {
        for (j = 0; j < Nj; j++) {
            fprintf(file, "%e ", p0[i*Nj+j]);
        };
        fprintf(file, "\n");
    };
    fclose(file);
};

int main(int argc, char **argv) {

    int i, j, k, l, t,                          // l is the location, that will be defined to simplify some parts of the code to not polute with much repetions of long terms;
        c = 0,                                  // c is the counter that impress the number of the file that will be printed;
        lpx, lmx,                               // lmx -> l minus x, lpx -> l plus x
        lpy, lmy;                               // lmy -> l minus y, lpy -> l plus y
    double  T, Laplaciano;
    double  *p1  = calloc(Ni*Nj, sizeof(double)),
            *p2  = calloc(Ni*Nj, sizeof(double)),
            *p3  = calloc(Ni*Nj, sizeof(double)),
            *p0  = calloc(Ni*Nj, sizeof(double)),
            *p_1 = calloc(Ni*Nj, sizeof(double)),
            *p_2 = calloc(Ni*Nj, sizeof(double)),
            *p_3 = calloc(Ni*Nj, sizeof(double)),
            *p_0 = calloc(Ni*Nj, sizeof(double));

    gsl_rng_default_seed = (argc == 3) ? atoi(argv[2]) : time(NULL);
    gsl_rng *rng = gsl_rng_alloc(gsl_rng_taus);

//  Initial conditions;
    for (i = 0; i < Ni; i++) {
        for(j = 0; j < Nj; j++) {
            k = gsl_rng_uniform(rng)*4;
            l = i*Ni+j;
            switch(k) {
                case 0:
                    p0[l] = 1.0;
                    break;
                case 1:
                    p1[l] = 1.0;
                    break;
                case 2:
                    p2[l] = 1.0;
                    break;
                case 3:
                    p3[l] = 1.0;
                    break;
            };
        };
    };
//  Printing initial conditions;
    op(c, p1, p2, p3, p0);

//  Main loop - Temporal loop;
    for (t = 0; t <= tf; t++) {
        T = 0.0;
        while(T < 1.0) {
//      First step of Runge-Kutta;
            for (i = 0; i < Ni; i++) {
                for (j = 0; j < Nj; j++) {
                    l = i*Nj+j;
                    lpx = ((i+1)%Ni)*Nj+j;
                    lmx = ((i-1+Ni)%Ni)*Nj+j;
                    lpy = i*Nj+(j+1)%Nj;
                    lmy = i*Nj+(j-1+Nj)%Nj;

                    Laplaciano = p1[lpx]+p1[lmx]+p1[lpy]+p1[lmy]-4.0*p1[l];
                    p_1[l] = p1[l]+0.5*dt*(Cm*Laplaciano+Pr*p0[l]*p1[l]-Pp*p1[l]*p3[l]);

                    Laplaciano = p2[lpx]+p2[lmx]+p2[lpy]+p2[lmy]-4.0*p2[l];
                    p_2[l] = p2[l]+0.5*dt*(Cm*Laplaciano+Pr*p0[l]*p2[l]-Pp*p1[l]*p2[l]);

                    Laplaciano = p3[lpx]+p3[lmx]+p3[lpy]+p3[lmy]-4.0*p3[l];
                    p_3[l] = p3[l]+0.5*dt*(Cm*Laplaciano+Pr*p0[l]*p3[l]-Pp*p2[l]*p3[l]);

                    Laplaciano = p0[lpx]+p0[lmx]+p0[lpy]+p0[lmy]-4.0*p0[l];
                    p_0[l] = p0[l]+0.5*dt*(Cm*Laplaciano-Pr*p0[l]*(p1[l]+p2[l]+p3[l])+Pp*(p1[l]*p3[l]+
                                                                                          p2[l]*p1[l]+
                                                                                          p3[l]*p2[l]));
                };
            };
//      Second step of Runge-Kutta;
            for (i = 0; i < Ni; i++) {
                for (j = 0; j < Nj; j++) {
                    l = i*Nj+j;
                    lpx = ((i+1)%Ni)*Nj+j;
                    lmx = ((i-1+Ni)%Ni)*Nj+j;
                    lpy = i*Nj+(j+1)%Nj;
                    lmy = i*Nj+(j-1+Nj)%Nj;

                    Laplaciano = p_1[lpx]+p_1[lmx]+p_1[lpy]+p_1[lmy]-4.0*p_1[l];
                    p1[l] += 0.5*dt*(Cm*Laplaciano+Pr*p_0[l]*p_1[l]-Pp*p_1[l]*p_3[l]);

                    Laplaciano = p_2[lpx]+p_2[lmx]+p_2[lpy]+p_2[lmy]-4.0*p_2[l];
                    p2[l] += 0.5*dt*(Cm*Laplaciano+Pr*p_0[l]*p_2[l]-Pp*p_1[l]*p_2[l]);

                    Laplaciano = p_3[lpx]+p_3[lmx]+p_3[lpy]+p_3[lmy]-4.0*p_3[l];
                    p3[l] += 0.5*dt*(Cm*Laplaciano+Pr*p_0[l]*p_3[l]-Pp*p_2[l]*p_3[l]);

                    Laplaciano = p_0[lpx]+p_0[lmx]+p_0[lpy]+p_0[lmy]-4.0*p_0[l];
                    p0[l] += 0.5*dt*(Cm*Laplaciano-Pr*p_0[l]*(p_1[l]+p_2[l]+p_3[l])+Pp*(p_1[l]*p_3[l]+
                                                                                        p_2[l]*p_1[l]+
                                                                                        p_3[l]*p_2[l]));
                };
            };
        T += dt;
        };
        if (t%(tf/1000) == 0) {
            op(c++, p1, p2, p3, p0);
            printf("%d%%\n", t/(tf/100));
        };
    };

    free(p1);
    free(p2);
    free(p3);
    free(p0);
    free(p_1);
    free(p_2);
    free(p_3);
    free(p_0);
    gsl_rng_free(rng);
    return 0;
};
