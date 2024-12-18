#!/bin/bash

# Usage: ./compare.sh [DATASET_SIZE]
# DATASET_SIZE can be MINI, SMALL, or LARGE
# Example: ./compare.sh SMALL

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


# Compile and run serial version
gcc -O3 $DEFINE PA_Function_V3.c -o PA_Function_V3_serial
./PA_Function_V3_serial > serial_output.txt

# Compile and run parallel version
gcc -fopenmp -O3 $DEFINE PA_Function_Parallel_V3.c -o PA_Function_V3_parallel
./PA_Function_V3_parallel > parallel_output.txt

# Compare outputs
diff serial_output.txt parallel_output.txt
if [ $? -eq 0 ]; then
    echo "The outputs are identical."
else
    echo "The outputs differ!"
fi
