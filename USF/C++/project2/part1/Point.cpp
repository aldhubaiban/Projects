#include "Point.h"


Point::Point(double ax,double ay)
{

	setX(ax);
	setY(ay);
}

double Point::getX()
{

	return x;
}

double Point::getY()
{

	return y;
}

void Point::setX( double ax)
{
	x=ax;
}
void Point::setY(double ay)
{

	y=ay;
}