#include <stdio.h>
#include <omp.h>
#include "PF_Function_V2.h"

// Same side-effect free function
static inline double side_effect_free_func(double x, double y) {
    return x * x + y * y;
}

void initialization(double A[N][M], double B[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = (double)(i + j);
            B[i][j] = (double)(i - j);
        }
    }
}

void kernel(double A[N][M], double B[N][M], double C[N][M]) {
    // Parallelized version using OpenMP
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            double valA = A[i][j];
            double valB = B[i][M - j - 1];
            double temp = side_effect_free_func(valA, valB);
            C[i][j] = valA + valB + temp;
        }
    }
}

void printResults(double C[N][M]) {
    int limit_i = (N < 5) ? N : 5;
    int limit_j = (M < 5) ? M : 5;
    for (int i = 0; i < limit_i; i++) {
        for (int j = 0; j < limit_j; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    static double A[N][M], B[N][M], C[N][M];
    initialization(A, B);
    kernel(A, B, C);
    printResults(C);
    return 0;
}
