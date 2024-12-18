#!/bin/bash

# Script to compile and run Non_parallelFC_V4.c

# Define dataset size (uncomment one of the following lines as needed)
#export MINI_DATASET
#export SMALL_DATASET
#export LARGE_DATASET

# Compilation flags
CC=gcc
CFLAGS="-O2 -Wall -std=c99"

# Source and header files
SRC=Non_parallelFC_V4.c
HEAD=Non_parallelFC_V4.h
OUT=Non_parallelFC_V4.out

# Compile the program
$CC $CFLAGS -o $OUT $SRC

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run the executable
./$OUT
