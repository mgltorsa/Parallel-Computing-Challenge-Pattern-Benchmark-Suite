#!/bin/bash

# Compile the serial version with optimization flags

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


gcc -O2 -o PA_Function_V2 PA_Function_V2.c $DEFINE

# Run the serial version and save the output
./PA_Function_V2 > serial_output.txt

# Compile the parallel version with optimization and OpenMP flags
gcc -O2 -fopenmp -o PA_Function_Parallel_V2 PA_Function_Parallel_V2.c $DEFINE

# Run the parallel version and save the output
./PA_Function_Parallel_V2 > parallel_output.txt

# Compare the outputs
diff serial_output.txt parallel_output.txt
if [ $? -eq 0 ]; then
    echo "Outputs are the same."
else
    echo "Outputs differ!"
fi
