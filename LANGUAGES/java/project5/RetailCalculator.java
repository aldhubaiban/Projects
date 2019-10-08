/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/

import java.util.*;

import java.text.*;

public class RetailCalculator
{

public static void main(String[] args)
{

// scanner 
Scanner input= new Scanner (System.in);

// declare variables
double cost , markup, retail;


// percntage and currency objects 
NumberFormat fmt = NumberFormat.getCurrencyInstance();
NumberFormat fmt2 = NumberFormat.getPercentInstance();


// prompt the user to enter cost
System.out.print ("Enter the item's wholesale cost: ");
cost= input.nextDouble();

// prompt the user to enter markup percntage 
System.out.print("Enter the item's markup percentage ");
markup= input.nextDouble();

// to allow the user enter the percntage as decimal 
if (markup<1 && markup>0)
{
markup=markup*100;
}


// if entered as whole number 
markup = markup/100;


// print the result 
retail = calculator(markup, cost); 
System.out.print("The item's retail price (at a " + fmt2.format(markup)+ ") is " + fmt.format(retail));
 

  
}




// method for calculation 
public static double  calculator (double markup,double cost)

{
    return cost*markup+cost;  
   
}







}