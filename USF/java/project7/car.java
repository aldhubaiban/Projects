/*“I pledge my Honor that I have not cheated, and will not cheat, on this assignment.”*/



public class car 

{

// declare private variables 
private String make, model ;
private int year ;


// first Constructor


public car ()
{

make= "-";

model= "-";

year= 0;

}


// second Constructor
public car (String brand , String type , int Year)
{

make = brand ;

model= type ;

year= Year ;


}



// Accessors and Mutators for all variables 

public String getMake()
{
return make;
}

public void setMake(String brand)
{
make= brand ;
}




public String getModel()
{
return model;
}

public void setModel(String type)
{
model= type ;
}



public int  getYear()
{
return year;
}

public void setYear(int age)
{
year= age ;
}



// to string method 
public String toString ()
{

return (year +"\t"+ make + "\t" + model) ;
}


}


