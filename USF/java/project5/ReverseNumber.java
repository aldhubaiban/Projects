/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/

import java.util.*;

public class ReverseNumber
{
   
public static void main(String[] args)
{

// Declare variables
int number, lastDigit=0, reverse = 0;

//Scannner
Scanner input = new Scanner(System.in);

// prompt user to enter a postive number
System.out.print("Enter a positive integer: ");
number = input.nextInt();

reverse= revs(lastDigit, number, reverse);

// Print the result 
System.out.println("That number reversed is " + reverse);


// print the method calculation 
reverse= revs(lastDigit, number, reverse);

}


// a method to do the calculation 

public static int revs(int lastDigit, int number, int reverse)
{
  do  {

lastDigit = number % 10;

reverse = (reverse * 10) + lastDigit;

number = number / 10; } while (number > 0);

return reverse;
}


}