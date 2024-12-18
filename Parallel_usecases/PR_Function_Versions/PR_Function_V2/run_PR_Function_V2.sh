#!/bin/bash

# Compile the serial code
gcc -O2 -o PR_Function_V2 PR_Function_V2.c

# Run and redirect output
./PR_Function_V2 > serial_output.txt
