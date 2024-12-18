#ifndef DA_FUNCTION_V2_H
#define DA_FUNCTION_V2_H

/* Data sizes: 
   The user can define one of MINI_DATASET, SMALL_DATASET, or LARGE_DATASET before compilation.
   Example: gcc -DMINI_DATASET ...
*/

#ifndef MINI_DATASET
#ifndef SMALL_DATASET
#ifndef LARGE_DATASET
#define LARGE_DATASET
#endif
#endif
#endif

#ifdef MINI_DATASET
#define N 16
#elif defined(SMALL_DATASET)
#define N 64
#elif defined(LARGE_DATASET)
#define N 256
#endif

// Function prototypes
void initialization(double A[N][N], double B[N][N]);
void kernel(double A[N][N], double B[N][N]);
void printResults(double A[N][N]);

#endif // DA_FUNCTION_V2_H
