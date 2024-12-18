#include "PR_Function_V3.h"

/* Global arrays */
double A[N][M];
double B[N][M];
double C[N][M];
double D[N][M];

void initialization() {
    // Initialize arrays with some values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = (double)((i+1)*(j+1)) / (double)(N*M);
            B[i][j] = (double)((i+1)+(j+1)) / (double)(N+M);
            C[i][j] = 0.0;
            D[i][j] = (double)(i - j) / (double)(N);
        }
    }
}

void kernel() {

    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < M-1; j++) {
            C[i][j] = (A[i][j] * B[i][j]) + (A[i-1][j] * B[i+1][j]) 
                    - (A[i][j-1] * B[i][j+1]) + sqrt(fabs(D[i][j]));
        }
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < M-1; j++) {
            A[i][j] = A[i][j] + C[i+1][j+1]*0.5 - D[i][j]*C[i][j];
        }
    }

    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < M-1; j++) {
            D[i][j] = D[i][j] + sin(A[i][j]) * cos(B[i][j]) 
                    - 0.3*C[i][j] * A[i-1][j-1];
        }
    }
}

void printResults() {
    // Print a small subset of the arrays to verify correctness
    // Just printing top-left corner of the arrays
    printf("C[0][0] = %f\n", C[0][0]);
    printf("C[1][1] = %f\n", C[1][1]);
    printf("A[N-2][M-2] = %f\n", A[N-2][M-2]);
    printf("D[N-2][M-2] = %f\n", D[N-2][M-2]);
}

int main(int argc, char** argv) {
    initialization();
    kernel();
    printResults();
    return 0;
}
