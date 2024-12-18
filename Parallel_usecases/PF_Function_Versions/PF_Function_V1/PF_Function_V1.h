#ifndef PF_FUNCTION_V1_H
#define PF_FUNCTION_V1_H

// Define data sizes depending on which dataset is selected
#ifndef MINI_DATASET
#ifndef SMALL_DATASET
#ifndef LARGE_DATASET
// If no dataset is defined, use a default
#define STANDARD_DATASET
#endif
#endif
#endif

#ifdef MINI_DATASET
#define N 32
#endif

#ifdef SMALL_DATASET
#define N 50
#endif

#ifdef LARGE_DATASET
#define N 100
#endif

#ifdef STANDARD_DATASET
#define N 1024
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void initialization(double A[N][N], double B[N][N]);
void kernel(double A[N][N], double B[N][N]);
void printResults(double A[N][N]);

#endif // PF_FUNCTION_V1_H
