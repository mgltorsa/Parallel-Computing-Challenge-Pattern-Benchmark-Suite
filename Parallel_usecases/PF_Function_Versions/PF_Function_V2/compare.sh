#!/bin/bash

# This script will run both the serial and parallel versions and compare their outputs.

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

# Ensure both are compiled
gcc -O3 -Wall -o PF_Function_V2 PF_Function_V2.c $DEFINE
gcc -O3 -fopenmp -Wall -o PF_Function_Parallel_V2 PF_Function_Parallel_V2.c $DEFINE

# Run both
./PF_Function_V2 > serial_output.txt
./PF_Function_Parallel_V2 > parallel_output.txt

# Compare
diff serial_output.txt parallel_output.txt

if [ $? -eq 0 ]; then
    echo "Outputs match!"
else
    echo "Outputs differ!"
fi
