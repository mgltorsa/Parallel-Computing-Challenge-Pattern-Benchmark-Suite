#ifndef PA_FUNCTION_V2_H
#define PA_FUNCTION_V2_H

// Define data sizes based on compilation flags
#if !defined(MINI_DATASET) && !defined(SMALL_DATASET) && !defined(LARGE_DATASET)
#define MINI_DATASET
#endif

#ifdef MINI_DATASET
#define N 10
#endif

#ifdef SMALL_DATASET
#define N 50
#endif

#ifdef LARGE_DATASET
#define N 100
#endif

// Declare global variables or structures as needed
extern double A[N][N][N];
extern double B[N][N][N];
extern double C[N][N][N];
extern double global_sum;

// Function prototypes
void initialization(void);
void kernel(void);
void printResults(void);

#endif // PA_FUNCTION_V2_H
