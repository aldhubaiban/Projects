/*I pledge my Honor that i have not cheated, and will not cheat, on this test*/

import java.util.*;

import java.text.*;

public class Cone
{

// private members 
private double r, h ;


// constructor 
public Cone()
{

r=0.0;

h=0.0;

}

// mutators
public void setR(double r)
{

this.r=r;

}

public void setH(double h)
{

this.h=h;

}


// Accessors 
public double getR()
{

return r;
}

public double getH()
{

return h;
}

public double getArea()
{

return (Math.PI*r)*(r+Math.sqrt(  (h*h+r*r)            ));
}

public double getVolume()
{

return ((Math.PI*r*r)* (h/3)            );
}


}