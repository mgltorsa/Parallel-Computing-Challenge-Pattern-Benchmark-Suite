#include <stdio.h>
#include <stdlib.h>
/* #include <omp.h> */
#include "ParallelOut_V1.h"
#include "functions.h"

void ParallelOut_V1(int * data, int * indices, int num_rows, int num_cols_result, int num_cols_tmp, double **result_matrix, double **matrix_A, double **coefficient_matrix, double **matrix_B, double **matrix_C, double **matrix_D) {
    int i, j, k, temp;
    
    for (i = 0; i < num_rows; i++) {
        
        for (j = 0; j < num_cols_result; j++) {
            for (k = 0; k < num_cols_tmp; k++) {
                int index = i * num_rows * num_rows * num_cols_result + 1;
                temp += data[indices[index]];
                result_matrix[i][j] += matrix_A[i][k] * coefficient_matrix[k][j];
                matrix_B[i][j] += matrix_C[i][k] * matrix_D[k][j];
            }
            
        }
    }
}

void Initialization(int * data, int * indices, int num_rows, int num_cols_result, int num_cols_tmp,double **result_matrix, double **matrix_A, double **coefficient_matrix, double **matrix_B, double **matrix_C, double **matrix_D) {
    int i, j;
    int min = 1;
    int max = 10;


      // Initialize the data array with some values
    for (int i = 0; i < num_rows * num_rows; ++i) {
        data[i] = i;
    }

    // Create random access patterns
    for (int i = 0; i < num_rows * num_rows ; ++i) {
        indices[i] = rand() % (num_rows * num_rows);
    }

    // Initialize matrices with random values
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols_tmp; j++) {
            matrix_A[i][j] = rand() % (max - min + 1) + min;
            matrix_C[i][j] = 2.0 + rand() % (max - min + 1) + min;
            
        }
        for (j = 0; j < num_cols_result; j++) {
            result_matrix[i][j] = 0.0;
            matrix_B[i][j] = 1.0 + rand() % (max - min + 1) + min;
            
            
        }
    }

    for (i = 0; i < num_cols_tmp; i++) {
        for (j = 0; j < num_cols_result; j++) {
            coefficient_matrix[i][j] = 1.0;
            matrix_D[j][i] = 3.0 + rand() % (max - min + 1) + min;
        }
    }
}

void PrintResults(int num_rows, int num_cols_result, int num_cols_tmp, double **result_matrix, double **matrix_B) {
    int i, j;
    
    // Print a small part of the resulting matrices
    printf("Result Matrix:\n");
    for (i = 0; i < (num_rows ); i++) {
        for (j = 0; j < (num_cols_result); j++) {
            printf("%f ", result_matrix[i][j]);
        }
        printf("\n");
    }

    printf("Matrix_B:\n");
    for (i = 0; i < (num_rows ); i++) {
        for (j = 0; j < (num_cols_result ); j++) {
            printf("%f ", matrix_B[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i;
    int num_rows=28;
	int num_cols_tmp=30;
	int num_cols_result=32;
    // Allocate memory for matrices
    double **result_matrix = (double **)malloc(num_rows * sizeof(double *));
    double **matrix_A = (double **)malloc(num_rows * sizeof(double *));
    double **coefficient_matrix = (double **)malloc(num_cols_tmp * sizeof(double *));
    double **matrix_B = (double **)malloc(num_rows * sizeof(double *));
    double **matrix_C = (double **)malloc(num_rows * sizeof(double *));
    double **matrix_D = (double **)malloc(num_rows * sizeof(double *));

     int *data = (int *)malloc(N * N * sizeof(int));
    int *indices = (int *)malloc(N * N * sizeof(int));

  

    for (i = 0; i < num_rows; i++) {
        result_matrix[i] = (double *)malloc(num_cols_result * sizeof(double));
        matrix_A[i] = (double *)malloc(num_cols_tmp * sizeof(double));
        matrix_B[i] = (double *)malloc(num_cols_result * sizeof(double));
        matrix_C[i] = (double *)malloc(num_cols_result * sizeof(double));
        matrix_D[i] = (double *)malloc(num_cols_result * sizeof(double));
    }

    for (i = 0; i < num_cols_tmp; i++) {
        coefficient_matrix[i] = (double *)malloc(num_cols_result * sizeof(double));
    }

    	/* Initialize matrices */
	Initialization(  data, indices, num_rows,  num_cols_result,  num_cols_tmp, result_matrix, matrix_A, coefficient_matrix, matrix_B, matrix_C, matrix_D);
	/* Call the parllelized kernel function */
	ParallelOut_V1(data, indices, num_rows,  num_cols_result,  num_cols_tmp,result_matrix, matrix_A, coefficient_matrix, matrix_B, matrix_C, matrix_D);
	/* Print results */
	PrintResults( num_rows,  num_cols_result,  num_cols_tmp,result_matrix, matrix_B);

    // Free allocated memory
    for (i = 0; i < num_rows; i++) {
        free(result_matrix[i]);
        free(matrix_A[i]);
        free(matrix_B[i]);
        free(matrix_C[i]);
        free(matrix_D[i]);
    }

    for (i = 0; i < num_cols_tmp; i++) {
        free(coefficient_matrix[i]);
    }

    free(result_matrix);
    free(matrix_A);
    free(coefficient_matrix);
    free(matrix_B);
    free(matrix_C);
    free(matrix_D);

    return 0;
}
