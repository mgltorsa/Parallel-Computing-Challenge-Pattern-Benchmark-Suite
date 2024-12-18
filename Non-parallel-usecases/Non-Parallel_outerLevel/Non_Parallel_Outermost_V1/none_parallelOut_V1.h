#ifndef PARALLELOUT_V1_H
#define PARALLELOUT_V1_H

// Uncomment the dataset you wish to use
// #define MINI_DATASET
// #define SMALL_DATASET
// #define MEDIUM_DATASET
// #define LARGE_DATASET
// #define EXTRALARGE_DATASET

// Default dataset if none is selected
#ifndef MINI_DATASET
#ifndef SMALL_DATASET
#ifndef MEDIUM_DATASET
#ifndef LARGE_DATASET
#ifndef EXTRALARGE_DATASET
#define MINI_DATASET
#endif
#endif
#endif
#endif
#endif

// Define the size N based on the selected dataset
#if defined(MINI_DATASET)
    #define N 10
#elif defined(SMALL_DATASET)
    #define N 100
#elif defined(MEDIUM_DATASET)
    #define N 250
#elif defined(LARGE_DATASET)
    #define N 280
#elif defined(EXTRALARGE_DATASET)
    #define N 4000
#endif

#endif // PARALLELOUT_V1_H
