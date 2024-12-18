#include <stdio.h>
#include <stdlib.h>
#include "Non_parallelFC_V4.h"

// Global variables
double A[MAX_SIZE][MAX_SIZE][MAX_SIZE];
double B[MAX_SIZE][MAX_SIZE][MAX_SIZE];
double C[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int global_counter = 0;

// Function prototypes
void initialization();
void kernel();
void printResults();

// Non side-effect-free function to prevent parallelization
double compute(int i, int j, int k) {
    // Introduce side effects by modifying a global variable
    global_counter += (i + j + k) % 100;
    return (double)(i * j - k) / (double)(i + j + 1);
}

int main(int argc, char** argv) {
    initialization();
    kernel();
    printResults();
    return 0;
}

void initialization() {
    for(int i = 0; i < N1; i++) {
        for(int j = 0; j < N2; j++) {
            for(int k = 0; k < N3; k++) {
                A[i][j][k] = (double)(i + j + k);
                B[i][j][k] = (double)(i * j * k);
                C[i][j][k] = 0.0;
            }
        }
    }
}

void kernel() {
    for(int i = 0; i < N1; i++) {
        for(int j = 0; j < N2; j++) {
            for(int k = 0; k < N3; k++) {
                int idx1 = (i + j) % N1;
                int idx2 = (j + k) % N2;
                int idx3 = (k + i) % N3;
                C[i][j][k] = A[idx1][idx2][idx3] * B[i][j][k] + compute(i, j, k);
            }
        }
    }
}

void printResults() {
    printf("Global Counter: %d\n", global_counter);
    printf("Sample Results:\n");
    for(int i = 0; i < (N1 < 5 ? N1 : 5); i++) {
        for(int j = 0; j < (N2 < 5 ? N2 : 5); j++) {
            for(int k = 0; k < (N3 < 5 ? N3 : 5); k++) {
                printf("C[%d][%d][%d] = %.2f\n", i, j, k, C[i][j][k]);
            }
        }
    }
}
