#ifndef PARALLELIZINGOUTERLOOP_H
#define PARALLELIZINGOUTERLOOP_H

// Define different data sizes
#ifdef MINI_DATASET
#define num_rows 10
#define num_cols_tmp 10
#define num_cols_result 10
#endif

#ifdef SMALL_DATASET
#define num_rows 30
#define num_cols_tmp 30
#define num_cols_result 30
#endif

#ifdef MEDIUM_DATASET
#define num_rows 50
#define num_cols_tmp 50
#define num_cols_result 50
#endif

#ifdef LARGE_DATASET
#define num_rows 100
#define num_cols_tmp 100
#define num_cols_result 100
#endif


#endif // PARALLELIZINGOUTERLOOP_H
