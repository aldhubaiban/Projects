/*I pledge my Honor that i have not cheated, and will not cheat, on this test*/

import java.util.*;

import java.text.*;

public class ConeDriver


{
public static void main(String [] args)

{

// declare variables 
double r,h;


// object 
Cone obj1= new Cone();

// Scanner 
Scanner input= new Scanner(System.in);

// DecimalFormat
DecimalFormat fmt= new DecimalFormat("0.##");

// prompt thes user to enter radius and  height 
System.out.print("Enter the radius of a cone: ");

r=input.nextDouble();

System.out.println();

System.out.print("Enter the height of a cone: ");

h=input.nextDouble();


// settters 
obj1.setR(r);
obj1.setH(h);


// printout the result 
System.out.println("Given a cone with a radius of  "+ obj1.getR()+ " units, and height of "+obj1.getH()+ " units:");

System.out.println("The area is: "+fmt.format(obj1.getArea())+" units squared.");

System.out.println("The volume is: "+fmt.format(obj1.getVolume())+" units cubed.");


}

}