#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "parallelOut_V3.h"
// Initialization function
void initialize_data(int *data, int *indices, int size) {
    // Initialize the data array with some values
    for (int i = 0; i < size * size * size * size; ++i) {
        data[i] = i;
    }

    // Seed random number generator
    srand((unsigned)time(NULL));

    // Create random access patterns
    for (int i = 0; i < size * size * size * size; ++i) {
        indices[i] = rand() % (size * size * size * size);
    }
}

// Kernel function
int compute_sum(int *data, int *indices, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                for (int l = 0; l < size; ++l) {
                    int position = i * size * size * size ;
                    int index = position + j * size * size + k * size + l ;
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

int main() {
    int size = ELEMENTS;
    int *data = (int *)malloc(size * size * size * size * sizeof(int));
    int *indices = (int *)malloc(size * size * size * size * sizeof(int));

    if (data == NULL || indices == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    initialize_data(data, indices, size);
    int sum = compute_sum(data, indices, size);
    print_sum(sum);

    // Clean up
    free(data);
    free(indices);

    return 0;
}
