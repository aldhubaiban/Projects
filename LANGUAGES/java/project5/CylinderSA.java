/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/

import java.util.*;
import java.text.*;
public class CylinderSA
{
 public static void main(String [] args)
 {
  
  //Declare variables 
  double Area, height, radius;
  
  //Scanner
  Scanner scan = new Scanner(System.in);
  
  //Prompt user to enter the radius and height
  System.out.println("Enter cylinder's radius:");
  radius = scan.nextDouble();
  
  System.out.println("Enter the cylinder's height:");
  height = scan.nextDouble();
  
  //Calculate surface area using the method 
 Area= calculate(height,radius);
  
 //Display the result
 System.out.println("The surface area of a cylinder is: " + Area);
 }
 
 public static double calculate(double height, double radius)
 {
 return (2*(Math.PI)*radius*height)+(2*(Math.PI)*(Math.pow(radius,2))); }
  
}