#include <stdio.h>
#include "DA_Function_V1.h"

void initialization(double A[NI][NJ][NK], double B[NI][NJ][NK], double C[NI][NJ][NK]) {
    for (int i = 0; i < NI; i++) {
        for (int j = 0; j < NJ; j++) {
            for (int k = 0; k < NK; k++) {
                A[i][j][k] = (double)(i + j + k);
                B[i][j][k] = (double)(i * j * k + 1);
                C[i][j][k] = (double)(i + 2*j + 3*k + 2);
            }
        }
    }
}

void kernel(double A[NI][NJ][NK], double B[NI][NJ][NK], double C[NI][NJ][NK]) {

    for (int i = 0; i < NI; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= j; k++) {
                A[i][j][k] += B[i][j][k] * C[i][j][k] - 0.5 * A[i][j][k];
            }
        }
    }
}

void printResults(double A[NI][NJ][NK]) {
    /* Print a small portion of the results for verification */
    /* For larger datasets, printing all might be too big. Just print a slice. */
    for (int i = 0; i < (NI < 5 ? NI : 5); i++) {
        for (int j = 0; j < (NJ < 5 ? NJ : 5); j++) {
            for (int k = 0; k < (NK < 5 ? NK : 5); k++) {
                printf("%0.2f ", A[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    static double A[NI][NJ][NK];
    static double B[NI][NJ][NK];
    static double C[NI][NJ][NK];

    initialization(A, B, C);
    kernel(A, B, C);
    printResults(A);

    return 0;
}
