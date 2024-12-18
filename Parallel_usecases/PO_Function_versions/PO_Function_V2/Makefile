CC = gcc
CCFLAGS = -g -fopenmp -O3
OUTPUT = *.out
DATA_SET =

parallelOutV2_MINI_DATASET:
	$(CC) -o parallelOut_V2_MINI $(CCFLAGS) -DMINI_DATASET parallelOut_V2.c -lm 

parallelOutV2_SMALL_DATASET:
	$(CC) -o parallelOut_V2_SMALL $(CCFLAGS) -DSMALL_DATASET parallelOut_V2.c -lm 

parallelOutV2_MEDIUM_DATASET:
	$(CC) -o parallelOut_V2_MEDIUM $(CCFLAGS) -DMEDIUM_DATASET parallelOut_V2.c -lm 

parallelOutV2_LARGE_DATASET:
	$(CC) -o parallelOut_V2_LARGE $(CCFLAGS) -DLARGE_DATASET parallelOut_V2.c -lm 

parallelOutV2_EXTRALARGE_DATASET:
	$(CC) -o parallelOut_V2_EXTRALARGE $(CCFLAGS) -DEXTRALARGE_DATASET parallelOut_V2.c -lm 


clean:
	rm -f parallelOut_V2_MINI $(OUTPUT) parallelOut_V2_SMALL $(OUTPUT) parallelOut_V2_MEDIUM $(OUTPUT) parallelOut_V2_LARGE $(OUTPUT) parallelOut_V2_EXTRALARGE $(OUTPUT)