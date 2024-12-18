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


# Compile and run the serial version
gcc -O2 PR_Function_V1.c -o PR_Function_V1 $DEFINE
./PR_Function_V1 > serial_output.txt

# Compile and run the parallel version (with OpenMP)
gcc -O2 -fopenmp PR_Function_Parallel_V1.c -o PR_Function_Parallel_V1 $DEFINE
./PR_Function_Parallel_V1 > parallel_output.txt

# Compare outputs
diff -q serial_output.txt parallel_output.txt
if [ $? -eq 0 ]; then
    echo "Outputs are identical!"
else
    echo "Outputs differ!"
fi
