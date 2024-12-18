#ifndef DA_FUNCTION_V1_H
#define DA_FUNCTION_V1_H

/* 
 * Define dataset sizes.
 * If no dataset size is defined externally (e.g., via -DMINI_DATASET), 
 * the code defaults to some standard size.
 */

#ifndef MINI_DATASET
#ifndef SMALL_DATASET
#ifndef LARGE_DATASET
/* Default dataset sizes (if none provided) */
#define NI 10
#define NJ 10
#define NK 10
#endif
#endif
#endif

#ifdef MINI_DATASET
#define NI 10
#define NJ 10
#define NK 10
#endif

#ifdef SMALL_DATASET
#define NI 50
#define NJ 50
#define NK 50
#endif

#ifdef LARGE_DATASET
#define NI 100
#define NJ 100
#define NK 100
#endif

/* Function prototypes */
void initialization(double A[NI][NJ][NK], double B[NI][NJ][NK], double C[NI][NJ][NK]);
void kernel(double A[NI][NJ][NK], double B[NI][NJ][NK], double C[NI][NJ][NK]);
void printResults(double A[NI][NJ][NK]);

#endif /* DA_FUNCTION_V1_H */
