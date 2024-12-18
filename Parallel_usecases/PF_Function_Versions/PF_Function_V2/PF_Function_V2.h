#ifndef PF_FUNCTION_V2_H
#define PF_FUNCTION_V2_H

// Define dataset sizes depending on macros
// Default sizes if none are defined: LARGE_DATASET
// Possible defines: MINI_DATASET, SMALL_DATASET, LARGE_DATASET

#ifdef MINI_DATASET
# define N 16
# define M 16
#elif defined(SMALL_DATASET)
# define N 128
# define M 128
#elif defined(LARGE_DATASET)
# define N 512
# define M 512
#else
# define N 1024
# define M 1024
#endif

// Function prototypes
void initialization(double A[N][M], double B[N][M]);
void kernel(double A[N][M], double B[N][M], double C[N][M]);
void printResults(double C[N][M]);

#endif
