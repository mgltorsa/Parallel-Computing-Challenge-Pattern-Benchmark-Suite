// parallelOut_v2.h

#ifndef PARALLELOUT_V2_H
#define PARALLELOUT_V2_H

// Define dataset sizes
#ifndef MINI_DATASET
#ifndef SMALL_DATASET
#ifndef MEDIUM_DATASET
#ifndef LARGE_DATASET
#ifndef EXTRALARGE_DATASET
// Default to MINI_DATASET if no dataset size is defined
#define MINI_DATASET
#endif
#endif
#endif
#endif
#endif

// Set the value of N based on the dataset size
#ifdef MINI_DATASET
#define N 10
#endif

#ifdef SMALL_DATASET
#define N 20
#endif

#ifdef MEDIUM_DATASET
#define N 30
#endif

#ifdef LARGE_DATASET
#define N 40
#endif

#ifdef EXTRALARGE_DATASET
#define N 50
#endif

#endif // PARALLELOUT_V2_H
