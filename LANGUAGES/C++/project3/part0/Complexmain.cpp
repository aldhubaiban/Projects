#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
Complex x;
Complex y( 4.3, 8.2 );
Complex z( 3.3, 1.1 );
Complex a( 4.3, 8.2 );
Complex b(4.3, 8.2 );

cout << "x: ";
x.print();
cout << "\ny: ";
y.print();
cout << "\nz: ";
z.print();

x = y + z;
cout << "\n\nx = y + z: " ;
x.print();

cout<<"\n\ncheck for overloading << operator"<<endl;
x.print();
cout << " = ";
y.print();
cout << " + ";
z.print();

x = y - z;
cout << "\n\nx = y - z:" << endl;
x.print();
cout << " = ";
y.print();
cout << " - ";
z.print();

cout<<"\n\ncheck for overloading -- operator"<<endl;
--z;
cout<<z;

cout<<"check for overloading == operator"<<endl;
if( a == b)
   cout<<"Complex numbers \n"<<a<<"and\n"<<b<<"are equal "<<endl;
else
   cout<<"Complex numbers \n"<<a<<"and\n"<<b<<"are not equal "<<endl;
cout << endl;
} 
