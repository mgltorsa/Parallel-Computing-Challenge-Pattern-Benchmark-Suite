#include <stdio.h>
#include "PA_Function_V1.h"

/* Global arrays and variables */
static double A[N][N], B[N][N], C[N][N];
static double result1 = 0.0, result2 = 0.0;

void initialization(void) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = (double)(i + j + 1);
            B[i][j] = (double)((i * j) % (N+1) + 1);
            C[i][j] = (double)((i + 1) / (j + 1.0));
        }
    }
}

void kernel(void) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            result1 += A[i][j] * B[j][(i+j) % N];
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            result2 += (C[i][j] * A[j][(i*2)%N]) - B[i][j];
        }
    }

  
}

void printResults(void) {
    printf("Result1: %lf\n", result1);
    printf("Result2: %lf\n", result2);

}

int main(void) {
    initialization();
    kernel();
    printResults();
    return 0;
}
