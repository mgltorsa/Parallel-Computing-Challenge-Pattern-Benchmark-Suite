#ifndef NON_PARALLELOUT_V4_H
#define NON_PARALLELOUT_V4_H

// Define data sizes based on dataset selection
// If none defined, default to MINI_DATASET

#if !defined(MINI_DATASET) && !defined(SMALL_DATASET) && !defined(LARGE_DATASET)
#define MINI_DATASET
#endif

#ifdef MINI_DATASET
    #define N 30
    #define M 30
#endif

#ifdef SMALL_DATASET
    #define N 50
    #define M 50
#endif

#ifdef LARGE_DATASET
    #define N 100
    #define M 100
#endif

#endif // NON_PARALLELOUT_V4_H
