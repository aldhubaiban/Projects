/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/

import java.util.*;

public class ShapeTest 
{
public static void main(String[] args)
{
//Scanner
Scanner input = new Scanner(System.in);

// variables
String shape1,shape2,shape3;

int sides1,sides2,sides3;

//objects
Shape obj1 = new Shape();
Shape obj2 = new Shape();
Shape obj3 = new Shape();


//text 
System.out.println("Enter info on the "+Shape.Num()+" shapes: ");

//shape 1
System.out.print("Enter the name of the shape: ");
shape1 = input.next();
System.out.print("Enter the number of sides: ");
sides1 = input.nextInt();
 

//shape 2
System.out.print("Enther the name of the shape: ");
shape2 = input.next();
System.out.print("Enter the number of sides: ");
sides2 = input.nextInt();

//shape 3
System.out.print("Enther the name of the shape: ");
shape3 = input.next();
System.out.print("Enter the number of sides: ");
sides3 = input.nextInt();



// setter 
obj1.setShape(shape1);
obj1.setSide(sides1);


obj2.setShape(shape2);
obj2.setSide(sides2);

obj3.setShape(shape3);
obj3.setSide(sides3);

//Return User input 
System.out.println("Here is the info you have entered for the "+Shape.Num()+" shapes: ");
System.out.println(obj1 +"\n");
System.out.println(obj2 +"\n");
System.out.println(obj3+"\n");
}





}