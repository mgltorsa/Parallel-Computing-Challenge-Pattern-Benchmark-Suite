#ifndef NON_PARALLELFC_V4_H
#define NON_PARALLELFC_V4_H

// Define dataset size if not already defined
#if !defined(MINI_DATASET) && !defined(SMALL_DATASET) && !defined(LARGE_DATASET)
#define SMALL_DATASET
#endif

#ifdef MINI_DATASET
#define N1 10
#define N2 10
#define N3 10
#endif

#ifdef SMALL_DATASET
#define N1 50
#define N2 50
#define N3 50
#endif

#ifdef LARGE_DATASET
#define N1 100
#define N2 100
#define N3 100
#endif

// Define a constant for array size based on the largest dimension
#define MAX_SIZE 1000

#endif // NON_PARALLELFC_V4_H
