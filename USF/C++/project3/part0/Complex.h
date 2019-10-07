
#include<iostream>
using namespace std;
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
explicit Complex( double = 0.0, double = 0.0 ); 
Complex operator+( const Complex & ) const; 
Complex operator-( const Complex & ) const; 
friend ostream& operator<<( ostream &out,const Complex & ) ; 
bool operator==( const Complex &) ;
Complex& operator--() ;
void print() const; 
private:
double real; 
double imaginary; 
}; 

#endif