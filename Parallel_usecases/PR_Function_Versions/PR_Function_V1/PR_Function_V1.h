#ifndef PR_FUNCTION_V1_H
#define PR_FUNCTION_V1_H

// Dataset size selection
// If none are defined, default to MINI_DATASET
#ifndef MINI_DATASET
  #ifndef SMALL_DATASET
    #ifndef LARGE_DATASET
      #define MINI_DATASET
    #endif
  #endif
#endif

#if defined(MINI_DATASET)
  #define N 32
#elif defined(SMALL_DATASET)
  #define N 256
#elif defined(LARGE_DATASET)
  #define N 1024
#else
  #define N 32
#endif

#endif /* PR_FUNCTION_V1_H */
