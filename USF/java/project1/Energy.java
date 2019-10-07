/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/

import java.util.Scanner;

public class Energy
{
public static void main(String[] args)
{

/*Constant: Specific Heat Capacity of water*/ 
final int Specific_Heat_Capacity = 4184 ;



// variables 
double Mass,

Initial_Temperature,

Final_Temperature,

 Energy;

// input 
Scanner input = new Scanner(System.in) ;


// make the user write the numbers of water and Delta temperature
System.out.println("Enter the amount of water in kilograms:");
Mass = input.nextDouble ();

System.out.println("Enter the initial temperature in degree Celsius:");
Initial_Temperature = input.nextDouble ();

System.out.println("Enter the final temperature in degree Celsius:");
Final_Temperature = input.nextDouble ();


// Energy function 
Energy= Mass * (Final_Temperature-Initial_Temperature) * Specific_Heat_Capacity ;


// show results 
System.out.println("The energy needed is " + Energy + " joules.");
}
}

/* the goal of the program 
is to calculate energy easily */ 
