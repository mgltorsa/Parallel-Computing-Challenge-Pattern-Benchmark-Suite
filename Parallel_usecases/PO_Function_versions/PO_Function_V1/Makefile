CC = gcc
CCFLAGS = -g -fopenmp -O3
OUTPUT = *.out
DATA_SET =

parallelOutV1_MINI_DATASET:
	$(CC) -o parallelOut_V1_MINI $(CCFLAGS) -DMINI_DATASET parallelOut_V1.c -lm 

parallelOutV1_SMALL_DATASET:
	$(CC) -o parallelOut_V1_SMALL $(CCFLAGS) -DSMALL_DATASET parallelOut_V1.c -lm 

parallelOutV1_MEDIUM_DATASET:
	$(CC) -o parallelOut_V1_MEDIUM $(CCFLAGS) -DMEDIUM_DATASET parallelOut_V1.c -lm 

parallelOutV1_LARGE_DATASET:
	$(CC) -o parallelOut_V1_LARGE $(CCFLAGS) -DLARGE_DATASET parallelOut_V1.c -lm 

parallelOutV1_EXTRALARGE_DATASET:
	$(CC) -o parallelOut_V1_EXTRALARGE $(CCFLAGS) -DEXTRALARGE_DATASET parallelOut_V1.c -lm 


clean:
	rm -f parallelOut_V1_MINI $(OUTPUT) parallelOut_V1_SMALL $(OUTPUT) parallelOut_V1_MEDIUM $(OUTPUT) parallelOut_V1_LARGE $(OUTPUT) parallelOut_V1_EXTRALARGE $(OUTPUT)