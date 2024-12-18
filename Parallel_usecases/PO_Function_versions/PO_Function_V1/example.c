#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100  // Adjust size as needed

int main() {
    int *data = (int *)malloc(N * N * N * N * sizeof(int));
    int *indices = (int *)malloc(N * N * N * N * sizeof(int));

    if (data == NULL || indices == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

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

    // 4-level loop nest with irregular data accesses
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

    printf("Sum of accessed elements: %d\n", sum);

    // Clean up
    free(data);
    free(indices);

    return 0;
}
