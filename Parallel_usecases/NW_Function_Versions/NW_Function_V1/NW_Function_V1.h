// NW_Function_V1.h
#ifndef NW_FUNCTION_V1_H
#define NW_FUNCTION_V1_H

// Dataset size definitions
#ifndef MINI_DATASET
#ifndef SMALL_DATASET
#ifndef LARGE_DATASET
#error "Please define one dataset size: MINI_DATASET, SMALL_DATASET, or LARGE_DATASET"
#endif
#endif
#endif

#ifdef MINI_DATASET
#define ARRAY_SIZE 20
#define INNER_SIZE 20
#endif

#ifdef SMALL_DATASET
#define ARRAY_SIZE 50
#define INNER_SIZE 50
#endif

#ifdef LARGE_DATASET
#define ARRAY_SIZE 100
#define INNER_SIZE 100
#endif

// Function declarations
void initialization(double ****matrix_A, double ****matrix_B, double ****result, double ****array, double *sum);
void kernel(double ***matrix_A, double ***matrix_B, double ***result, double ***array, double *sum);
void printResults(double sum);

#endif // NW_FUNCTION_V1_H
