/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/

import java.util.Scanner ;
import java.text.DecimalFormat;
public class Heron
{
public static void main(String[] args)
{

// input 
Scanner input = new Scanner(System.in) ;
DecimalFormat fmt = new DecimalFormat ("0.###");


// declare variables 
double
side1, side2 , side3 , S , Area ;

// prompt the user to enter the sides length
System.out.print ("Enter the length of side 1: ") ;
side1 = input.nextDouble ();

System.out.print ("Enter the length of side 2: ") ;
side2 = input.nextDouble ();

System.out.print ("Enter the length of side 3: ") ;
side3 = input.nextDouble ();
// The equation of Heron

S= (side1+side2+side3)/2 ;
Area= Math.sqrt(S*(S-side1)*(S-side2)*(S-side3));

// show results 
System.out.print("Area: " +fmt.format(Area)) ;

}
}



/*
The Goal of this program 

is to run  heron's formula which 

calculate the area of triangle with three sides.

*/