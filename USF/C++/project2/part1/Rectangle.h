#ifndef Rectangle_H

#define Rectangle_H

#include "Point.h"

class Rectangle
{

private:
Point topLeft;
Point topRight;
Point bottomLeft;
Point bottomRight;

public:

	Rectangle(Point,Point,Point,Point);

	 Point getTopLeft();
     Point getTopRight();
     Point getBottomLeft();
     Point getBottomRight();

     double length();
     double width();
     double perimeter();
     double area();
     bool square();
	
};

#endif