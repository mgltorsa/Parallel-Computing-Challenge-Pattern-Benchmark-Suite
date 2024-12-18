#!/bin/bash

# compare.sh

# Usage: ./compare.sh [DATASET_SIZE]
# DATASET_SIZE can be MINI, SMALL, or LARGE
# Example: ./compare.sh SMALL
rm -r parallel_output.txt serial_output.txt

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

# Compile the serial version
gcc -O2 -o NW_Function_V1 NW_Function_V1.c $DEFINE
if [ $? -ne 0 ]; then
    echo "Compilation of serial version failed."
    exit 1
fi

# Compile the parallel version with OpenMP
gcc -O2 -fopenmp -o NW_Function_Parallel_V1 NW_Function_Parallel_V1.c $DEFINE
if [ $? -ne 0 ]; then
    echo "Compilation of parallel version failed."
    exit 1
fi

# Run the serial version and capture output
./NW_Function_V1 > serial_output.txt

# Run the parallel version and capture output
./NW_Function_Parallel_V1 > parallel_output.txt

# Compare the outputs
diff serial_output.txt parallel_output.txt > /dev/null

if [ $? -eq 0 ]; then
    echo "Success: Serial and Parallel outputs match."
else
    echo "Error: Outputs do not match."
    echo "Differences:"
    diff serial_output.txt parallel_output.txt
fi

# Optionally, clean up
# rm serial_output.txt parallel_output.txt
