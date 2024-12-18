#ifndef DA_FUNCTION_V3_H
#define DA_FUNCTION_V3_H

/* Define problem size based on dataset macros:
 * If none are defined, we default to MINI_DATASET.
 */

#ifndef MINI_DATASET
#ifndef SMALL_DATASET
#ifndef LARGE_DATASET
  /* Default dataset if no macro is defined */
  #define MINI_DATASET
#endif
#endif
#endif

#ifdef MINI_DATASET
#define N 32
#endif

#ifdef SMALL_DATASET
#define N 50
#endif

#ifdef LARGE_DATASET
#define N 200
#endif

#endif // DA_FUNCTION_V3_H
