#include "Rectangle.h"
#include <math.h>
#include <iostream>



Rectangle::Rectangle(Point tl,Point tr, Point bl, Point br)
{
	  if(          tl.getX() < 20.0  &&   tl.getX() >=0.0
	             &&tl.getY() < 20.0  &&   tl.getY() >= 0.0
				 &&tr.getX() < 20.0  &&   tr.getX() >=0.0
				 &&tr.getY() < 20.0  &&   tr.getY() >=0.0
				 &&bl.getX() < 20.0  &&   bl.getX() >=0.0
				 &&bl.getY() < 20.0  &&   bl.getY() >=0.0
				 &&br.getX() < 20.0  &&   br.getX() >=0.0
				 &&br.getY() < 20.0  &&   br.getY() >=0.0
		)
	  {

	  	topLeft= tl;
	  	topRight= tr;
	  	bottomLeft= bl;
	  	bottomRight= br;
	  }

	  

 		  

}

	  Point Rectangle::getTopLeft(){
		  return topLeft;
	  }
      
	  Point Rectangle::getTopRight(){
		  return topRight;
	  }
      Point Rectangle::getBottomLeft(){
		  return bottomLeft;
	  }
      Point Rectangle::getBottomRight(){
		  return bottomRight;
	  }

	   double Rectangle::width(){
		  Point tr = this->getTopRight();
		  Point tl = this->getTopLeft();
		  return std::abs(tr.getX() - tl.getX());
	  }

	   double Rectangle::length(){
		    Point p1 = this->getTopRight();
			Point p2 = this->getBottomRight();
 
		  return std::abs(p1.getY() - p2.getY());
 
	  }

 double Rectangle::perimeter(){
		  double per = this->length()*2 + this->width()*2;
		  return per;
	  }

	  double Rectangle::area(){
		  double area = this->length()*2 * this->width()*2;
		  return area;
	  }

	  	  bool Rectangle::square(){
		  if(this->length() == this->width()) return true;
		  else return false;
	  }








