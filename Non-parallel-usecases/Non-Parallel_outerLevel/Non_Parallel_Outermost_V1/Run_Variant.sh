#!/bin/bash
DATA_SIZE=${1}
ITERATIONS=${2}

if [ "$DATA_SIZE" = "MINI" ]; then
    make none_parallelOut_V1_MINI_DATASET
    for ((i=1; i<=ITERATIONS; i++)); do
        ./none_parallelOut_V1_MINI >> results_${DATA_SIZE}_${i}.txt
    done

elif [ "$DATA_SIZE" = "SMALL" ]; then
    make none_parallelOut_V1_SMALL_DATASET
    for ((i=1; i<=ITERATIONS; i++)); do
        ./none_parallelOut_V1_SMALL >> results_${DATA_SIZE}_${i}.txt
    done

elif [ "$DATA_SIZE" = "MEDIUM" ]; then
    make none_parallelOut_V1_MEDIUM_DATASET
    for ((i=1; i<=ITERATIONS; i++)); do
        ./none_parallelOut_V1_MEDIUM >> results_${DATA_SIZE}_${i}.txt
    done

elif [ "$DATA_SIZE" = "LARGE" ]; then
    make none_parallelOut_V1_LARGE_DATASET
    for ((i=1; i<=ITERATIONS; i++)); do
        ./none_parallelOut_V1_LARGE >> results_${DATA_SIZE}_${i}.txt
    done

elif [ "$DATA_SIZE" = "XLARGE" ]; then
    make none_parallelOut_V1_EXTRALARGE_DATASET
    for ((i=1; i<=ITERATIONS; i++)); do
        ./none_parallelOut_V1_EXTRALARGE >> results_${DATA_SIZE}_${i}.txt
    done

else
    echo "Invalid DATA_SIZE: $DATA_SIZE"
    echo "Please specify one of: MINI, SMALL, MEDIUM, LARGE, XLARGE"
    exit 1
fi