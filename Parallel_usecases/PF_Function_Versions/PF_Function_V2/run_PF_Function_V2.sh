#!/bin/bash

# Example compile script with flags
# Adjust flags and compiler as needed
CC=gcc
CFLAGS="-O3 -fopenmp -Wall"

# Clean old binaries
rm -f PF_Function_V2 PF_Function_Parallel_V2

# Compile the serial version
$CC $CFLAGS -o PF_Function_V2 PF_Function_V2.c

# Run the program
./PF_Function_V2
