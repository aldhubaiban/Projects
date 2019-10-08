
/*I pledge my Honor that I have not cheated, and will not cheat, on this test.*/ 

import java.util.*;
import java.text.*;

public class StarMethod3 


{
public static void main(String [] args)
{
//  scanner 
Scanner input=new Scanner(System.in);
//declare variables
int rows;
//prompt the user to enter the number of rows 
System.out.print("Enter the number of rows: ");
rows=input.nextInt();

// result 
starpattern3(rows);
}

// method for starpattern3
public static void starpattern3(int rows) 
{
for (int row = rows; row <= rows; row--)
{
for (int star = 1; star <= row; star ++)
{




if (star > 0)
System.out.print("*");
if (star <= 0)
break;
}
System.out.println();
if (row <= 0)
break; }


}



}