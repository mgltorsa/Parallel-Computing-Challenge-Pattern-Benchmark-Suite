#!/bin/bash

# Example run script for the serial version
# Ensure executable permission: chmod +x run_DA_Function_V3.sh

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


# Compile the code
gcc -O2 -o DA_Function_V3 DA_Function_V3.c $DEFINE

# Run the executable and store output
./DA_Function_V3 > output_serial.txt
