#!/bin/bash

# Clean previous binaries
rm -f PA_Function_V1

# Compile with optimization flags
gcc -O2 -o PA_Function_V1 PA_Function_V1.c

# Run the program
./PA_Function_V1
