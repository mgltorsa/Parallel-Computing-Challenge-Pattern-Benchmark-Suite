#!/bin/bash

# Script to compile and run Non_parallelOut_V4.c

# Usage: ./run_Non_parallelOut_V4.sh [dataset]
# dataset can be: MINI, SMALL, LARGE
# Default is MINI

# Check for help argument
if [ "$1" == "-h" ] || [ "$1" == "--help" ]; then
    echo "Usage: $0 [dataset]"
    echo "dataset options: MINI, SMALL, LARGE"
    echo "If no dataset is specified, MINI_DATASET is used by default."
    exit 0
fi

DATASET=${1:-MINI}

# Set define based on dataset
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
        echo "Invalid dataset size. Choose from MINI, SMALL, LARGE."
        exit 1
        ;;
esac

# Compilation flags
CFLAGS="-O3 -Wall -std=c99 $DEFINE"

# Compiler
CC=gcc

# Output executable
OUT=Non_parallelOut_V4

# Compile
echo "Compiling with dataset size: $DATASET"
$CC $CFLAGS Non_parallelOut_V4.c -o $OUT

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run the executable
echo "Running the program..."
./$OUT
