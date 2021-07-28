/**
 * Created              :   2021.07.19;
 * Last Update          :   2021.07.19;
 * Author               :   Gabriel Marino de Oliveira <ra115114@uem.br>;
 * Supervisor/Advisor   :   Breno Ferraz de Oliveira <>;
 * Notes                :   Count the lines of a file;
 * Compilation          :   gcc -O3 count_lines.c -static
 */

#include "../head.h"

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