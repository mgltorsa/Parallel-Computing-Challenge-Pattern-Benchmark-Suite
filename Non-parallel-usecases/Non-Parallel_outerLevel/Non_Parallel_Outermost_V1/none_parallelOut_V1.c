#include <stdio.h>
#include "none_parallelOut_V1.h"
#include <sys/time.h>
// Function prototypes
void initialize(double A[N][N][N][N][N][N], double B[N][N][N][N][N][N]);
void kernel(double A[N][N][N][N][N][N], double B[N][N][N][N][N][N]);
void printResults(double A[N][N][N][N][N][N]);

int main() {
    // Declare the arrays
    static double A[N][N][N][N][N][N];
    static double B[N][N][N][N][N][N];

    // Initialize arrays
    initialize(A, B);

    // Perform the computation

    struct timeval start_LOOP_1, end_LOOP_1;
    gettimeofday(&start_LOOP_1, NULL);   
    kernel(A, B);
    gettimeofday(&end_LOOP_1, NULL);
    printf("TimeInstrument_LOOP_1 = %0.8f \n", (((&end_LOOP_1)->tv_sec - (&start_LOOP_1)->tv_sec) + (1.0E-6 * ((&end_LOOP_1)->tv_usec - (&start_LOOP_1)->tv_usec))));

    // Print the results
    printResults(A);

    return 0;
}

// Function to initialize arrays A and B
void initialize(double A[N][N][N][N][N][N], double B[N][N][N][N][N][N]) {
    // Initialize B with some values
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                for (int l = 0; l < N; l++)
                    for (int m = 0; m < N; m++)
                        for (int n = 0; n < N; n++)
                            B[i][j][k][l][m][n] = 1.0;  
}

// Kernel function with the six-level nested loop
void kernel(double A[N][N][N][N][N][N], double B[N][N][N][N][N][N]) {
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            for (int k = 1; k < N; k++)
                for (int l = 1; l < N; l++)
                    for (int m = 1; m < N; m++)
                        for (int n = 1; n < N; n++)
                            A[i][j][k][l][m][n] = A[i-1][j-1][k-1][l-1][m-1][n-1] + B[i][j][k][l][m][n];
}

// Function to print the results
void printResults(double A[N][N][N][N][N][N]) {
    // For demonstration, print the last element
    printf("Dataset Size N = %d\n", N);
    printf("A[%d][%d][%d][%d][%d][%d] = %f\n", N-1, N-1, N-1, N-1, N-1, N-1,
           A[N-1][N-1][N-1][N-1][N-1][N-1]);
}
