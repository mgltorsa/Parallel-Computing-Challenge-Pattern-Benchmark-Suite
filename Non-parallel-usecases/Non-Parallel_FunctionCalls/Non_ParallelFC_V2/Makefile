CC = gcc
CCFLAGS = -g -fopenmp -O3
OUTPUT = *.out


none_parallelFC_V2_MINI_DATASET:
	$(CC) -o none_parallelFC_V2_MINI $(CCFLAGS) -DMINI_DATASET none_parallelFC_V2.c -lm

none_parallelFC_V2_SMALL_DATASET:
	$(CC) -o none_parallelFC_V2_SMALL $(CCFLAGS) -DSMALL_DATASET none_parallelFC_V2.c -lm 

none_parallelFC_V2_MEDIUM_DATASET:
	$(CC) -o none_parallelFC_V2_MEDIUM $(CCFLAGS) -DMEDIUM_DATASET none_parallelFC_V2.c -lm 

none_parallelFC_V2_LARGE_DATASET:
	$(CC) -o none_parallelFC_V2_LARGE $(CCFLAGS) -DLARGE_DATASET none_parallelFC_V2.c -lm 

none_parallelFC_V2_EXTRALARGE_DATASET:
	$(CC) -o none_parallelFC_V2_EXTRALARGE $(CCFLAGS) -DEXTRALARGE_DATASET none_parallelFC_V2.c -lm 


clean:
	rm -f none_parallelFC_V2_MINI $(OUTPUT) none_parallelFC_V2_SMALL $(OUTPUT) none_parallelFC_V2_MEDIUM $(OUTPUT) none_parallelFC_V2_LARGE $(OUTPUT) none_parallelFC_V2_EXTRALARGE $(OUTPUT)