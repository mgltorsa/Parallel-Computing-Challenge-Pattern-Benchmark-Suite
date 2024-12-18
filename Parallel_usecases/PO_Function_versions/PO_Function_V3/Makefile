CC = gcc
CCFLAGS = -g -fopenmp -O3
OUTPUT = *.out


parallelOutV3_MINI_DATASET:
	$(CC)  -o parallelOut_V3_MINI $(CCFLAGS) -DMINI_DATASET  parallelOut_V3.c -lm 

parallelOutV3_LARGE_DATASET:
	$(CC) -o parallelOut_V3_LARGE $(CCFLAGS) -DLARGE_DATASET parallelOut_V3.c -lm 

parallelOutV3_EXTRALARGE_DATASET:
	$(CC) -o parallelOut_V3_EXTRALARGE $(CCFLAGS) -DEXTRALARGE_DATASET parallelOut_V3.c -lm 


clean:
	rm -f parallelOut_V3_MINI $(OUTPUT) parallelOut_V3_SMALL $(OUTPUT) parallelOut_V3_MEDIUM $(OUTPUT) parallelOut_V3_LARGE $(OUTPUT) parallelOut_V3_EXTRALARGE $(OUTPUT)