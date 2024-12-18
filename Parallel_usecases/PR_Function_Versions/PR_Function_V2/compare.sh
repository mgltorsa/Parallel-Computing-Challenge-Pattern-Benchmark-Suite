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


# Compile serial version
gcc -O2 -o PR_Function_V2 PR_Function_V2.c $DEFINE

# Compile parallel version
gcc -O2 -fopenmp -o PR_Function_Parallel_V2 PR_Function_Parallel_V2.c $DEFINE

# Run both
./PR_Function_V2 > serial_output.txt
./PR_Function_Parallel_V2 > parallel_output.txt

# Compare outputs
diff serial_output.txt parallel_output.txt

if [ $? -eq 0 ]; then
    echo "Outputs are the same."
else
    echo "Outputs differ!"
fi
