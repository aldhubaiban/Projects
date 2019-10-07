/*I pledge my Honor that I have not cheated, and will not cheat, on this test.*/ 

import java.util.Scanner;

public class Octagonal
{

 public static void main(String[] args)
 {
// declare varaiables
  int starting, ending;

  //Scanner
  Scanner scan = new Scanner(System.in);

  //prompt user to enter starting value
System.out.print("Enter a starting value (greater than 0): ");
starting = scan.nextInt();

//starting value input validation
  while(starting <= 0)
{
System.out.println("Your previous entry is invalid.");
System.out.print("Enter another starting value: ");
starting = scan.nextInt();
}

  //prompt user to enter ending value
System.out.print("Enter an ending value (greater than your starting value): ");
ending = scan.nextInt();

//ending value input validation
 while(ending <= starting)
{
System.out.println("Your previous entry is invalid.");
System.out.print("Enter another ending value: ");
ending = scan.nextInt();
}

 //result
 System.out.println("\nNumber \t\t OctagonalNumber Number");
 System.out.println("-------------------------------");

 //loop to print result 
 while (starting <= ending)
 {
 System.out.println(starting + "\t\t\t\t" + OctagonalNumber(starting,ending));
 starting++ ;
 }


 }

 // method  OctagonalNumber number calcualtion
 public static int OctagonalNumber (int starting, int ending)
 {
  return ( (3*(starting*starting))-(2*starting));
 }

}
