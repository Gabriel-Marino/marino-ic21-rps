/**
 * Created              :   2021.06.04;
 * Last Update          :   2021.07.09;
 * Author               :   Gabriel Marino de Oliveira <ra115114@uem.br>;
 * Supervisor/Advisor   :   Breno Ferraz de Oliveira <>;
 * Notes                :   Calculates the discrete Fourier Transform of the data inputted;
 * Compilation          :   gcc -O3 dft.c -static -lgsl -lgslcblas -lm -o dft.out
 */

#include "../head.h"

//  Function count how many lines the file have;
int count_lines(char *name);

int main(int argc, char **argv) {

    char *data = argv[1], name[100];
    int n = count_lines(data), i, t/*, N = atoi(argv[2])*/;
    double          *f_t = calloc(n, sizeof(double)),
                    *c   = calloc(7, sizeof(double));       /*  the data i've used have 5 column and i just need the data on the 3rd column,
                                                                so i used this variable to throw away the two 1st columns;*/
//                  *f_i = calloc(n, sizeof(double));       // can be used to do the inverse dft;
    double complex  *g_f = calloc(n/2, sizeof(double complex));
    FILE *file/*, *file1*/;

    // sprintf(name, "dft/names/dftnames-%d.dat", N);
    // file1 = fopen(name, "a");

    file = fopen(data, "r");
    for (t = 0; t < n; t++) {
        fscanf(file, "%lf %lf %lf %lf %lf %lf %lf", &c[0], &c[1], &f_t[t], &c[2], &c[3], &c[4], &c[5]);
    };
    fclose(file);

    for (i = 0; i < n/2; i++) {
        for (t = 0; t < n; t++) {
            g_f[i] += f_t[t]*cexp(-2.0*M_PI*I*i*t/n);
        };
        g_f[i] *= 2.0/n;
    };
    g_f[0] /= 2.0;

    sprintf(name, "dft/dft-%s", data);
    // fprintf(file1, "%s\n", name);
    file = fopen(name, "w");
    for (i = 0; i < n/2; i++) {
        fprintf(file, "%e\n", cabs(g_f[i])*cabs(g_f[i]));
    };
    fclose(file);
    // fclose(file1);

    free(f_t);
    // free(f_i);
    free(g_f);
    return 0;
};