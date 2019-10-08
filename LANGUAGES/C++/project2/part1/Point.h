#ifndef Point_H

#define Point_H


class Point
{
private:
	double x,y;

public:
	Point(double=0.0,double=0.0);

	double getX();
	double getY();
	void setX( double);
	void setY( double);

};









#endif