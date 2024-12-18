#ifndef NON_PARALLELFV5_H
#define NON_PARALLELFV5_H

/* Data set size definitions */
#ifndef MINI_DATASET
#define MINI_DATASET 10
#endif

#ifndef SMALL_DATASET
#define SMALL_DATASET 50
#endif

#ifndef LARGE_DATASET
#define LARGE_DATASET 100
#endif

/* Select dataset size */
#ifdef MINI_DATASET
    #define DATA_SIZE MINI_DATASET
#elif defined(SMALL_DATASET)
    #define DATA_SIZE SMALL_DATASET
#elif defined(LARGE_DATASET)
    #define DATA_SIZE LARGE_DATASET
#else
    #define DATA_SIZE 100 /* Default size if none defined */
#endif

#endif /* NON_PARALLELFV5_H */
