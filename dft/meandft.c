/**
 * Created              :   2021.07.19;
 * Last Update          :   2021.07.19;
 * Author               :   Gabriel Marino de Oliveira <ra115114@uem.br>;
 * Supervisor/Advisor   :   Breno Ferraz de Oliveira <>;
 * Notes                :   Take the aritimetic mean of several discrete transform fourrier;
 * Compilation          :   gcc -O3 meandft.c count_lines.c -static -o meandft.out
 */

#include "../head.h"

//  Function count how many lines the file have;
int count_lines(char *name);

int main (int argc, char **argv) {

    int i, j, s, n = 2500, N = atoi(argv[1]);
    double *arr = calloc(n*N, sizeof(double)), sum;
    FILE *file;
    char name[100];

    for (s = 0; s < 3; s++) {
        for (i = 0; i < N; i++) {
            sprintf(name, "dft-dst-spiral-%d-%d.dat", s+3, i+1);
            file = fopen(name, "r");
            for (j = 0; j < n; j++) {
                fscanf(file, "%lf", &arr[i*n+j]);
            };
            fclose(file);
        };

        sprintf(name, "meandft-%d.dat", s);
        file = fopen(name, "w");
        for (j = 0; j < n; j++) {
            sum = 0.0;
            for (i = 0; i < N; i++) {
                sum += arr[i*n+j];
            };
            sum /= N;
            fprintf(file, "%e\n", sum);
        };
        fclose(file);
        free(arr);
    };

    return 0;
};