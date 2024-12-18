#include <stdio.h>
#include <stdlib.h>
#include "Non_parallelOut_V4.h"

// Function declarations
void initialization(double **A, double **B);
void kernel(double **A, double **B);
void printResults(double **A, double **B);

// Helper function to allocate 2D arrays
double** allocate2D(int rows, int cols) {
    double **array = (double **) malloc(rows * sizeof(double *));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed for rows.\n");
        exit(EXIT_FAILURE);
    }
    array[0] = (double *) malloc(rows * cols * sizeof(double));
    if (array[0] == NULL) {
        fprintf(stderr, "Memory allocation failed for data.\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 1; i < rows; i++) {
        array[i] = array[0] + i * cols;
    }
    return array;
}

// Helper function to free 2D arrays
void free2D(double **array) {
    free(array[0]);
    free(array);
}

// Initialization function
void initialization(double **A, double **B) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            A[i][j] = (double)(i + j);
            B[i][j] = (double)(i - j);
        }
    }
}


void kernel(double **A, double **B) {
    for(int i = 1; i < N; i++) { 
        for(int j = 1; j < M; j++) { 
            // Data dependencies: A[i][j] depends on A[i-1][j] and A[i][j-1]
            A[i][j] = A[i][j] + A[i-1][j] * 0.5 + A[i][j-1] * 0.5;
            B[i][j] = B[i][j] * A[i][j] - A[i][j] / (B[i-1][j] + 1.0);
        }
    }
}

// Print results function
void printResults(double **A, double **B) {
    double checksumA = 0.0, checksumB = 0.0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            checksumA += A[i][j];
            checksumB += B[i][j];
        }
    }
    printf("Checksum A: %lf\n", checksumA);
    printf("Checksum B: %lf\n", checksumB);
}

// Main function
int main(int argc, char** argv) {
    // Allocate 2D arrays
    double **A = allocate2D(N, M);
    double **B = allocate2D(N, M);

    // Initialize data
    initialization(A, B);

    // Run kernel
    kernel(A, B);

    // Print results
    printResults(A, B);

    // Free memory
    free2D(A);
    free2D(B);

    return 0;
}
