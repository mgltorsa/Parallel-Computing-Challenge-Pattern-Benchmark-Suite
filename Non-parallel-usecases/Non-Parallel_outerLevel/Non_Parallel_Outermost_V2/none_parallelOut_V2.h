#ifndef PARALLELOUT_V2_H
#define PARALLELOUT_V2_H

// Dataset size definitions
#ifndef MINI_DATASET
#ifndef SMALL_DATASET
#ifndef MEDIUM_DATASET
#ifndef LARGE_DATASET
#ifndef EXTRALARGE_DATASET

// Default dataset size
#define N 16
#define M 16
#define P 16
#define Q 16
#define R 16

#endif
#endif
#endif
#endif
#endif

#ifdef MINI_DATASET
#define N 16
#define M 16
#define P 16
#define Q 16
#define R 16
#endif

#ifdef SMALL_DATASET
#define N 32
#define M 32
#define P 32
#define Q 32
#define R 32
#endif

#ifdef MEDIUM_DATASET
#define N 64
#define M 64
#define P 64
#define Q 64
#define R 64
#endif

#ifdef LARGE_DATASET
#define N 128
#define M 128
#define P 128
#define Q 128
#define R 128
#endif

#ifdef EXTRALARGE_DATASET
#define N 256
#define M 256
#define P 256
#define Q 256
#define R 256
#endif

#endif // PARALLELOUT_V2_H
