// parallelOut_v2.c

#include <stdio.h>
#include "none_parallelOut_V3.h"
#include <sys/time.h>
double A[N][N][N][N][N];
double B[N][N][N][N][N];

void initialization() {
    int i, j, k, l, m;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                for (l = 0; l < N; l++)
                    for (m = 0; m < N; m++) {
                        A[i][j][k][l][m] = (double)(i + j + k + l + m);
                        B[i][j][k][l][m] = (double)(i * j * k * l * m + 1) / (N * N * N * N * N);
                    }
}

void kernel() {
    int i, j, k, l, m;
    for (i = 1; i < N; i++)
        for (j = 1; j < N; j++)
            for (k = 1; k < N; k++)
                for (l = 1; l < N; l++)
                    for (m = 1; m < N; m++) {
                        A[i][j][k][l][m] = A[i - 1][j][k][l][m] * 0.5 + A[i][j - 1][k][l][m] * 0.4
                                         + A[i][j][k - 1][l][m] * 0.3 + A[i][j][k][l - 1][m] * 0.2
                                         + A[i][j][k][l][m - 1] * 0.1 + B[i][j][k][l][m];
                    }
}

void printResults() {
    int i, j, k, l, m;
    // Print a subset of the results to avoid overwhelming output
    for (i = 0; i < N; i += N / 2)
        for (j = 0; j < N; j += N / 2)
            for (k = 0; k < N; k += N / 2)
                for (l = 0; l < N; l += N / 2)
                    for (m = 0; m < N; m += N / 2) {
                        printf("A[%d][%d][%d][%d][%d] = %lf\n", i, j, k, l, m, A[i][j][k][l][m]);
                    }
}

int main() {
    initialization();

    struct timeval start_LOOP_1, end_LOOP_1;
    gettimeofday(&start_LOOP_1, NULL);

    kernel();

    gettimeofday(&end_LOOP_1, NULL);
    printf("TimeInstrument_LOOP_1 = %0.8f \n", (((&end_LOOP_1)->tv_sec - (&start_LOOP_1)->tv_sec) + (1.0E-6 * ((&end_LOOP_1)->tv_usec - (&start_LOOP_1)->tv_usec))));



    printResults();
    return 0;
}
