#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "PR_Function_V1.h"

// Global arrays
static double A[N][N];
static double B[N][N];
static double C[N][N];

void initialization() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (double)(i + j + 1);
            B[i][j] = (double)(i - j + 2);
            C[i][j] = 0.0;
        }
    }
}

void kernel() {
   // Start a parallel region
    #pragma omp parallel
    {
   
        #pragma omp for
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                C[i][j] = A[i][j] * B[j][(i+j) % N] 
                         + A[(j+i) % N][j] * B[i][j]
                         + 0.5 * A[i][(j+2)%N] * B[(i+3)%N][j]
                         - 0.3 * A[(i+4)%N][(j+4)%N] * B[(j+5)%N][(i+5)%N];
            }
        }

        #pragma omp for
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                C[i][j] += A[j][i] * B[(j+i)%N][(i+2)%N]
                          - 0.1 * B[j][i] * A[(i+2)%N][(j+2)%N];
            }
        }
    } // End parallel region
}

void printResults() {
    int print_size = (N < 10) ? N : 10;
    for (int i = 0; i < print_size; i++) {
        for (int j = 0; j < print_size; j++) {
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
