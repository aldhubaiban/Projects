/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/

import java.util.*;

public class Fusion
{
public static void main(String[] args)
{
// input
Scanner input = new Scanner(System.in) ;


// Declare gems
String  gem_1, gem_2 ;

// prompt the user to enter gems 
System.out.println("Who is the first gem? ");
gem_1= input.next();
System.out.println("Who is the second gem? ");
gem_2= input.next();

// First equation  


if (gem_1.equalsIgnoreCase("Garnet") &&gem_2.equalsIgnoreCase("Pearl")
|| gem_1.equalsIgnoreCase("Pearl") &&gem_2.equalsIgnoreCase("Garnet"))
{System.out.print("When "+ gem_1+ " and "+ gem_2+" fuse, they create Sardonyx");}


//second equation


 else if (gem_1.equalsIgnoreCase("Garnet") &&gem_2.equalsIgnoreCase("Amethyst") 
 ||gem_1.equalsIgnoreCase("Amethyst") &&gem_2.equalsIgnoreCase("Garnet"))
{System.out.print("When "+ gem_1+ " and "+ gem_2+" fuse, they create Sugilite");}


// third equation


 else if (gem_1.equalsIgnoreCase("Pearl") &&gem_2.equalsIgnoreCase("Amethyst") 
 ||gem_1.equalsIgnoreCase("Amethyst") &&gem_2.equalsIgnoreCase("Pearl"))
 
{System.out.print("When "+ gem_1+ " and "+ gem_2+" fuse, they create Opal");}

// fourth equation 


 else if (gem_1.equalsIgnoreCase("Steven") &&gem_2.equalsIgnoreCase("Amethyst")
 || gem_1.equalsIgnoreCase("Amethyst") &&gem_2.equalsIgnoreCase("Steven"))
{System.out.print("When "+ gem_1+ " and "+ gem_2+" fuse, they create Smoky Quartz");}

//fifth equation 


else if (gem_1.equalsIgnoreCase("Connie") &&gem_2.equalsIgnoreCase("Steven")
|| gem_1.equalsIgnoreCase("Steven") &&gem_2.equalsIgnoreCase("Connie"))
{System.out.print("When "+ gem_1+ " and "+ gem_2+" fuse, they create Stevonnie");}


// if the fusion is unknown 
else System.out.print("No known fusion.");

}
}
