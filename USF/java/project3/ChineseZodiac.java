/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/
import java.util.*;
public class ChineseZodiac
{
public static void main(String[] args)
{


// input 
Scanner input = new Scanner(System.in) ;

//Declare variables 
int year, ChineseZodiac; 

// prompt the user enter the year 
System.out.print ("Enter a year: ");
year=input.nextInt() ;

// math equation 
ChineseZodiac= year %12 ;


// switch statement 
switch (ChineseZodiac)
{

case 0:
System.out.print("The year " + year+ " is the year of the Monkey"  );
break ;

case 1:
System.out.print("The year " + year+ " is the year of the Rooster"  );
break ;

case 2:
System.out.print("The year " + year+ " is the year of the Dog"  );
break ;

case 3:
System.out.print("The year " + year+ " is the year of the Pig"  );
break ;

case 4:
System.out.print("The year " + year+ " is the year of the Rat"  );
break ;

case 5:
System.out.print("The year " + year+ " is the year of the Ox"  );
break ;

case 6:
System.out.print("The year " + year+ " is the year of the Tiger"  );
break ;

case 7:
System.out.print("The year " + year+ " is the year of the Rabbit"  );
break ;

case 8:
System.out.print("The year " + year+ " is the year of the Dragon"  );
break ;

case 9:
System.out.print("The year " + year+ " is the year of the Snake"  );
break ;

case 10:
System.out.print("The year " + year+ " is the year of the Horse"  );
break ;

case 11:
System.out.print("The year " + year+ " is the year of the Sheep"  );
break ;

}





}
}