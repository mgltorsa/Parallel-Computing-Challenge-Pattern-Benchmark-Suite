#!/usr/bin/env bash

# run_PF_Function_V1.sh
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

# Uncomment one of these lines to select a dataset size:
# DATASET_FLAG="-D MINI_DATASET"
# DATASET_FLAG="-D SMALL_DATASET"
# DATASET_FLAG="-D MEDIUM_DATASET"
DATASET_FLAG=""  # Using default (STANDARD_DATASET) if none selected

echo "Compiling PF_Function_V1.c with $$DEFINE..."
gcc $$DEFINE -O2 -o PF_Function_V1 PF_Function_V1.c -lm

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    ./PF_Function_V1
else
    echo "Compilation failed."
    exit 1
fi
