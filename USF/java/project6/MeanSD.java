/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/

import java.util.*;

import java.text.*;


public class MeanSD
{
public static void main(String [] args)
{

// input
Scanner input= new Scanner (System.in);

// declare array
double array[]= new double [10];

System.out.print("enter the number: ");


//  a loop to prompt the user to input array numbers

for (int i = 0 ; i < array.length ; i++)
{array[i]=input.nextDouble();}


// print the average

System.out.println("The mean is "+mean(array));

// print the deviation

System.out.print("The standard deviation is "+deviation(array));

}// close main method 

// a method to count the avarage of the array 
public static double mean(double [] average)
{
// declare variable inside the method
double mean = 0 ;

// a loop to sum numerator
for (int i = 0; i < average.length ;i++)
{ mean += average[i];}

return mean / average.length  ;
}

// a method to count the deviation of the array

public static double deviation(double [] deviation)
{
// declare variable inside the method 
double numerator=0;
double totall;
// a loop to sum numerator
for(int i=0;i<deviation.length;i++)
{
numerator+= Math.pow(deviation[i]-mean(deviation),2);
}

// deviation formula
totall=numerator/(deviation.length-1);

return Math.sqrt(totall);
}

}