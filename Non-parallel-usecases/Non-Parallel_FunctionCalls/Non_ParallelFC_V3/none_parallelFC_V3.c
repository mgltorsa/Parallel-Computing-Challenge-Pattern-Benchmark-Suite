#include <stdio.h>
#include "none_parallelFC_V3.h"
#include <sys/time.h>
#include <omp.h>
double global_var = 0.0;
static int static_var = 0;

/* Function prototypes */
void initialization(double array[N][N][N][N][N]);
void kernel_GPT_CoT_3(double array[N][N][N][N][N]);
void printResults(double array[N][N][N][N][N]);
double read_data();
/* void modify_argument(double *arg);
void side_effect_function(double value);
void write_data(double value);
double read_data(); */

void functionOperation(double value);

int main()
{
    double array[N][N][N][N][N];
    initialization(array);

    struct timeval start_LOOP_1, end_LOOP_1;
    gettimeofday(&start_LOOP_1, NULL);
    kernel_GPT_CoT_3(array);
    gettimeofday(&end_LOOP_1, NULL);
    printf("TimeInstrument_LOOP_1 = %0.8f \n", (((&end_LOOP_1)->tv_sec - (&start_LOOP_1)->tv_sec) + (1.0E-6 * ((&end_LOOP_1)->tv_usec - (&start_LOOP_1)->tv_usec))));

    printResults(array);
    return 0;
}

void initialization(double array[N][N][N][N][N])
{
    int i1, i2, i3, i4, i5, i6, i7, i8;
    for (i1 = 0; i1 < N; i1++)
        for (i2 = 0; i2 < N; i2++)
            for (i3 = 0; i3 < N; i3++)
                for (i4 = 0; i4 < N; i4++)
                    for (i5 = 0; i5 < N; i5++)
                        array[i1][i2][i3][i4][i5] = (double)(i1 + i2 + i3 + i4 + i5) / (8 * N);
}

void kernel(double array[N][N][N][N][N])
{
    int i1, i2, i3, i4, i5, i6, i7, i8;
    for (i1 = 0; i1 < N; i1++)
        for (i2 = 0; i2 < N; i2++)
            for (i3 = 0; i3 < N; i3++)
                for (i4 = 0; i4 < N; i4++)
                    for (i5 = 0; i5 < N; i5++)
                    {
                        double val = array[i1][i2][i3][i4][i5];
                        val += global_var;
                        val *= (i1 + 1) * (i2 + 1) / (i3 + 1.0);
                        val -= static_var;
                        array[i1][i2][i3][i4][i5] = val;

                        double input = read_data();

                        array[i1][i2][i3][i4][i5] += input;
                    }
}

void kernel_GPT_IP_2(double array[N][N][N][N][N])
{
    int i1, i2, i3, i4, i5;
    #pragma omp parallel for private(i1, i2, i3, i4, i5)
    for (i1 = 0; i1 < N; i1++)
        for (i2 = 0; i2 < N; i2++)
            for (i3 = 0; i3 < N; i3++)
                for (i4 = 0; i4 < N; i4++)
                    for (i5 = 0; i5 < N; i5++)
                    {
                        double val = array[i1][i2][i3][i4][i5];
                        val += global_var;
                        val *= (i1 + 1) * (i2 + 1) / (i3 + 1.0);
                        val -= static_var;
                        array[i1][i2][i3][i4][i5] = val;
                        double input; 
                        #pragma omp critical
                        {
                            input = read_data();
                        
                             array[i1][i2][i3][i4][i5] += input;
                        }
                    }
}

void kernel_GPT_IP_3(double array[N][N][N][N][N])
{
    int i1, i2, i3, i4, i5;
   #pragma omp parallel for private(i1, i2, i3, i4, i5)
   for (i1 = 0; i1 < N; i1++)
       for (i2 = 0; i2 < N; i2++)
           for (i3 = 0; i3 < N; i3++)
               for (i4 = 0; i4 < N; i4++)
                   for (i5 = 0; i5 < N; i5++)
                   {
                       double val = array[i1][i2][i3][i4][i5];
                       val += global_var;
                       val *= (i1 + 1) * (i2 + 1) / (i3 + 1.0);
                       val -= static_var;
                       array[i1][i2][i3][i4][i5] = val;

                       double input;
                       #pragma omp critical
                       {
                           input = read_data();
                       }
                       array[i1][i2][i3][i4][i5] += input;
                   }
}
void kernel_GPT_CoT_2(double array[N][N][N][N][N])
{
    int i1, i2, i3, i4, i5;
   #pragma omp parallel for private(i2, i3, i4, i5) shared(array)
   for (i1 = 0; i1 < N; i1++)
       for (i2 = 0; i2 < N; i2++)
           for (i3 = 0; i3 < N; i3++)
               for (i4 = 0; i4 < N; i4++)
                   for (i5 = 0; i5 < N; i5++)
                   {
                       double val = array[i1][i2][i3][i4][i5];
                       val += global_var;
                       val *= (i1 + 1) * (i2 + 1) / (i3 + 1.0);
                       val -= static_var;
                       array[i1][i2][i3][i4][i5] = val;

                       double input;
                       #pragma omp critical
                       {
                           input = read_data();
                       }
                       array[i1][i2][i3][i4][i5] += input;
                   }

}

void kernel_GPT_CoT_3(double array[N][N][N][N][N]){
    int i1, i2, i3, i4, i5;
   
   #pragma omp parallel for private(i2, i3, i4, i5)
   for (i1 = 0; i1 < N; i1++)
       for (i2 = 0; i2 < N; i2++)
           for (i3 = 0; i3 < N; i3++)
               for (i4 = 0; i4 < N; i4++)
                   for (i5 = 0; i5 < N; i5++)
                   {
                       double val = array[i1][i2][i3][i4][i5];
                       val += global_var;
                       val *= (i1 + 1) * (i2 + 1) / (i3 + 1.0);
                       val -= static_var;
                       array[i1][i2][i3][i4][i5] = val;

                       double input;
                       #pragma omp critical
                       {
                           input = read_data();
                       }
                       array[i1][i2][i3][i4][i5] += input;
                   }

}

void printResults(double array[N][N][N][N][N])
{
    int i1, i2, i3, i4, i5, i6, i7, i8;
    for (i1 = 0; i1 < N; i1++)
        for (i2 = 0; i2 < N; i2++)
            for (i3 = 0; i3 < N; i3++)
                for (i4 = 0; i4 < N; i4++)
                    for (i5 = 0; i5 < N; i5++)
                    {
                        printf("%f ", array[i1][i2][i3][i4][i5]);
                    }
    /*  printf("\nGlobal variable: %f\n", global_var);
     printf("Static variable: %d\n", static_var); */
}

/* void modify_global(double value) {
    global_var += value;
} */

/* void modify_argument(double *arg) {
    *arg += 1.0;
}
 */
/* void functionOperation(double value)
{
    static_var += (int)value % 10;
} */
/*
void write_data(double value) {
    printf("Writing value: %f\n", value);
} */

double read_data()
{
    FILE *file;
    int value;

    file = fopen("data.txt", "r"); // Open the file in read mode
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Read an integer from the file
    if (fscanf(file, "%d", &value) != 1)
    {
        printf("Error reading integer from file\n");
        fclose(file);
        return 1;
    }
    return value;
}
