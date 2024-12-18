#include <stdio.h>
#include <stdlib.h>
#include "PA_Function_V2.h"

double A[N][N][N];
double B[N][N][N];
double C[N][N][N];
double global_sum = 0.0;

void initialization(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                A[i][j][k] = (double)(i + j + k);
                B[i][j][k] = (double)(i - j + k) * 0.5;
                C[i][j][k] = (double)(i * j * k + 1);
            }
        }
    }
}

void kernel(void) {
    global_sum = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                A[i][j][k] = (A[i][j][k] + B[i][j][k]) * C[i][j][k];
                global_sum += A[i][j][k];
            }
        }
    }
}

void printResults(void) {
    printf("Final sum: %f\n", global_sum);
}

int main(void) {
    initialization();
    kernel();
    printResults();
    return 0;
}
