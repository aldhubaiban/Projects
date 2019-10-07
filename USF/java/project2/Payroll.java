/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/


import java.util.Scanner;
import java.text.NumberFormat;
public class Payroll
{
public static void main(String[] args)
{

// input 
Scanner input = new Scanner(System.in) ;
NumberFormat fmt = NumberFormat.getCurrencyInstance();
NumberFormat fmt2 = NumberFormat.getPercentInstance();

// Declare variables 
String  
employee ;

double 
federal_tax, state_tax , hours_worked, hourly_rate, Gross_pay, Total_Deduction, Net_Pay ;

//prompt the user to enter an employee information 
System.out.print ("Enter employee's name: ") ;
employee= input.nextLine ();

System.out.print("Enter number of hours worked in a week: ");
hours_worked= input.nextDouble ();

System.out.print("Enter hourly pay rate: ") ;
hourly_rate= input.nextDouble () ;

System.out.print( "Enter federal tax withholding rate (as decimal): ") ;
federal_tax= input.nextDouble () ;

System.out.print( "Enter state tax withholding rate (as decimal): ") ;
state_tax= input.nextDouble () ;
System.out.print( "\n") ;

// Mathmatic equation 
Gross_pay = hours_worked * hourly_rate ;

Total_Deduction= Gross_pay*state_tax +Gross_pay *federal_tax ;

Net_Pay=Gross_pay - Total_Deduction ;


//results 
System.out.print("Employee Name:" + employee + "\n" ) ;
System.out.print("Hours Worked:" + hours_worked + "\n") ;
System.out.print("Hourly Pay Rate:" + fmt.format(hourly_rate) +"\n \n"  ) ;



System.out.print("Gross Pay:" + fmt.format(Gross_pay) +"\nDeductions:" );


System.out.print ("\n\t Federal Tax@"+fmt2.format(federal_tax)) ; 
System.out.print (":" +  fmt.format(Gross_pay *federal_tax) );


System.out.print ("\n\t State Tax@"+fmt2.format(state_tax)+":" 
+fmt.format(Gross_pay*state_tax) ) ;



System.out.print ("\n\t Total deduction:"+fmt.format(Total_Deduction) );
System.out.print ( "\n\t Net Pay:" + fmt.format(Net_Pay) ) ;





}
}

/* The goal of this program helps the workers to know 
how much is the GrossPay 

and how much money has been deducted from Taxes*/