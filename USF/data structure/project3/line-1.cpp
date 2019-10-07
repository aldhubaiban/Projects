// Programmer: Abdulrahman Aldhubaiban
// Last modification date: Mar 19, 2018

#include <iostream>
#include "line.h"

double Line::intersect(const Line L) const 
{
 
 	
		if ( (this->a==L.a) && (this->b==L.b))
		{
			throw EqualLines();
		}
		else if (this->a==L.a)
		{
			throw ParallelLines();
		}

	
	  return (L.b-this->b)/(this->a-L.a);
  
}






