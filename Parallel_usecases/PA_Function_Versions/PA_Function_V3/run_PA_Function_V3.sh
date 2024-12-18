#!/bin/bash

DATASET=$1
if [ -z "$DATASET" ]; then
    DATASET="MEDIUM_DATASET"
fi

rm -f PA_Function_V3

gcc -O3 -D $DATASET PA_Function_V3.c -o PA_Function_V3
./PA_Function_V3
