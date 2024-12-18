#!/bin/bash

# Compile the serial version
gcc -O2 PR_Function_V1.c -o PR_Function_V1

# Run the program
./PR_Function_V1 > serial_output.txt
echo "Serial version completed. Output written to serial_output.txt"
