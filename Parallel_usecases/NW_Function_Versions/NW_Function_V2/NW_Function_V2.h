#ifndef NW_FUNCTION_V2_H
#define NW_FUNCTION_V2_H

// Define data sizes
#ifndef MINI_DATASET
#ifndef SMALL_DATASET
#ifndef MEDIUM_DATASET
#define MEDIUM_DATASET
#endif
#endif
#endif

#ifdef MINI_DATASET
#define ARRAY_SIZE 20
#define INNER_SIZE 20
#endif

#ifdef SMALL_DATASET
#define ARRAY_SIZE 60
#define INNER_SIZE 60
#endif

#ifdef LARGE_DATASET
#define ARRAY_SIZE 100
#define INNER_SIZE 100
#endif

// Function prototypes
void initialization();
void kernel();
void printResults();

#endif // NW_FUNCTION_V2_H
