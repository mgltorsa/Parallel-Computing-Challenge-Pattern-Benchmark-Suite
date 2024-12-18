// NW_Function_V2.c
#include <stdio.h>
#include <stdlib.h>
#include "NW_Function_V2.h"

// Global variables
double ***matrix_A;
double ***matrix_B;
double ***result;
double ***array;
double sum = 0.0;

// Function to allocate 3D arrays
double ***allocate3DArray(int x, int y, int z) {
    double ***array = (double ***)malloc(x * sizeof(double **));
    for(int i = 0; i < x; i++) {
        array[i] = (double **)malloc(y * sizeof(double *));
        for(int j = 0; j < y; j++) {
            array[i][j] = (double *)malloc(z * sizeof(double));
        }
    }
    return array;
}

// Initialization function
void initialization() {
    matrix_A = allocate3DArray(ARRAY_SIZE, INNER_SIZE, INNER_SIZE);
    matrix_B = allocate3DArray(ARRAY_SIZE, INNER_SIZE, INNER_SIZE);
    result    = allocate3DArray(ARRAY_SIZE, INNER_SIZE, INNER_SIZE);
    array     = allocate3DArray(ARRAY_SIZE, INNER_SIZE, INNER_SIZE);

    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < INNER_SIZE; j++) {
            for(int k = 0; k < INNER_SIZE; k++) {
                matrix_A[i][j][k] = (double)(i + j + k);
                matrix_B[i][j][k] = (double)(i - j + k);
                array[i][j][k]      = (double)(i * j * k);
                result[i][j][k]     = 0.0;
            }
        }
    }
}

// Kernel function with two level-3 loops
void kernel() {

    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < INNER_SIZE; j++) {
            for(int k = 0; k < INNER_SIZE; k++) {
                result[i][j][k] += matrix_A[i][j][k] * matrix_B[i][j][k];
            }
        }
    }

    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < INNER_SIZE; j++) {
            for(int k = 0; k < INNER_SIZE; k++) {
                sum += array[i][j][k] / (i + j + k + 1); 
            }
        }
    }
}

// Function to print results
void printResults() {
    printf("Sum: %lf\n", sum);
    // Optionally, print some elements of the result matrix
    printf("result[0][0][0] = %lf\n", result[0][0][0]);
    printf("result[%d][%d][%d] = %lf\n", ARRAY_SIZE-1, INNER_SIZE-1, INNER_SIZE-1, result[ARRAY_SIZE-1][INNER_SIZE-1][INNER_SIZE-1]);
}

// Main function
int main() {
    initialization();
    kernel();
    printResults();

    // Free allocated memory
    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < INNER_SIZE; j++) {
            free(matrix_A[i][j]);
            free(matrix_B[i][j]);
            free(result[i][j]);
            free(array[i][j]);
        }
        free(matrix_A[i]);
        free(matrix_B[i]);
        free(result[i]);
        free(array[i]);
    }
    free(matrix_A);
    free(matrix_B);
    free(result);
    free(array);

    return 0;
}
