#!/bin/bash

# Usage: ./compare.sh [DATASET]
# DATASET can be MINI, SMALL, or LARGE. Default is MINI.

rm serial_output.txt parallel_output.txt

DATASET=${1:-MEDIUM}

if [ "$DATASET" = "SMALL" ]; then
    DEFINE="-D SMALL_DATASET"
elif [ "$DATASET" = "LARGE" ]; then
    DEFINE="-D LARGE_DATASET"
else
    DEFINE="-D MINI_DATASET"
fi

# Compile serial version
gcc -o NW_Function_V2 NW_Function_V2.c -O2 $DEFINE
if [ $? -ne 0 ]; then
    echo "Compilation of serial version failed."
    exit 1
fi

# Compile parallel version
gcc -fopenmp -o NW_Function_Parallel_V2 NW_Function_Parallel_V2.c -O2 $DEFINE
if [ $? -ne 0 ]; then
    echo "Compilation of parallel version failed."
    exit 1
fi

# Run serial version
./NW_Function_V2 > serial_output.txt

# Run parallel version
./NW_Function_Parallel_V2 > parallel_output.txt

# Compare outputs
diff serial_output.txt parallel_output.txt > /dev/null

if [ $? -eq 0 ]; then
    echo "SUCCESS: Serial and Parallel outputs match."
else
    echo "ERROR: Outputs do not match."
    echo "Differences:"
    diff serial_output.txt parallel_output.txt
fi

# Clean up
#rm serial_output.txt parallel_output.txt
