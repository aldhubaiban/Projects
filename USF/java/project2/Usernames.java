/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/


import java.util.Scanner ;

import java.util.Random;

public class Usernames

{

public static void main(String[] args)
{

Scanner input = new Scanner(System.in) ;

Random generator = new Random();

// declare assigned variables  

String 

First_Name, Last_Name, Username;



// declare random generator  
int Random_Number;

Random_Number = generator.nextInt(99)+ 10; 

//prompt the user to enter names 
System.out.print("Enter your first name: ") ;
First_Name= input.nextLine ();

System.out.print ("Enter your last name: ") ;
Last_Name = input.nextLine ();

// show results 

System.out.print("Username: " +First_Name.charAt(0) + Last_Name.substring(0,3) + Random_Number);



}

}

/*
The goal of this program is to create a username 

that begins with  first letter of the first name 

and  first three letters of the last name 


*/