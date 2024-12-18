#!/usr/bin/env bash
set -e

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


# Compilation flags
CFLAGS="-O3 -std=c99"

# Compile both versions
gcc $CFLAGS -o PF_Function_V3 PF_Function_V3.c $DEFINE -lm
gcc $CFLAGS -o PF_Function_Parallel_V3 PF_Function_Parallel_V3.c $DEFINE -lm -fopenmp

# Run both
./PF_Function_V3 > output_serial.txt
./PF_Function_Parallel_V3 > output_parallel.txt

# Compare outputs
if diff output_serial.txt output_parallel.txt > /dev/null ; then
    echo "SUCCESS: The serial and parallel outputs match."
else
    echo "FAILURE: The outputs differ."
fi
