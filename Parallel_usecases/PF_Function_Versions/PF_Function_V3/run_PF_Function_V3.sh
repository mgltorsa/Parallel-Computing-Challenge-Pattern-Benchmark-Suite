#!/usr/bin/env bash
set -e

# Compilation flags (adjust as needed)
CFLAGS="-O3 -std=c99 -lm"

# Compile
gcc $CFLAGS -o PF_Function_V3 PF_Function_V3.c -lm

# Run and redirect output
./PF_Function_V3 > output_serial.txt
echo "Serial execution completed. Output in output_serial.txt"
