#ifndef PARALLELOUT_V3_H
#define PARALLELOUT_V3_H

/* Default to LARGE_DATASET if no dataset size is defined */
#ifndef MINI_DATASET
#ifndef SMALL_DATASET
#ifndef MEDIUM_DATASET
#ifndef LARGE_DATASET
#ifndef EXTRALARGE_DATASET
#define LARGE_DATASET
#endif
#endif
#endif
#endif
#endif

/* Define dataset sizes */
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

#endif /* PARALLELOUT_V2_H */
