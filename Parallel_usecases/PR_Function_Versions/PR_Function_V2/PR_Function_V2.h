#ifndef PR_FUNCTION_V2_H
#define PR_FUNCTION_V2_H

// Dataset size selection logic:
// If MINI_DATASET is defined, use small sizes,
// else if SMALL_DATASET is defined, use slightly larger sizes,
// else if LARGE_DATASET is defined, use even larger sizes,
// else default to a large dataset.
#ifdef MINI_DATASET
#define N 16
#define M 16
#elif defined(SMALL_DATASET)
#define N 64
#define M 64
#elif defined(LARGE_DATASET)
#define N 100
#define M 100
#else
#define N 1024
#define M 1024
#endif

// Function prototypes
void initialization(double A[N][M], double B[N][M], double C[N][M], double D[N][M]);
void kernel(double A[N][M], double B[N][M], double C[N][M], double D[N][M]);
void printResults(double A[N][M]);

#endif
