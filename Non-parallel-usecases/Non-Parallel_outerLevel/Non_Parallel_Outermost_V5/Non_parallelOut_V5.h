#ifndef NON_PARALLELOUT_V5_H
#define NON_PARALLELOUT_V5_H

// Define dataset sizes based on preprocessor directives
#if defined MINI_DATASET
    #define NX 30
    #define NY 30
#elif defined SMALL_DATASET
    #define NX 50
    #define NY 50
#elif defined LARGE_DATASET
    #define NX 100
    #define NY 100
#else
    #define NX 500
    #define NY 500
#endif

// Define the number of iterations for the kernel
#define NITERS 10

#endif // NON_PARALLELOUT_V5_H
