#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "DA_Function_V3.h"

/* This is the parallel version with three-level triangular loops. */

static double A[N][N], B[N][N], C[N][N];

void initialization() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (double)(i + j);
            B[i][j] = (double)(i - j);
            C[i][j] = 0.0;
        }
    }
}

void kernel() {

    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= j; k++) {
                C[i][j] += A[i][k] * B[j][k] - A[k][j] * B[i][k];
            }
        }
    }

    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= j; k++) {
                C[i][j] += (A[i][i] * B[j][j]) / (1.0 + i + j + k);
            }
        }
    }
}

void printResults() {
    int print_limit = (N < 10) ? N : 10;
    for (int i = 0; i < print_limit; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initialization();
    kernel();
    printResults();
    return 0;
}
