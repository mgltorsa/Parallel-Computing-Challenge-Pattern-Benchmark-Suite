#!/bin/bash

# run_NW_Function_V1.sh

# Usage: ./run_NW_Function_V1.sh [DATASET_SIZE]
# DATASET_SIZE can be MINI, SMALL, or LARGE
# Example: ./run_NW_Function_V1.sh SMALL

if [ $# -ne 1 ]; then
    echo "Usage: $0 [MINI|SMALL|LARGE]"
    exit 1
fi

DATASET=$1

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

# Compile the serial version
gcc -O2 -o NW_Function_V1 NW_Function_V1.c $DEFINE

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run the program
./NW_Function_V1
