#include <stdio.h>
#include "PF_Function_V2.h"

// Example side-effect free function
// This function just returns some computed value without modifying global state
static inline double side_effect_free_func(double x, double y) {
    // A simple math operation:
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

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            double valA = A[i][j];
            double valB = B[i][M - j - 1]; // Some reversed index access
            // Use the side_effect_free_func
            double temp = side_effect_free_func(valA, valB);
            C[i][j] = valA + valB + temp;
        }
    }
}

void printResults(double C[N][M]) {
    // Print only a subset to avoid huge output
    // For demonstration, print first 5x5 block
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
