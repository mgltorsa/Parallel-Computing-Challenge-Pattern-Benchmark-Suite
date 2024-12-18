# PCB_SUITE_V1.0

To run a specific use case, navigate to the folder of the challenge pattern you want to execute and type the following command:


./compare.sh $DATA_SIZE

### The $DATA_SIZE can be MINI, SMALL, or LARGE.

This script ./compare.sh will execute the parallel version of the challenge pattern and the serial version, then compare both results to check if there is a match, which will represent correctness.

## Detailed Instructions
Navigate to the Challenge Pattern Directory:

Open your terminal and change to the directory containing the specific challenge pattern you wish to run. For example:


cd path/to/challenge-pattern

## Run the Comparison Script:

Execute the compare.sh script with the desired data size:

./compare.sh $DATA_SIZE

Replace $DATA_SIZE with one of the following options:

#### MINI: For a minimal dataset.
#### SMALL: For a small dataset.
#### LARGE: For a large dataset.

## Understanding the Script's Functionality:

The compare.sh script performs the following actions:

Executes the Parallel Version: Runs the parallel implementation of the selected challenge pattern.
Executes the Serial Version: Runs the serial (non-parallel) implementation of the same challenge pattern.
Compares Results: Checks if the outputs from both versions match to verify correctness.
Interpreting the Results:

Match Found: Indicates that both the parallel and serial versions produce identical results, confirming correctness.
Mismatch Found: Suggests a discrepancy between the two versions, indicating a potential issue in the parallel implementation.