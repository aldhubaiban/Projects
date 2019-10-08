#include <stdio.h>
#include"matrix_multi.h"

int main ()
{
  int first[M][M] ={
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

    int second[M][M] ={
     {1,2,3},
    {4,5,6},
    {7,8,9}
  };

    int third[M][M] ={
      {1,1,1},
     {1,1,1},
     {1,1,1}
   };
    int fourth[M][M] ={
      {4,4,4},
     {4,4,4},
     {4,4,4}
   };

     int multiply0[M][M];
     int multiply1[M][M];
     int multiply2[M][M];
     int multiply3[M][M];
   
  

  matrix_multiplication(first,second,multiply0);

  matrix_multiplication(first,third,multiply1);

  matrix_multiplication(first,fourth,multiply2);

  matrix_multiplication(third,fourth,multiply3);








  return 0;
}
