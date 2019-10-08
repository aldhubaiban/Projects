/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/

import java.util.*;

public class carTest 
{

public static void main(String []args)
{

//scanner
Scanner input= new Scanner(System.in);

// Decalre variables
String model1, model3, make3 ; 
int year2, year3 ;


// import info from another class 
car car1= new car("Ford", "Taurus", 2015);
car car2= new car("Honda", "Accord", 2007);
car car3= new car();


// text and proompt the user to enter new information
System.out.println("Here is the information I have on Mr. Smith's three cars:");
System.out.println(car1 + "\n"+car2 + "\n"+ car3 + "\n");



System.out.println("Whoops! It seems we do not have the info on one of his cars! \n Enter the information the third car here: ");

System.out.print("Make: ");
make3=input.next();

System.out.print("Model: ");
model3=input.next();

System.out.print("Year: ");
year3=input.nextInt();


System.out.print("Mr. Smith traded the Taurus for another Ford from the same year.\nEnter the new Ford model: ");
model1=input.next();
System.out.print("Mr. Smith sold the 2007 Accord to buy a more current version.\nEnter the new year for the Accord: ");
year2=input.nextInt();


System.out.println("Here is the updated information I now have on Mr. Smith's three cars: ");

// cars  updated information 
	   car3.setYear(year3);
   
		car3.setMake(make3);
      
		car3.setModel(model3);
      
      car2.setYear(year2);   
      
      car1.setModel(model1);
      
      //print result 
      
     System.out.println( car1.getYear() + "\t" + car1.getMake() + "\t" + car1.getModel());
     
     System.out.println( car2.getYear() + "\t" + car2.getMake() + "\t" + car2.getModel());
     
     System.out.println( car3.getYear() + "\t" + car3.getMake() + "\t" + car3.getModel());
      
      
          

}


}