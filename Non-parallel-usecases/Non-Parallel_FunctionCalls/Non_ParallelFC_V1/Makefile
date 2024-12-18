CC = gcc
CCFLAGS = -g -fopenmp -O3
OUTPUT = *.out


none_parallelFC_V1_MINI_DATASET:
	$(CC) -o none_parallelFC_V1_MINI $(CCFLAGS) -DMINI_DATASET none_parallelFC_V1.c -lm

none_parallelFC_V1_SMALL_DATASET:
	$(CC) -o none_parallelFC_V1_SMALL $(CCFLAGS) -DSMALL_DATASET none_parallelFC_V1.c -lm 

none_parallelFC_V1_MEDIUM_DATASET:
	$(CC) -o none_parallelFC_V1_MEDIUM $(CCFLAGS) -DMEDIUM_DATASET none_parallelFC_V1.c -lm 

none_parallelFC_V1_LARGE_DATASET:
	$(CC) -o none_parallelFC_V1_LARGE $(CCFLAGS) -DLARGE_DATASET none_parallelFC_V1.c -lm 

none_parallelFC_V1_EXTRALARGE_DATASET:
	$(CC) -o none_parallelFC_V1_EXTRALARGE $(CCFLAGS) -DEXTRALARGE_DATASET none_parallelFC_V1.c -lm 


clean:
	rm -f none_parallelFC_V1_MINI $(OUTPUT) none_parallelFC_V1_SMALL $(OUTPUT) none_parallelFC_V1_MEDIUM $(OUTPUT) none_parallelFC_V1_LARGE $(OUTPUT) none_parallelFC_V1_EXTRALARGE $(OUTPUT)