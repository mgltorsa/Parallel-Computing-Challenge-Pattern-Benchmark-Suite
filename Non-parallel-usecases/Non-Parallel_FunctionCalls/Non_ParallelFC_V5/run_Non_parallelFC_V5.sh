#!/bin/bash

# Compilation settings
CC=gcc
CFLAGS="-O2 -Wall"

# Select dataset size by defining one of the following:
# Uncomment one of the lines below to choose the dataset size

# CFLAGS="$CFLAGS -DMINI_DATASET"
# CFLAGS="$CFLAGS -DSMALL_DATASET"
CFLAGS="$CFLAGS -DLARGE_DATASET"

# Output executable name
OUTPUT=Non_parallelFC_V5

# Compile the C program
echo "Compiling Non_parallelFC_V5.c with flags: $CFLAGS"
$CC $CFLAGS Non_parallelFC_V5.c -o $OUTPUT

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Compilation successful. Running the program..."

# Run the executable
./$OUTPUT

# End of script
