#!/usr/bin/env bash

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



# Compile both versions
gcc -O2 -Wall -o PR_Function_V3 PR_Function_V3.c $DEFINE -lm
if [ $? -ne 0 ]; then
  echo "Serial compilation failed."
  exit 1
fi

gcc -O2 -fopenmp -Wall -o PR_Function_Parallel_V3 PR_Function_Parallel_V3.c $DEFINE -lm
if [ $? -ne 0 ]; then
  echo "Parallel compilation failed."
  exit 1
fi

# Run both versions
./PR_Function_V3 > serial_output.txt
./PR_Function_Parallel_V3 > parallel_output.txt

# Compare outputs
diff serial_output.txt parallel_output.txt
if [ $? -eq 0 ]; then
  echo "Outputs match."
else
  echo "Outputs differ!"
fi
