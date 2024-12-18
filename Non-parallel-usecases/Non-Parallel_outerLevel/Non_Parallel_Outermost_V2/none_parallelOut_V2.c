#include <stdio.h>
#include "none_parallelOut_V2.h"
#include <sys/time.h>
double A[N][M][P];

// Function prototypes
void initialization();
void kernel();
void printResults();

int main()
{
    initialization();
    struct timeval start_LOOP_1, end_LOOP_1;
    gettimeofday(&start_LOOP_1, NULL);
    // kernel();
    // kernelGPT4_V2();
    //kernelGPT4_V3();
    kernelGPT_CoT_V1();
    gettimeofday(&end_LOOP_1, NULL);
    printf("TimeInstrument_LOOP_1 = %0.8f \n", (((&end_LOOP_1)->tv_sec - (&start_LOOP_1)->tv_sec) + (1.0E-6 * ((&end_LOOP_1)->tv_usec - (&start_LOOP_1)->tv_usec))));

    printResults();
    return 0;
}

void initialization()
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            for (k = 0; k < P; k++)
            {
                A[i][j][k] = (double)(i + j + k) / P;
            }
        }
    }
}

void kernel()
{
    int i, j, k, l, m;
    for (i = 1; i < N - 1; i++)
    {
        for (j = 1; j < M - 1; j++)
        {
            for (k = 1; k < P - 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    for (m = -1; m <= 1; m++)
                    {
                        int ii = i + l;
                        int jj = j + m;
                        int kk = k + l * m;
                        if (ii >= 0 && ii < N && jj >= 0 && jj < M && kk >= 0 && kk < P)
                        {
                            A[i][j][k] += (A[ii][jj][kk] * A[i][j][k]) / (A[ii][jj][kk] + 1);
                        }
                    }
                }
            }
        }
    }
}



void printResults()
{
    int i, j, k;
    for (i = 0; i < N; i += N / 4)
    {
        for (j = 0; j < M; j += M / 4)
        {
            for (k = 0; k < P; k += P / 4)
            {
                printf("%0.2f ", A[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
