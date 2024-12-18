#ifndef PF_FUNCTION_V3_H
#define PF_FUNCTION_V3_H

/* Define problem sizes */
#if !defined(MINI_DATASET) && !defined(SMALL_DATASET) && !defined(LARGE_DATASET)
/* Default dataset sizes if none specified */
#define NI 512
#define NJ 512
#endif

#ifdef MINI_DATASET
#define NI 16
#define NJ 16
#endif

#ifdef SMALL_DATASET
#define NI 64
#define NJ 64
#endif

#ifdef LARGE_DATASET
#define NI 256
#define NJ 256
#endif

/* Function prototypes */
void initialization(double A[NI][NJ], double B[NI][NJ]);
void kernel(double A[NI][NJ], double B[NI][NJ]);
void printResults(double A[NI][NJ]);

#endif /* PF_FUNCTION_V3_H */
