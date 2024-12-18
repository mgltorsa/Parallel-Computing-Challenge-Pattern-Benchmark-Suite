#include <stdio.h>
#include <math.h>
#include "PF_Function_V3.h"

/* Same side-effect free function as before */
static inline double foo(double x, double y) {
    return sin(x) * cos(y) + sqrt(x + y);
}

void initialization(double A[NI][NJ], double B[NI][NJ]) {
    for (int i = 0; i < NI; i++) {
        for (int j = 0; j < NJ; j++) {
            A[i][j] = (double) (i*j) / (NI*NJ);
            B[i][j] = (double) (i+j) / (NI+NJ);
        }
    }
}

void kernel(double A[NI][NJ], double B[NI][NJ]) {
    /* Parallelized kernel */
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < NI; i++) {
        for (int j = 0; j < NJ; j++) {
            A[i][j] += foo(B[i][j], A[i][j]);
        }
    }
}

void printResults(double A[NI][NJ]) {
    int print_i = NI < 5 ? NI : 5;
    int print_j = NJ < 5 ? NJ : 5;
    for (int i = 0; i < print_i; i++) {
        for (int j = 0; j < print_j; j++) {
            printf("%0.6f ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    static double A[NI][NJ], B[NI][NJ];
    initialization(A, B);
    kernel(A, B);
    printResults(A);
    return 0;
}
