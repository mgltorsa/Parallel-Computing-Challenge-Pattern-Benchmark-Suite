#include <stdio.h>
#include "PR_Function_V2.h"

void initialization(double A[N][M], double B[N][M], double C[N][M], double D[N][M]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            A[i][j] = 0.0;
            B[i][j] = (double)((i + j) % 10);
            C[i][j] = (double)((i * j) % 10);
            D[i][j] = (double)(i - j);
        }
    }
}

void kernel(double A[N][M], double B[N][M], double C[N][M], double D[N][M]) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            A[i][j] = A[i][j] + B[i][j] * C[j][i] - D[i][j];
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            A[i][j] = (A[i][j] * 2.0 + D[i][j] * C[i][j]) / (B[i][j] + 1.0);
        }
    }
}

void printResults(double A[N][M]) {
    int i, j;
    // Print a small portion of A for verification
    for (i = 0; i < 10 && i < N; i++) {
        for (j = 0; j < 10 && j < M; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    static double A[N][M], B[N][M], C[N][M], D[N][M];

    initialization(A, B, C, D);
    kernel(A, B, C, D);
    printResults(A);

    return 0;
}
