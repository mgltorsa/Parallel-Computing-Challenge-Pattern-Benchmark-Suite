#ifndef PA_FUNCTION_V3_H
#define PA_FUNCTION_V3_H

#ifdef MINI_DATASET
# define N 16
#elif defined(SMALL_DATASET)
# define N 20
#elif defined(LARGE_DATASET)
# define N 128
#else
# define N 128
#endif

#include <stdio.h>
#include <stdlib.h>

#define IDX(i,j,k) ((i)*N*N + (j)*N + (k))

void initialization(double *A, double *B, double *C, double *D, double *sum_array);
void kernel(double *A, double *B, double *C, double *D, double *sum_array);
void printResults(double *sum_array);

#endif
