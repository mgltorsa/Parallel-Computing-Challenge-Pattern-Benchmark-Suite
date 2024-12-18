#!/bin/bash

# Example run script for the parallel version
# Ensure executable permission: chmod +x run_DA_Function_Parallel_V3.sh

# Compile the parallel version with OpenMP support

if [ $# -ne 1 ]; then
    echo "Usage: $0 [MINI|SMALL|LARGE]"
    exit 1
fi

DATASET=$1

# Define dataset size macros
case $DATASET in
    MINI)
        DEFINE="-DMINI_DATASET"
        ;;
    SMALL)
        DEFINE="-DSMALL_DATASET"
        ;;
    LARGE)
        DEFINE="-DLARGE_DATASET"
        ;;
    *)
        echo "Invalid dataset size. Choose from MINI, SMALL, or LARGE."
        exit 1
        ;;
esac


gcc -fopenmp -O2 -o DA_Function_Parallel_V3 DA_Function_Parallel_V3.c $DEFINE

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation of DA_Function_Parallel_V3.c failed."
    exit 1
fi

# Run the executable and store output
./DA_Function_Parallel_V3 > output_parallel.txt

# Check if execution was successful
if [ $? -ne 0 ]; then
    echo "Execution of DA_Function_Parallel_V3 failed."
    exit 1
fi

echo "Parallel version executed successfully. Output saved to output_parallel.txt."
