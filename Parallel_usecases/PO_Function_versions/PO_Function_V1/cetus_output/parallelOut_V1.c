/*
Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it andor
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https:www.gnu.org/licenses/>. 
*/
/*
This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it. 
*/
/*
glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default. 
*/
/*
wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISOIEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters
*/
#include <stdio.h>
#include <stdlib.h>
/* #include <omp.h> */
#include "ParallelOut_V1.h"
#include "functions.h"
void ParallelOut_V1(int * data, int * indices, int num_rows, int num_cols_result, int num_cols_tmp, double * * result_matrix, double * * matrix_A, double * * coefficient_matrix, double * * matrix_B, double * * matrix_C, double * * matrix_D)
{
	int i, j, k, temp;
	/* Parallelized loop with OpenMP */
	/* #pragma omp parallel for private(i, j, k) */
	#pragma cetus private(j, k) 
	#pragma loop name ParallelOut_V1#0 
	#pragma cetus reduction(+: temp) 
	#pragma cetus parallel 
	#pragma omp parallel for if((10000<(((1L+(3L*num_rows))+((3L*num_cols_result)*num_rows))+(((6L*num_cols_result)*num_cols_tmp)*num_rows)))) private(j, k) reduction(+: temp)
	for (i=0; i<num_rows; i ++ )
	{
		#pragma cetus private(j, k) 
		#pragma cetus lastprivate(index) 
		#pragma loop name ParallelOut_V1#0#0 
		/* #pragma cetus reduction(+: temp)  */
		for (j=0; j<num_cols_result; j ++ )
		{
			#pragma cetus private(k) 
			#pragma cetus lastprivate(index) 
			#pragma loop name ParallelOut_V1#0#0#0 
			/* #pragma cetus reduction(+: temp)  */
			for (k=0; k<num_cols_tmp; k ++ )
			{
				int index = (((i*num_rows)*num_rows)*num_cols_result)+1;
				temp+=data[indices[index]];
				result_matrix[i][j]+=(matrix_A[i][k]*coefficient_matrix[k][j]);
				matrix_B[i][j]+=(matrix_C[i][k]*matrix_D[k][j]);
			}
		}
	}
	return ;
}

void Initialization(int * data, int * indices, int num_rows, int num_cols_result, int num_cols_tmp, double * * result_matrix, double * * matrix_A, double * * coefficient_matrix, double * * matrix_B, double * * matrix_C, double * * matrix_D)
{
	int i, j;
	int min = 1;
	int max = 10;
	/* Initialize the data array with some values */
	int i;
	#pragma cetus private(i) 
	#pragma loop name Initialization#0 
	#pragma cetus parallel 
	#pragma omp parallel for if((10000<(1L+((3L*num_rows)*num_rows)))) private(i)
	for (i=0; i<(num_rows*num_rows);  ++ i)
	{
		data[i]=i;
	}
	/* Create random access patterns */
	#pragma cetus private(i) 
	#pragma loop name Initialization#1 
	#pragma cetus parallel 
	#pragma omp parallel for if((10000<(1L+((103L*num_rows)*num_rows)))) private(i)
	for (i=0; i<(num_rows*num_rows);  ++ i)
	{
		indices[i]=(rand()%(num_rows*num_rows));
	}
	/* Initialize matrices with random values */
	#pragma cetus private(i, j) 
	#pragma loop name Initialization#2 
	#pragma cetus parallel 
	#pragma omp parallel for if((10000<(((1L+(4L*num_rows))+((104L*num_cols_result)*num_rows))+((204L*num_cols_tmp)*num_rows)))) private(i, j)
	for (i=0; i<num_rows; i ++ )
	{
		#pragma cetus private(j) 
		#pragma loop name Initialization#2#0 
		for (j=0; j<num_cols_tmp; j ++ )
		{
			matrix_A[i][j]=((rand()%((max-min)+1))+min);
			matrix_C[i][j]=((2.0+(rand()%((max-min)+1)))+min);
		}
		#pragma cetus private(j) 
		#pragma loop name Initialization#2#1 
		for (j=0; j<num_cols_result; j ++ )
		{
			result_matrix[i][j]=0.0;
			matrix_B[i][j]=((1.0+(rand()%((max-min)+1)))+min);
		}
	}
	#pragma cetus private(i, j) 
	#pragma loop name Initialization#3 
	#pragma cetus parallel 
	#pragma omp parallel for if((10000<((1L+(3L*num_cols_tmp))+((104L*num_cols_result)*num_cols_tmp)))) private(i, j)
	for (i=0; i<num_cols_tmp; i ++ )
	{
		#pragma cetus private(j) 
		#pragma loop name Initialization#3#0 
		for (j=0; j<num_cols_result; j ++ )
		{
			coefficient_matrix[i][j]=1.0;
			matrix_D[j][i]=((3.0+(rand()%((max-min)+1)))+min);
		}
	}
	return ;
}

