#include <stdio.h>
#include "none_parallelFC_V2.h"
#include <sys/time.h>
double global_var = 0.0;
static int static_var = 0;

/* Function prototypes */
void initialization(double array[N][N][N][N][N][N]);
void kernel(double array[N][N][N][N][N][N]);
void printResults(double array[N][N][N][N][N][N]);


/* void modify_argument(double *arg);
void side_effect_function(double value);
void write_data(double value);
double read_data(); */

void functionOperation(double value);

int main() {
    double array[N][N][N][N][N][N];
    initialization(array);

    struct timeval start_LOOP_1, end_LOOP_1;
    gettimeofday(&start_LOOP_1, NULL);    
    kernel2(array);
    gettimeofday(&end_LOOP_1, NULL);
    printf("TimeInstrument_LOOP_1 = %0.8f \n", (((&end_LOOP_1)->tv_sec - (&start_LOOP_1)->tv_sec) + (1.0E-6 * ((&end_LOOP_1)->tv_usec - (&start_LOOP_1)->tv_usec))));

    //printResults(array);
    return 0;
}

void initialization(double array[N][N][N][N][N][N]) {
    int i1,i2,i3,i4,i5,i6,i7,i8;
    for (i1 = 0; i1 < N; i1++)
        for (i2 = 0; i2 < N; i2++)
            for (i3 = 0; i3 < N; i3++)
                for (i4 = 0; i4 < N; i4++)
                    for (i5 = 0; i5 < N; i5++)
                        for (i6 = 0; i6 < N; i6++)
                                array[i1][i2][i3][i4][i5][i6] = (double)(i1+i2+i3+i4+i5+i6)/(8*N);
}

void kernel(double array[N][N][N][N][N][N]) {
    int i1,i2,i3,i4,i5,i6,i7,i8;
    for (i1 = 0; i1 < N; i1++)
        for (i2 = 0; i2 < N; i2++)
            for (i3 = 0; i3 < N; i3++)
                for (i4 = 0; i4 < N; i4++)
                    for (i5 = 0; i5 < N; i5++)
                        for (i6 = 0; i6 < N; i6++){
                                    double val = array[i1][i2][i3][i4][i5][i6];
                                    val += global_var;
                                    val *= (i1+1)*(i2+1)/(i3+1.0);
                                    val -= static_var;
                                    array[i1][i2][i3][i4][i5][i6] = val;
                                    if ((i1+i2+i3+i4+i5+i6) % 1000 == 0) {
                                        functionOperation(val);
                                    }
                                }
}

void kernel2(double array[N][N][N][N][N][N]) {
  int i1, i2, i3, i4, i5, i6;
    for (i1 = 0; i1 < N; i1++)
        for (i2 = 0; i2 < N; i2++)
            for (i3 = 0; i3 < N; i3++)
                for (i4 = 0; i4 < N; i4++)
                    for (i5 = 0; i5 < N; i5++) {
                        #pragma omp parallel for private(val)
                        for (i6 = 0; i6 < N; i6++) {
                            double val = array[i1][i2][i3][i4][i5][i6];
                            val += global_var;
                            val *= (i1 + 1) * (i2 + 1) / (i3 + 1.0);
                            val -= static_var;
                            array[i1][i2][i3][i4][i5][i6] = val;
                            if ((i1 + i2 + i3 + i4 + i5 + i6) % 1000 == 0) {
                                functionOperation(val);
                            }
                        }
                    }
}

void printResults(double array[N][N][N][N][N][N]) {
    int i1,i2,i3,i4,i5,i6,i7,i8;
    for (i1 = 0; i1 < N; i1++)
        for (i2 = 0; i2 < N; i2++)
            for (i3 = 0; i3 < N; i3++)
                for (i4 = 0; i4 < N; i4++)
                    for (i5 = 0; i5 < N; i5++)
                        for (i6 = 0; i6 < N; i6++)
                           {
                                    printf("%f ", array[i1][i2][i3][i4][i5][i6]);
                                }
    printf("\nGlobal variable: %f\n", global_var);
    printf("Static variable: %d\n", static_var);
}

/* void modify_global(double value) {
    global_var += value;
} */

/* void modify_argument(double *arg) {
    *arg += 1.0;
}
 */
void  functionOperation(double value) {
    static_var += (int)value % 10;
}

/* void write_data(double value) {
    printf("Writing value: %f\n", value);
}

double read_data() {
    double input;
    printf("Enter a value: ");
    scanf("%lf", &input);
    return input;
} */
