#!/bin/bash

# Compile the serial version
rm -r serial_output.txt parallel_output.txt

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


gcc -O2 -o PA_Function_V1 PA_Function_V1.c $DEFINE

# Compile the parallel version (with OpenMP)
gcc -fopenmp -O2 -o PA_Function_Parallel_V1 PA_Function_Parallel_V1.c $DEFINE

# Run the serial version
./PA_Function_V1 > serial_output.txt

# Run the parallel version
./PA_Function_Parallel_V1 > parallel_output.txt

# Compare outputs
if diff serial_output.txt parallel_output.txt > /dev/null ; then
    echo "Outputs are the same"
else
    echo "Outputs differ!"
fi
