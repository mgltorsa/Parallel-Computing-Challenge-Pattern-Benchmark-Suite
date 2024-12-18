CC = gcc
CCFLAGS = -g -fopenmp -O3
OUTPUT = *.out


none_parallelOut_V3_MINI_DATASET:
	$(CC) -o none_parallelOut_V3_MINI $(CCFLAGS) -DMINI_DATASET none_parallelOut_V3.c -lm

none_parallelOut_V3_SMALL_DATASET:
	$(CC) -o none_parallelOut_V3_SMALL $(CCFLAGS) -DSMALL_DATASET none_parallelOut_V3.c -lm 

none_parallelOut_V3_MEDIUM_DATASET:
	$(CC) -o none_parallelOut_V3_MEDIUM $(CCFLAGS) -DMEDIUM_DATASET none_parallelOut_V3.c -lm 

none_parallelOut_V3_LARGE_DATASET:
	$(CC) -o none_parallelOut_V3_LARGE $(CCFLAGS) -DLARGE_DATASET none_parallelOut_V3.c -lm 

none_parallelOut_V3_EXTRALARGE_DATASET:
	$(CC) -o none_parallelOut_V3_EXTRALARGE $(CCFLAGS) -DEXTRALARGE_DATASET none_parallelOut_V3.c -lm 


clean:
	rm -f none_parallelOut_V3_MINI $(OUTPUT) none_parallelOut_V3_SMALL $(OUTPUT) none_parallelOut_V3_MEDIUM $(OUTPUT) none_parallelOut_V3_LARGE $(OUTPUT) none_parallelOut_V3_EXTRALARGE $(OUTPUT)