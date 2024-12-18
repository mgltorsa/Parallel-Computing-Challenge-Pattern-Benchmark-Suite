#ifndef PA_FUNCTION_V1_H
#define PA_FUNCTION_V1_H

/* If no dataset size is specified, default to LARGE_DATASET */
#if !defined(MINI_DATASET) && !defined(SMALL_DATASET) && !defined(LARGE_DATASET)
# define LARGE_DATASET
#endif

#ifdef MINI_DATASET
# define N 16
#endif

#ifdef SMALL_DATASET
# define N 64
#endif

#ifdef LARGE_DATASET
# define N 256
#endif

#endif /* PA_FUNCTION_V1_H */
