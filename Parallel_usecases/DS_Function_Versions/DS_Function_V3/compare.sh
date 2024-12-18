#!/bin/bash

# This script compiles both the serial and parallel versions,
# runs them, and compares their outputs to ensure they match.

# Ensure executable permissions are set for run scripts
chmod +x run_DA_Function_V3.sh
chmod +x run_DA_Function_Parallel_V3.sh

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

echo "Compiling and running the serial version..."
./run_DA_Function_V3.sh $DEFINE
if [ $? -ne 0 ]; then
    echo "Serial version failed to compile or run."
    exit 1
fi

echo "Compiling and running the parallel version..."
./run_DA_Function_Parallel_V3.sh $DEFINE
if [ $? -ne 0 ]; then
    echo "Parallel version failed to compile or run."
    exit 1
fi

echo "Comparing outputs of serial and parallel versions..."

# Compare the outputs
diff output_serial.txt output_parallel.txt > /dev/null

if [ $? -eq 0 ]; then
    echo "SUCCESS: The output of the serial and parallel versions match."
else
    echo "ERROR: The outputs of the serial and parallel versions differ."
    echo "See 'output_serial.txt' and 'output_parallel.txt' for details."
    exit 1
fi

