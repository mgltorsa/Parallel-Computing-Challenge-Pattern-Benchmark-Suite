#include "PA_Function_V3.h"

void initialization(double *A, double *B, double *C, double *D, double *sum_array)
{
    for (int i = 0; i < N; i++) {
        sum_array[i] = 0.0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                int idx = IDX(i,j,k);
                A[idx] = (double)(i + j + k + 1);
                B[idx] = (double)(i*j + k + 2);
                C[idx] = (double)(i - j + k*2 + 3);
                D[idx] = (double)(i*j*k + 4);
            }
        }
    }
}

void kernel(double *A, double *B, double *C, double *D, double *sum_array)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                int idx = IDX(i,j,k);
                double val = A[idx]*B[idx]
                           + C[idx] - D[idx]
                           + (A[idx]*C[idx])
                           - (B[idx]*D[idx])
                           + (A[idx]*B[idx]*C[idx]*0.001)
                           - (D[idx]*0.002);
                sum_array[i] += val;
            }
        }
    }
}

void printResults(double *sum_array)
{
    double total_sum = 0.0;
    for (int i = 0; i < N; i++) {
        total_sum += sum_array[i];
    }
    printf("Final sum: %lf\n", total_sum);
}

int main(int argc, char** argv)
{
    double *A = (double *)malloc(sizeof(double)*N*N*N);
    double *B = (double *)malloc(sizeof(double)*N*N*N);
    double *C = (double *)malloc(sizeof(double)*N*N*N);
    double *D = (double *)malloc(sizeof(double)*N*N*N);
    double *sum_array = (double *)malloc(sizeof(double)*N);

    if (!A || !B || !C || !D || !sum_array) {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        return 1;
    }

    initialization(A, B, C, D, sum_array);
    kernel(A, B, C, D, sum_array);
    printResults(sum_array);

    free(A);
    free(B);
    free(C);
    free(D);
    free(sum_array);

    return 0;
}
