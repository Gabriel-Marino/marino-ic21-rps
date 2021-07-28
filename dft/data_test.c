#include "../head.h"

//  gcc -O3 data_test.c -static -lgsl -lgslcblas -lm

int main(int argc, char **argv) {

    gsl_rng_default_seed = (argc == 2) ? atoi(argv[1]) : time(NULL);
    gsl_rng *rng = gsl_rng_alloc(gsl_rng_taus);

    FILE *cos1 = fopen("1-cos.dat", "w");
    FILE *cos2 = fopen("2-cos.dat", "w");
    FILE *cos3 = fopen("3-cos.dat", "w");

    for (int i = 0; i < 500; i++) {
        fprintf(cos1, "%e %e %e\n", 1.0*i, 2.0*i, 5.0*cos(10.0*M_PI*i/500));
        fprintf(cos2, "%e %e %e\n", 1.0*i, 2.0*i, 2.0*cos(10.0*M_PI*i/500));
        fprintf(cos3, "%e %e %e\n", 1.0*i, 2.0*i, 5.0*cos(10.0*M_PI*i/500)+2.0*gsl_rng_uniform(rng)-1.0);
    };

    fclose(cos1);
    fclose(cos2);
    fclose(cos3);
    gsl_rng_free(rng);
    return 0;
};