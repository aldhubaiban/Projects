#include <iostream>
#include "Complex.h" 
using namespace std;

// Constructor
Complex::Complex( double realPart, double imaginaryPart )
: real( realPart ),
imaginary( imaginaryPart )
{
   real = realPart; 
imaginary = imaginaryPart; 
} 

// addition operator
Complex Complex::operator+( const Complex &operand2 ) const
{
return Complex( real + operand2.real,
imaginary + operand2.imaginary );
} // end function operator+

// subtraction operator
Complex Complex::operator-( const Complex &operand2 ) const
{
return Complex( real - operand2.real,
imaginary - operand2.imaginary );
} // end function operator-

// display a Complex object in the form: (a, b)
void Complex::print() const
{
cout << '(' << real << ", " << imaginary << ')';
} // end function print

ostream& operator<<( ostream &out,const Complex &r )// output
{
   cout<<r.real<<"+"<<r.imaginary<<"i"<<endl;
   return out;

}
bool Complex::operator==( const Complex &r2 ) //overload equal operator
{
  
   if((real != r2.real) || (imaginary!=r2.imaginary))
  
       return false;
  

   return true;
  
}
Complex& Complex::operator-- ()
{
	
--real;
   --imaginary;
   return *this;
}
