// NW_Function_Parallel_V1.c
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "NW_Function_V1.h"

// Function to initialize the matrices and arrays
void initialization(double ****matrix_A, double ****matrix_B, double ****result, double ****array, double *sum) {
    int i, j, k;

    // Allocate memory for 3D arrays
    *matrix_A = (double ***)malloc(ARRAY_SIZE * sizeof(double **));
    *matrix_B = (double ***)malloc(ARRAY_SIZE * sizeof(double **));
    *result   = (double ***)malloc(ARRAY_SIZE * sizeof(double **));
    *array    = (double ***)malloc(ARRAY_SIZE * sizeof(double **));

    if (*matrix_A == NULL || *matrix_B == NULL || *result == NULL || *array == NULL) {
        fprintf(stderr, "Memory allocation failed for top-level arrays.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < ARRAY_SIZE; i++) {
        (*matrix_A)[i] = (double **)malloc(INNER_SIZE * sizeof(double *));
        (*matrix_B)[i] = (double **)malloc(INNER_SIZE * sizeof(double *));
        (*result)[i]   = (double **)malloc(INNER_SIZE * sizeof(double *));
        (*array)[i]    = (double **)malloc(INNER_SIZE * sizeof(double *));

        if ((*matrix_A)[i] == NULL || (*matrix_B)[i] == NULL || (*result)[i] == NULL || (*array)[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for second-level arrays.\n");
            exit(EXIT_FAILURE);
        }

        for (j = 0; j < INNER_SIZE; j++) {
            (*matrix_A)[i][j] = (double *)malloc(INNER_SIZE * sizeof(double));
            (*matrix_B)[i][j] = (double *)malloc(INNER_SIZE * sizeof(double));
            (*result)[i][j]   = (double *)malloc(INNER_SIZE * sizeof(double));
            (*array)[i][j]    = (double *)malloc(INNER_SIZE * sizeof(double));

            if ((*matrix_A)[i][j] == NULL || (*matrix_B)[i][j] == NULL ||
                (*result)[i][j] == NULL || (*array)[i][j] == NULL) {
                fprintf(stderr, "Memory allocation failed for third-level arrays.\n");
                exit(EXIT_FAILURE);
            }

            for (k = 0; k < INNER_SIZE; k++) {
                // Initialize matrices with some values
                (*matrix_A)[i][j][k] = (double)(i + j + k);
                (*matrix_B)[i][j][k] = (double)(i - j + k);
                (*result)[i][j][k]   = 0.0;
                (*array)[i][j][k]    = (double)(i * j * k);
            }
        }
    }

    *sum = 0.0;
}

// Kernel function with two nested level-3 loops, parallelized with OpenMP
void kernel(double ***matrix_A, double ***matrix_B, double ***result, double ***array, double *sum) {
    int i, j, k;

    double local_sum = 0.0;

    #pragma omp parallel private(i, j, k, local_sum) shared(matrix_A, matrix_B, result, array, sum)
    {
        local_sum = 0.0;

        #pragma omp for nowait
        for (i = 0; i < ARRAY_SIZE; i++) {
            for (j = 0; j < INNER_SIZE; j++) {
                for (k = 0; k < INNER_SIZE; k++) {
                    result[i][j][k] += matrix_A[i][j][k] * matrix_B[i][j][k] + (i - j) * (j - k);
                }
            }
        }

        #pragma omp for nowait
        for (i = 0; i < ARRAY_SIZE; i++) {
            for (j = 0; j < INNER_SIZE; j++) {
                for (k = 0; k < INNER_SIZE; k++) {
                    local_sum += array[i][j][k] / (1.0 + i + j + k);
                }
            }
        }

        #pragma omp atomic
        *sum += local_sum;
    }
}

// Function to print the results
void printResults(double sum) {
    printf("Final Sum: %lf\n", sum);
}

// Main function
int main(int argc, char *argv[]) {
    double ***matrix_A, ***matrix_B, ***result, ***array;
    double sum;

    initialization(&matrix_A, &matrix_B, &result, &array, &sum);
    kernel(matrix_A, matrix_B, result, array, &sum);
    printResults(sum);

    // Free allocated memory
    int i, j;
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = 0; j < INNER_SIZE; j++) {
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
