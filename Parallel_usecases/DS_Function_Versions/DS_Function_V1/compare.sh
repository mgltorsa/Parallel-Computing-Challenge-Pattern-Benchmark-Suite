#!/bin/bash

# Usage: ./compare.sh [DATASET_SIZE]
# DATASET_SIZE can be MINI, SMALL, or LARGE
# Example: ./compare.sh SMALL

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


# Run the serial version
gcc -O3 -o DA_Function_V1 DA_Function_V1.c $DEFINE
./DA_Function_V1 > output_serial.txt

# Run the parallel version
gcc -fopenmp -O3 -o DA_Function_Parallel_V1 DA_Function_Parallel_V1.c $DEFINE
./DA_Function_Parallel_V1 > output_parallel.txt

# Compare outputs
echo "Comparing outputs..."
diff output_serial.txt output_parallel.txt

if [ $? -eq 0 ]; then
    echo "Outputs are the same."
else
    echo "Outputs differ!"
fi