void PrintResults(int num_rows, int num_cols_result, int num_cols_tmp, double * * result_matrix, double * * matrix_B)
{
	int i, j;
	/* Print a small part of the resulting matrices */
	printf("Result Matrix:\n");
	#pragma cetus private(i, j) 
	#pragma loop name PrintResults#0 
	for (i=0; i<num_rows; i ++ )
	{
		#pragma cetus private(j) 
		#pragma loop name PrintResults#0#0 
		for (j=0; j<num_cols_result; j ++ )
		{
			printf("%f ", result_matrix[i][j]);
		}
		printf("\n");
	}
	printf("Matrix_B:\n");
	#pragma cetus private(i, j) 
	#pragma loop name PrintResults#1 
	for (i=0; i<num_rows; i ++ )
	{
		#pragma cetus private(j) 
		#pragma loop name PrintResults#1#0 
		for (j=0; j<num_cols_result; j ++ )
		{
			printf("%f ", matrix_B[i][j]);
		}
		printf("\n");
	}
	return ;
}

int main()
{
	int i;
	int num_rows = 28;
	int num_cols_tmp = 30;
	int num_cols_result = 32;
	/* Allocate memory for matrices */
	double * * result_matrix = (double * * )malloc(num_rows*sizeof (double * ));
	double * * matrix_A = (double * * )malloc(num_rows*sizeof (double * ));
	double * * coefficient_matrix = (double * * )malloc(num_cols_tmp*sizeof (double * ));
	double * * matrix_B = (double * * )malloc(num_rows*sizeof (double * ));
	double * * matrix_C = (double * * )malloc(num_rows*sizeof (double * ));
	double * * matrix_D = (double * * )malloc(num_rows*sizeof (double * ));
	int * data = (int * )malloc((N*N)*sizeof (int));
	int * indices = (int * )malloc((N*N)*sizeof (int));
	int _ret_val_0;
	#pragma cetus private(i) 
	#pragma loop name main#0 
	#pragma cetus parallel 
	#pragma omp parallel for if((10000<(1L+(507L*num_rows)))) private(i)
	for (i=0; i<num_rows; i ++ )
	{
		result_matrix[i]=((double * )malloc(num_cols_result*sizeof (double)));
		matrix_A[i]=((double * )malloc(num_cols_tmp*sizeof (double)));
		matrix_B[i]=((double * )malloc(num_cols_result*sizeof (double)));
		matrix_C[i]=((double * )malloc(num_cols_result*sizeof (double)));
		matrix_D[i]=((double * )malloc(num_cols_result*sizeof (double)));
	}
	#pragma cetus private(i) 
	#pragma loop name main#1 
	#pragma cetus parallel 
	#pragma omp parallel for if((10000<(1L+(103L*num_cols_tmp)))) private(i)
	for (i=0; i<num_cols_tmp; i ++ )
	{
		coefficient_matrix[i]=((double * )malloc(num_cols_result*sizeof (double)));
	}
	/* Initialize matrices */
	Initialization(data, indices, num_rows, num_cols_result, num_cols_tmp, result_matrix, matrix_A, coefficient_matrix, matrix_B, matrix_C, matrix_D);
	/* Call the parllelized kernel function */
	ParallelOut_V1(data, indices, num_rows, num_cols_result, num_cols_tmp, result_matrix, matrix_A, coefficient_matrix, matrix_B, matrix_C, matrix_D);
	/* Print results */
	PrintResults(num_rows, num_cols_result, num_cols_tmp, result_matrix, matrix_B);
	/* Free allocated memory */
	#pragma cetus private(i) 
	#pragma loop name main#2 
	for (i=0; i<num_rows; i ++ )
	{
		free(result_matrix[i]);
		free(matrix_A[i]);
		free(matrix_B[i]);
		free(matrix_C[i]);
		free(matrix_D[i]);
	}
	#pragma cetus private(i) 
	#pragma loop name main#3 
	for (i=0; i<num_cols_tmp; i ++ )
	{
		free(coefficient_matrix[i]);
	}
	free(result_matrix);
	free(matrix_A);
	free(coefficient_matrix);
	free(matrix_B);
	free(matrix_C);
	free(matrix_D);
	_ret_val_0=0;
	return _ret_val_0;
}
