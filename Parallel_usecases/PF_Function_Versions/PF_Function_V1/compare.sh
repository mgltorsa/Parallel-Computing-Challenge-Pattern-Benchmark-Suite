#!/usr/bin/env bash

# compare.sh

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

# Function to compile a C file
compile_program() {
    local c_file=$1
    local output=$2
    local flags=$3

    echo "Compiling $c_file with flags: $flags"
    gcc $flags -O2 -o $output $c_file $DEFINE -lm

    if [ $? -ne 0 ]; then
        echo "Compilation failed for $c_file."
        exit 1
    fi
}

# Function to run a program and capture its output
run_program() {
    local executable=$1
    local output_file=$2

    echo "Running $executable..."
    ./$executable > $output_file

    if [ $? -ne 0 ]; then
        echo "Execution failed for $executable."
        exit 1
    fi
}

# Compile serial version
compile_program "PF_Function_V1.c" "PF_Function_V1" ""

# Compile parallel version with OpenMP
compile_program "PF_Function_Parallel_V1.c" "PF_Function_Parallel_V1" "-fopenmp"

# Run serial version
run_program "PF_Function_V1" "output_serial.txt"

# Run parallel version
run_program "PF_Function_Parallel_V1" "output_parallel.txt"

# Compare the outputs
echo "Comparing outputs..."
diff output_serial.txt output_parallel.txt > /dev/null

if [ $? -eq 0 ]; then
    echo "Success: Serial and Parallel outputs are identical."
else
    echo "Warning: Serial and Parallel outputs differ."
    echo "Differences:"
    diff output_serial.txt output_parallel.txt
fi

# Cleanup (optional)
# Uncomment the following lines if you want to remove executables and output files after comparison
# rm PF_Function_V1 PF_Function_Parallel_V1 output_serial.txt output_parallel.txt
