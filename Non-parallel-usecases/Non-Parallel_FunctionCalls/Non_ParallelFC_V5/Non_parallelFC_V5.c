#include <stdio.h>
#include <stdlib.h>
#include "Non_parallelFC_V5.h"

/* Global variable to introduce side effect */
int global_counter = 0;

/* Non side-effect free function */
int modifyCounter(int value) {
    global_counter += value;
    return global_counter;
}

/* Initialization function */
void initialization(double **A, double **B, double **C) {
    for(int i = 0; i < DATA_SIZE; i++) {
        for(int j = 0; j < DATA_SIZE; j++) {
            A[i][j] = (double)(i + j);
            B[i][j] = (double)(i - j);
            C[i][j] = 0.0;
        }
    }
}

void kernel(double **A, double **B, double **C) {
    for(int i = 1; i < DATA_SIZE -1; i++) {
        for(int j = 1; j < DATA_SIZE -1; j++) {
            C[i][j] = (A[i][j] * B[i-1][j+1]) + (A[i+1][j] / (B[i][j] + 1.0));
            /* Call function with side effect */
            C[i][j] += modifyCounter(i + j);
        }
    }
}

/* Print results function */
void printResults(double **C) {
    for(int i = 0; i < DATA_SIZE; i++) {
        for(int j = 0; j < DATA_SIZE; j++) {
            printf("%lf ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    /* Allocate 2D arrays dynamically */
    double **A = malloc(DATA_SIZE * sizeof(double*));
    double **B = malloc(DATA_SIZE * sizeof(double*));
    double **C = malloc(DATA_SIZE * sizeof(double*));

    if(A == NULL || B == NULL || C == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for(int i = 0; i < DATA_SIZE; i++) {
        A[i] = malloc(DATA_SIZE * sizeof(double));
        B[i] = malloc(DATA_SIZE * sizeof(double));
        C[i] = malloc(DATA_SIZE * sizeof(double));

        if(A[i] == NULL || B[i] == NULL || C[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }

    /* Initialize arrays */
    initialization(A, B, C);

    /* Execute kernel */
    kernel(A, B, C);

    /* Print results */
    printResults(C);

    /* Print global counter to show side effects */
    printf("Global Counter: %d\n", global_counter);

    /* Free allocated memory */
    for(int i = 0; i < DATA_SIZE; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
