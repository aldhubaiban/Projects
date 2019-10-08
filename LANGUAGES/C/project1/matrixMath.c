
		/*
		Abdulrahman Aldhubaiban
		--------------------------------------------------------------------------------------------------------------------
		Summary - Write a C program that is able to view, add, or multiply two matrices input by the user. 
		After inputting the two matrices, the user should be presented with a menu of possible operations
			
			◦ View the matrices 
			◦ Add the matrices 
			◦ Multiply the matrices 
			◦ Quit the program 
		--------------------------------------------------------------------------------------------------------------------
		*/

#include <stdio.h>


// global variables 
float matrix_sum[0][0]; 
float matrix_multiplay[0][0]; 

int main (void)
{
// Declare variables 
int row1=0, column1=0,row2=0,column2=0 ;
char user_input;

//variables for loops 
int i_a=0, j_a=0, i_b=0, j_b=0 , i=0 , j=0,k=0 ;



// prompt the user to enter number of rows and columns  for matrix A

	printf("for matrix A: \n");
	printf("how many rows? ");
	scanf("%d", &row1);
	printf("\n");
	printf("how many columns? ");
	scanf("%d", &column1);

				float matrix_a[row1][column1];
// loading the first matrix
	for ( i_a=0; i_a<row1 ; i_a++)
{
	printf("enter %d values for row %d: ",column1, i_a);

		for( j_a=0;j_a<column1;j_a++)

		scanf("%f", &matrix_a[i_a][j_a]);
}

// prompt the user to enter number of rows and columns  for matrix B
	printf("for matrix B: \n");
	printf("how many rows? ");
	scanf("%d", &row2);
	printf("\n");
	printf("how many columns? ");
	scanf("%d", &column2);
	printf("\n");

	float matrix_b[row2] [column2];
// loading the second matrix
	for ( i_b=0; i_b<row2 ; i_b++)
	{
	printf("enter %d values for row %d: ",column2, i_b);

		for( j_b=0;j_b<column2;j_b++)

		scanf("%f", &matrix_b[i_b][j_b]);
	}


	do 
	{
	printf("\n");
		printf("*************************\n");
		printf("* v - View matrices     *\n");
		printf("* a - Add matrices      *\n");
		printf("* m - Multiply matrices *\n");
		printf("* q - Quit              *\n");
		printf("*************************\n\n");



	printf("Please select an operation: \n");
	scanf(" %c", &user_input);

switch(user_input)
{
	case 'v': printf(" A= \n");

			for ( i_a=0; i_a<row1; i_a++)
			{
				for ( j_a=0; j_a<column1; j_a++)
				{
				printf("%10.3f ",matrix_a[i_a][j_a] );
				}
			printf("\n");
			}



			printf("\n B= \n");

			for ( i_b=0; i_b<row2; i_b++)
			{
				for ( j_b=0; j_b<column2; j_b++)
				{
				printf("%10.3f ",matrix_b[i_b][j_b] );
				}

			printf("\n");
			}

	break;

	// addtion 
	case 'a':
	if (row1==row2 && column1==column2)
	{

		int print=0;

		for ( i=0; i<row1; i++)
		{
			for ( j=0; j<column1; j++)
         	{
        	 matrix_sum[i][j]= matrix_a[i][j]+matrix_b[i][j];
		
			if (print==0){printf("A + B=\n");  print++;}

			printf("%10.3f \t",matrix_sum[i][j] );
	     	}
		printf("\n");
		}

	}
	else 
	{
	printf("Cannot add matrices of different size\n");
	}
	break;

	case 'm':
	// multiplay
	if(column1==row2)
 	{
		int print=0;
		float sum=0;
			for (i=0; i<row1; i++)
    		{
				for (j=0; j<column2; j++)
         		{
					for (k=0;k<row2;k++)
             		{
					sum= sum+matrix_a[i][k]* matrix_b[k][j];
             		}

				// to reset "sum" in order to count the next value 
				matrix_multiplay[i][j]=sum;
				sum=0;

				// if statement to print statement once 
				if (print==0){printf("A * B=\n");  print++;}

				printf("%10.3f \t",matrix_multiplay[i][j]);
         		}
			printf("\n");
     		}

	 }

	else
	{
	printf("Cannot multiplay matrices\n ");
	}
	break;

	case 'q': 
printf("\n Exiting the program...\n");
	break;

}// ends of switch 

}while (user_input!='q');

	return 0 ; 
}