/**
 * Created              :   2021.06.04;
 * Last Update          :   2021.06.04;
 * Author               :   Gabriel Marino de Oliveira <ra115114@uem.br>;
 * Supervisor/Advisor   :   Breno Ferraz de Oliveira <>;
 * Notes                :   Calculates the discrete Fourier Transform of the data inputted;
 * Compilation          :   gcc -O3 dft.c -static -lgsl -lgslcblas -lm -o dft.out
 */

#include "../head.h"

//  Function count how many lines the file have;
int count_lines(char *name) {
    int lines = 0;
    char chr;
    FILE *file = fopen(name, "r");

    for (chr = getc(file); chr != EOF; chr = getc(file)) {
        lines += (chr == '\n' ? 1 : 0);
    };

    fclose(file);
    return lines;
};

int main(int argc, char **argv) {

    char *data = argv[1], name[100];
    int n = count_lines(data), 
        i, t;
    double          *f_t = calloc(n, sizeof(double));
//                  *f_i = calloc(n, sizeof(double));       // can be used to do the inverse dft;
    double complex  *g_f = calloc(n/2, sizeof(double complex));
    FILE *file;

    file = fopen(data, "r");
    for (t = 0; t < n; t++) {
        fscanf(file, "%lf", &f_t[t]);
    };
    fclose(file);

    for (i = 0; i < n/2; i++) {
        for (t = 0; t < n; t++) {
            g_f[i] += f_t[t]*cexp(-2.0*M_PI*I*i*t/n);
        };
        g_f[i] *= 2.0/n;
    };
    g_f[0] /= 2.0;

    sprintf(name, "dft-%s", data);
    file = fopen(name, "w");
    for (i = 0; i < n/2; i++) {
        fprintf(file, "%e\n", cabs(g_f[i])*cabs(g_f[i]));
    };
    fclose(file);

    free(f_t);
    // free(f_i);
    free(g_f);
    return 0;
};