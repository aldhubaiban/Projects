#ifndef MATRIX_MULTI_
#define MATRIX_MULTI_
//#define N 3
#define M 3
//#define K 3

typedef int data_t;
typedef int sum_t;

void matrix_multiplication(data_t first[M][M],
		data_t second[M][M],
		data_t multiply[M][M]);
#endif 
