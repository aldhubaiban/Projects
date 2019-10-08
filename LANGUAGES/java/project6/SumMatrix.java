/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/

import java.util.*;
import java.text.*;


public class SumMatrix
{

public static void main(String[] args)
{

double [][] matrix1= new double [3] [3];
double [][] matrix2= new double [3] [3];


// first 2-D array
System.out.print("Enter matrix1:");
matrix(matrix1);
// second 2-D array
System.out.print("Enter matrix2:");
matrix(matrix2);

System.out.println();

System.out.println("The addition of the matrices is\n ");
//print first 2-D array 
print(matrix1);
System.out.println("\t\t+");
// print second 2-D array
print(matrix2);
System.out.println("\t\t=");
// add the two matrices
add(matrix1,matrix2);

}// main ends



//method for matrix  
public static void matrix(double [][] matrix)
{
Scanner input=new Scanner(System.in);

for(int i=0;i<matrix.length;i++)
{


for(int j=0;j<matrix[i].length;j++)
{
matrix[i][j]=input.nextDouble();
}


}

}

// method to print matrix 
public static void print(double [] [] print)
{
for(int i=0;i<print.length;i++)
{


for(int j=0;j<print[i].length;j++)
{
System.out.print(print[i][j]+ " ");
}

 System.out.println();
 
 
}
   
}
   

// method for the addition of matrices 
public static void add(double matrix1 [] [],double matrix2 [] [] )
{
double sum [][]=new double [matrix1.length] [matrix2.length] ;

for (int i= 0; i<sum.length; i++)
{
for (int j=0; j<sum[i].length; j++)
{
sum[i][j]= matrix1[i][j]+matrix2[i][j];

System.out.print(sum[i][j]+"  ");
}
System.out.println();
}

}


   
}// end of class

