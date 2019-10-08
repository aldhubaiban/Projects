#include"matrix_multi.h"


 
void matrix_multiplication(data_t first[M][M],
		data_t second[M][M],
		data_t  multiply[M][M])
{
  int c=0; 
  int d=0 ;
  int k=0;
  sum_t sum = 0;
   
     for (c = 0; c < M; c++) {
       for (d = 0; d < M; d++) {
         for (k = 0; k < M; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
 
        multiply[c][d] = sum;
        sum = 0;
      }
    }
 


  
}
