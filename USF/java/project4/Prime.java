/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/

import java.util.*;
public class Prime
{
public static void main(String[] args)
{
// input 
Scanner input= new Scanner(System.in) ;


// Declare variable 
int Num;
String Response ; 

// loop of the loops 
do { 

// prompt the user to enter a number greater than 2
System.out.print("Please enter a number greater than 2: ");
Num= input.nextInt();

// loop to varify a number is greater than 2 
while (Num<= 2)
{System.out.print("Invalid Number. Enter a number greater than 2: ");
Num= input.nextInt();}

//a line counter 
int Line_counter=0;

System.out.print("The prime number from 2 to " + Num + " are\n");

//outer  loop condition 
for (int outter = 2; outter <= Num ; outter++) { 
// inner loop condition 
for(int inner = 2; inner <= outter; inner++) {

// if statment to write prime numbers 
if (outter==inner )  {
System.out.print( outter+" ");


// new line after print 10 numbers
Line_counter++;
if (Line_counter==10)  {
System.out.println("");
//rest to 0
Line_counter=0;}
}
// if statment to get rid of not prime numbers 
if(outter%inner==0)
{break;}


        } 
          }
          
// prompt the user to enter another number 
System.out.print("\nDo you want to enter another number?"+"\t\nenter yes or no ");
Response= input.next();

                  } 
while (Response.equalsIgnoreCase("yes")); 









}
}

