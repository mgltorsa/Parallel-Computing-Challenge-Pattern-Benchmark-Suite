#!/bin/bash

# Example usage: 
# ./run_DA_Function_V1.sh          # runs with default size
# ./run_DA_Function_V1.sh MINI     # runs with MINI_DATASET
# ./run_DA_Function_V1.sh SMALL    # runs with SMALL_DATASET
# ./run_DA_Function_V1.sh LARGE   # runs with LARGE_DATASET

DATASET_FLAG=""

if [ "$1" == "MINI" ]; then
    DATASET_FLAG="-DMINI_DATASET"
elif [ "$1" == "SMALL" ]; then
    DATASET_FLAG="-DSMALL_DATASET"
elif [ "$1" == "LARGE" ]; then
    DATASET_FLAG="-DLARGE_DATASET"
fi

# Compile the code
gcc $DATASET_FLAG -O3 -o DA_Function_V1 DA_Function_V1.c

# Run the code and save the output
./DA_Function_V1 > output_serial.txt
echo "Serial version run completed. Output in output_serial.txt"
