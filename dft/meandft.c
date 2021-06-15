/**
 * Created              :   2021.06.11;
 * Last Update          :   2021.06.15;
 * Author               :   Gabriel Marino de Oliveira <ra115114@uem.br>;
 * Supervisor/Advisor   :   Breno Ferraz de Oliveira <>;
 * Notes                :   Take the mean of multiple dft;
 * Compilation          :   gcc -O3 meandft.c -static -lgsl -lgslcblas -lm -o meandft.out
 */

#include "../head.h"

#define size 1e10

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

int normal (double *arr) {

    int i;
    double    sig,
              min = arr[0], 
              max = arr[0],
            *temp = calloc(sizeof(arr), sizeof(double));

    for (i = 0; i < sizeof(arr); i++) {
        min = (arr[i] < min ? arr[i] : min);
    };

    for (i = 0; i < sizeof(arr); i++) {
        max = (arr[i] > max ? arr[i] : max);
    };

    sig = max - min;

    for (i = 0; i < sizeof(arr); i++) {
        temp[i] = (arr[i] - min)/sig;
    };

    arr = temp;

    free(temp);
    return 0;
};

int main(int argc, char **argv) {

    char *data = argv[1], name[100], **names;
    int n = count_lines(data), N, i, j, t;
    double sum, temp;
    double *arr = calloc(size, sizeof(double));
    FILE *file;

    file = fopen(data, "r");
    for (i = 0; i < n; i++) {
        fscanf(file, "%c", &names[i]);
    };
    fclose(file);

    for (i = 0; i < n; i++) {
        sprintf(name, "%c", names[i]);
        file = fopen(name, "r");
        N = count_lines(name);
        for (j = 0; j < N; j++){
            fscanf(file, "%lf", &arr[i*N+j]);
        };
        fclose(file);
    };

    file = fopen("../dat/dft/meandft.dat", "w");
    for (i = 0; i < sizeof(arr); i++) {
        fprintf(file, "%e\n", arr[i]);
    };
    fclose(file);

    free(arr);
    return 0;
};