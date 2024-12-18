#!/usr/bin/env bash

# Example: compile and run the serial and parallel versions
# with medium dataset as default. 
# You can change -Dxxx_DATASET to MINI_DATASET or SMALL_DATASET if needed.

# Clean previous binaries
rm -f DA_Function_V2_serial DA_Function_V2_parallel output_serial.txt output_parallel.txt

# Compile the serial version
gcc -O2 -DMEDIUM_DATASET -o DA_Function_V2_serial DA_Function_V2.c -lm

# Compile the parallel version (with OpenMP)
gcc -O2 -fopenmp -DMEDIUM_DATASET -o DA_Function_V2_parallel DA_Function_Parallel_V2.c -lm

# Run and save outputs
./DA_Function_V2_serial > output_serial.txt
./DA_Function_V2_parallel > output_parallel.txt

echo "Serial and parallel runs completed. Outputs saved to output_serial.txt and output_parallel.txt."
