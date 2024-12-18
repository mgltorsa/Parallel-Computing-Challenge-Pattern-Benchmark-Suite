#include <stdio.h>
#include <math.h>
#include <omp.h>
#include "DA_Function_V2.h"

void initialization(double A[N][N], double B[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (double)(i + j) / (N);
            B[i][j] = (double)(i - j) / (N + 1);
        }
    }
}

void kernel(double A[N][N], double B[N][N]) {
    // Parallel version using OpenMP with dynamic scheduling

    // Loop 1
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            double temp = A[i][j] * B[j][i] + sin(A[i][j]) + cos(B[j][i]);
            A[i][j] = temp * 0.5 + sqrt(fabs(temp));
        }
    }

    // Loop 2
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            double temp = B[i][j] * A[j][i] - sin(B[i][j]) + cos(A[j][i]);
            B[i][j] = temp * 0.3 + sqrt(fabs(temp));
        }
    }
}

void printResults(double A[N][N]) {
    for (int j = 0; j < N; j++) {
        printf("%.6f ", A[N-1][j]);
    }
    printf("\n");
}

int main() {
    static double A[N][N];
    static double B[N][N];

    initialization(A, B);
    kernel(A, B);
    printResults(A);

    return 0;
}
