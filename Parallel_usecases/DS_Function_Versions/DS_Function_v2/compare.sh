#!/usr/bin/env bash

# This script compiles both the serial and parallel versions of the code
# with all the required compilation flags.

# Adjust dataset as needed:
# Options: -DMINI_DATASET, -DSMALL_DATASET, or -DMEDIUM_DATASET
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


# Compilation flags: Place -lm after the source files.
CFLAGS="-O2 -Wall -Wextra"

# Clean old binaries
rm -f DA_Function_V2_serial DA_Function_V2_parallel

# Compile the serial version
gcc $CFLAGS $DEFINE DA_Function_V2.c -o DA_Function_V2_serial -lm

# Compile the parallel version (with OpenMP)
gcc $CFLAGS $DEFINE -fopenmp DA_Function_Parallel_V2.c -o DA_Function_V2_parallel -lm

# Run the serial and parallel versions
./DA_Function_V2_serial > output_serial.txt
./DA_Function_V2_parallel > output_parallel.txt

# Compare the outputs
if diff output_serial.txt output_parallel.txt > /dev/null 2>&1; then
    echo "Outputs are the same."
else
    echo "Outputs differ."
    echo "Differences:"
    diff output_serial.txt output_parallel.txt
fi