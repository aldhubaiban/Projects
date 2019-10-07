#ifndef Rectangle_H
#define Rectangle_H

#include <iostream> 

using namespace std;



class Rectangle
{
public: 
	


	Rectangle(float a=1, float b=1) {
		c=a;
		d=b;
	}


	


void setLength(float l)
{
d=l;
}

void setWidth(float w)
{
c=w;
}



float getLength()
{
return d;
}


float getWidth()
{
return c;
}



float perimeter()
{
return (2*c)+(2*d);
}

float area()
{
return c*d;
}


private: 
	float c;
	float d; 


};  




#endif 