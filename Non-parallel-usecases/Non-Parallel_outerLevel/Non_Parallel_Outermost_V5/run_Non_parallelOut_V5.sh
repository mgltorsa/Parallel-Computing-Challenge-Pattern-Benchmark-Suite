#!/bin/bash

# Script to compile and run Non_parallelOut_V5.c

# Usage: ./run_Non_parallelOut_V5.sh [mini|small|large]

# Set dataset size based on argument
if [ "$1" == "mini" ]; then
    DEFINES="-DMINI_DATASET"
    echo "Using MINI_DATASET"
elif [ "$1" == "small" ]; then
    DEFINES="-DSMALL_DATASET"
    echo "Using SMALL_DATASET"
elif [ "$1" == "large" ]; then
    DEFINES="-DLARGE_DATASET"
    echo "Using LARGE_DATASET"
else
    DEFINES=""
    echo "Using default dataset size"
fi

# Compile the C program
gcc -O2 -o Non_parallelOut_V5 Non_parallelOut_V5.c $DEFINES

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Compilation successful."

# Run the executable
./Non_parallelOut_V5

# End of script
