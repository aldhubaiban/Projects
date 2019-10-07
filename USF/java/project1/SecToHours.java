/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/

import java.util.Scanner;

public class SecToHours
{
public static void main(String[] args)
{

/*Time Constants*/ 
final int MINUTES_IN_HOUR= 60;
final int SECONDS_IN_MINUTE= 60;


// Time variables 
long SECONDS,MINUTES,HOURS;

// input 
Scanner input = new Scanner(System.in) ;


// make the user enter number of seconds  
System.out.println("enter the number of Seconds:");
SECONDS = input.nextLong ();



// Calculate the number of hours and minutes
MINUTES = SECONDS / SECONDS_IN_MINUTE ;
HOURS = MINUTES / MINUTES_IN_HOUR ;


// show results 
System.out.println (" Hours:"+ HOURS + "\n"  +
 " Minutes:"+ (MINUTES % MINUTES_IN_HOUR)  +"\n" +

" Seconds:" + (SECONDS % SECONDS_IN_MINUTE) );


/* the goal of this program is to 

convert any number of seconds 

to hours,minutes, and seconds*/

//----------------------------------9

/* How the calculation works??

when the user enter the number of seconds

the program try to convert it to hour if not minutes. 

when the number is not sufficent for hours and minutes, 

the program will output exactly the same seconds 
*/
}
}