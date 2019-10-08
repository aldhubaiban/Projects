/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/
import java.util.*;

public class TravelingSong
{
public static void main(String[] args)
{
// input 
Scanner input = new Scanner(System.in) ;

// declare variables 
int Num_of_verses, value=1, max=100 ;

// declare constants 
final int Limit= 100 ;

//prompt the user to enter how many verses
System.out.print("how many verses (1 to "  + Limit + ")? ");
Num_of_verses= input.nextInt() ;

//loop to verify the number is between 0 and 100
while(Num_of_verses <= 0 || Num_of_verses > Limit)
{
System.out.print("How many verses (1 to 100)? ");
Num_of_verses = input.nextInt();

}

//new line 
System.out.print("\n");


// second loop 
while(value<=Num_of_verses)
{
value++;
System.out.print( max +" bottles of beer on the wall.\n") ;
System.out.print( max +" bottles of beer.\n") ;
System.out.print( "If one of those bottles should happen to fall\n") ;
max-- ;
System.out.print( max +" bottles of beer on the wall.\n\n"); 
} 

}
}