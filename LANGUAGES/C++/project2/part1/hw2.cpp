// Test program for ex9.12
#include <iostream>
#include <stdexcept>
#include "Rectangle.h" // include definition of class Rectangle
#include "Point.h"
using namespace std;

int main() {
   Point w(1.0, 1.0);
   Point x(5.0, 1.0);
   Point y(5.0, 3.0);
   Point z(1.0, 3.0);

   Point j(0.0, 0.0);
   Point k(1.0, 0.0);
   Point m(1.0, 1.0);
   Point n(0.0, 1.0);

   Rectangle r1(z, y, x, w);
   cout << "Rectangle 1:\n";
   cout << "length = " << r1.length();
   cout << "\nwidth = " << r1.width();
   r1.perimeter();
   r1.area();
   cout << "\nThe rectangle " 
      << (r1.square() ? "is" : "is not")
      << " a square.\n";

   Rectangle r2(j, k, m, n);
   cout << "\nRectangle 2:\n";
   cout << "length = " << r2.length();
   cout << "\nwidth = " << r2.width();
   r2.perimeter();
   r2.area();
   cout << "\nThe rectangle " 
      << (r2.square() ? "is" : "is not")
      << " a square.\n";

   try {
      Rectangle r3(w, x, m, n);
   }
   catch (invalid_argument&) {
      cout << "\nNot a valid Rectangle" << endl;
   }

   try {
      Point v(99.0, -2.3);
   }
   catch (invalid_argument&) {
      cout << "Not a valid Point" << endl;
   }
};

