#ifndef PR_FUNCTION_V3_H
#define PR_FUNCTION_V3_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * Data sizes:
 * Use one of the following compilation flags:
 * -D MINI_DATASET
 * -D SMALL_DATASET
 * -D LARGE_DATASET
 * or define your own if needed.
 */

#ifndef MINI_DATASET
#ifndef SMALL_DATASET
#ifndef LARGE_DATASET
/* Default sizes if none defined */
#define N 50
#define M 50
#else
#define N 80
#define M 80
#endif
#else
#define N 100
#define M 100
#endif
#else
#define N 256
#define M 256
#endif

/* Global arrays */
extern double A[N][M];
extern double B[N][M];
extern double C[N][M];
extern double D[N][M];

/* Function prototypes */
void initialization();
void kernel();
void printResults();

#endif /* PR_FUNCTION_V3_H */
