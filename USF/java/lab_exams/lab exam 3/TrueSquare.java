/*I pledge my Honor that i have not cheated, and will not cheat, on this test*/


import java.util.*;

import java.text.*;

public class TrueSquare
{

public static void main(String [] args)
{

// array
int  [][] table= new int [6][6];


// loading array
for (int i=1;i<table.length; i++){

for( int j=1; j<table[i].length; j++)
{
table[i][j]= j*i*i*j;


}

}


// print array 
for (int i=1; i<table.length; i++){

for (int j=1; j<table[i].length; j++)

{

System.out.print(table[i][j] + "\t");


}

System.out.println();

}



}


}