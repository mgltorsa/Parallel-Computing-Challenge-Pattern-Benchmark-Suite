#!/usr/bin/env bash

# Compile and run the serial version
gcc -O2 -Wall -o PR_Function_V3 PR_Function_V3.c -lm
if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

# Run the program
./PR_Function_V3 > serial_output.txt
echo "Serial version executed. Output in serial_output.txt"
