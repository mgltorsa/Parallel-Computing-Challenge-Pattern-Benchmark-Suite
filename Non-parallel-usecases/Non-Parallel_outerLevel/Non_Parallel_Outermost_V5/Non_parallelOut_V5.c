#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Non_parallelOut_V5.h"

// Function prototypes
void initialization(double A[NX][NY], double B[NX][NY], double C[NX][NY]);
void kernel(double A[NX][NY], double B[NX][NY], double C[NX][NY]);
void printResults(double C[NX][NY]);

/**
 * Initializes the arrays A, B, and C with random values.
 */
void initialization(double A[NX][NY], double B[NX][NY], double C[NX][NY]) {
    srand(time(NULL));
    for(int i = 0; i < NX; i++) {
        for(int j = 0; j < NY; j++) {
            A[i][j] = (double)(rand()) / RAND_MAX;
            B[i][j] = (double)(rand()) / RAND_MAX;
            C[i][j] = 0.0;
        }
    }
}

/**
 * The kernel function with a 2-level loop nest and data dependencies.
 * This kernel performs a complex operation that cannot be parallelized.
 */
void kernel(double A[NX][NY], double B[NX][NY], double C[NX][NY]) {
    for(int i = 1; i < NX; i++) {
        for(int j = 1; j < NY; j++) { 
            C[i][j] = A[i][j] * B[i][j] + C[i-1][j] - C[i][j-1];
            C[i][j] = C[i][j] / (1.0 + A[i][j] + B[i][j]);
            C[i][j] = C[i][j] * (A[i][j] - B[i][j]) + C[i-1][j-1];
        }
    }
}

/**
 * Prints a subset of the results array C to verify correctness.
 */
void printResults(double C[NX][NY]) {
    printf("Sample results from array C:\n");
    for(int i = 0; i < NX; i += NX/10) { // Print 10 samples from rows
        for(int j = 0; j < NY; j += NY/10) { // Print 10 samples from columns
            printf("C[%d][%d] = %f\t", i, j, C[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    // Allocate memory for arrays
    double (*A)[NY] = malloc(sizeof(double[NX][NY]));
    double (*B)[NY] = malloc(sizeof(double[NX][NY]));
    double (*C)[NY] = malloc(sizeof(double[NX][NY]));

    if (A == NULL || B == NULL || C == NULL) {
        fprintf(stderr, "Error allocating memory for arrays.\n");
        return EXIT_FAILURE;
    }

    // Initialize arrays
    initialization(A, B, C);

    // Execute the kernel multiple times
    for(int iter = 0; iter < NITERS; iter++) {
        kernel(A, B, C);
    }

    // Print the results
    printResults(C);

    // Free allocated memory
    free(A);
    free(B);
    free(C);

    return EXIT_SUCCESS;
}
