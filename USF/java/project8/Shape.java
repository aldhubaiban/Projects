/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/


public class Shape 
{

// private variables  
private String shape ;

private int side; 
 

// static variable
static int shape_num ; 

// constructor
public Shape ()
{
shape= "-";

side= 0;
shape_num++;
}

// setter 
public void setShape(String Shape)
{
this.shape=Shape;
}

// setter
public void setSide(int Side)
{
this.side=Side;
}

//method to return static void variable 

public static int Num()
{

return shape_num;
}



public String toString()
{
   return ("Shape: "+ shape + "\n" + "No. of sides: " + side);
}




}