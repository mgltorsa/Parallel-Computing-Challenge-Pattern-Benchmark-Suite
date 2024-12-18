#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100  // Adjust size as needed

// Function prototypes
void initialize_data(int *data, int *indices);
int compute_sum(int *data, int *indices);
void print_sum(int sum);

int main() {
    int *data = (int *)malloc(N * N * N * N * sizeof(int));
    int *indices = (int *)malloc(N * N * N * N * sizeof(int));

    if (data == NULL || indices == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    initialize_data(data, indices);
    int sum = compute_sum(data, indices);
    print_sum(sum);

    // Clean up
    free(data);
    free(indices);

    return 0;
}

// Initialization function
void initialize_data(int *data, int *indices) {
    // Initialize the data array with some values
    for (int i = 0; i < N * N * N * N; ++i) {
        data[i] = i;
    }

    // Seed random number generator
    srand((unsigned)time(NULL));

    // Create random access patterns
    for (int i = 0; i < N * N * N * N; ++i) {
        indices[i] = rand() % (N * N * N * N);
    }
}

// Kernel function
int compute_sum(int *data, int *indices) {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                for (int l = 0; l < N; ++l) {
                    int index = i * N * N * N + j * N * N + k * N + l;
                    sum += data[indices[index]];
                }
            }
        }
    }
    return sum;
}

// Print function
void print_sum(int sum) {
    printf("Sum of accessed elements: %d\n", sum);
}
