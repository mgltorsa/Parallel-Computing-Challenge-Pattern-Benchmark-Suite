// PF_Function_Parallel_V1.c

#include "PF_Function_V1.h"

// A side-effect-free function used within the kernel.
// It takes two double arguments and returns a computed value without modifying any global state.
static double side_effect_free_func(double x, double y) {
    return sin(x) * cos(y) + sqrt((x * y) + 1.0);
}

void initialization(double A[N][N], double B[N][N]) {
    // Initialize the arrays with some values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (double)((i * j) % 7) + 0.5;
            B[i][j] = (double)((i + j) % 9) + 1.5;
        }
    }
}

void kernel(double A[N][N], double B[N][N]) {

    static double A_new[N][N];

    #pragma omp parallel for collapse(2)
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            double val_center = B[i][j];
            double val_up     = B[i-1][j];
            double val_down   = B[i+1][j];
            double val_left   = B[i][j-1];
            double val_right  = B[i][j+1];

            // Call the side-effect-free function
            double computed_val = side_effect_free_func(val_up, val_right);

            A_new[i][j] = A[i][j] 
                          + computed_val 
                          + 0.3 * val_center 
                          - 0.2 * val_down 
                          + 0.1 * val_left;
        }
    }

    // Copy the updated values from A_new back to A
    // The border values are unchanged since we only updated from i=1 to N-2 and j=1 to N-2
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            A[i][j] = A_new[i][j];
        }
    }
}

void printResults(double A[N][N]) {
    // Print a small portion of the result to verify correctness
    // This avoids overwhelming output for large N
    int max_print = (N < 10) ? N : 10;
    for (int i = 0; i < max_print; i++) {
        for (int j = 0; j < max_print; j++) {
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Allocate static arrays on the stack
    static double A[N][N];
    static double B[N][N];

    initialization(A, B);
    kernel(A, B);
    printResults(A);

    return 0;
}
