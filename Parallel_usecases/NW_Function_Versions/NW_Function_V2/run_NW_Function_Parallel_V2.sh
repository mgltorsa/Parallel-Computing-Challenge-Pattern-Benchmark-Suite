#!/bin/bash

# Usage: ./run_NW_Function_Parallel_V2.sh [DATASET]
# DATASET can be MINI, SMALL, or LARGE. Default is LARGE.

DATASET=${1:-LARGE}

if [ "$DATASET" = "MINI" ]; then
    DEFINE="-D MINI_DATASET"
elif [ "$DATASET" = "SMALL" ]; then
    DEFINE="-D SMALL_DATASET"
else
    DEFINE="-D LARGE_DATASET"
fi

gcc -fopenmp -o NW_Function_Parallel_V2 NW_Function_Parallel_V2.c -O2 $DEFINE

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Running NW_Function_Parallel_V2 with $DATASET dataset..."
./NW_Function_Parallel_V2
