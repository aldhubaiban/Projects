
//" i pledge my Honor that I have not cheated, and will not cheat, on this test" 


import java.util.*; 
import java.text.*;

public class Lab_exam

{
public static void main(String[] args)
{

Scanner input= new Scanner(System.in) ;
DecimalFormat fmt = new DecimalFormat("0.######"); 


// declare variables 
double Distance , Time=0 ;
String speed ;
// declare constants 
final int Air = 1100, Water= 4900, Steel= 16400 ;

// input 
System.out.print("enter the distance the sound will travel:") ;
Distance =input.nextDouble() ;

System.out.print("enter the medium that the sound will travel through:") ;
speed =input.next() ;

// if statement 

if (speed .equalsIgnoreCase("water"))
{
Time = Distance/Water;
System.out.print("The time take for sound to travel thorough Water: " + fmt.format(Time)+ " Seconds");
}
if (speed .equalsIgnoreCase("steel"))

{
Time = Distance/Steel;
System.out.print("The time take for sound to travel thorough Steel : " + fmt.format(Time)+ " Seconds");
}
} 
}



