#include <iostream>


using namespace std;
template <typename T>

T minimum(T var1,T var2)
{
	T minimumValue(var1);
	if (var2<minimumValue)
	{
		minimumValue=var2;
	}
	return minimumValue;
}

int main(void) 
{
// demonstrate minimum with int values
int int1(0); // first int value
int int2(0); // second int value
cout << "Input two integer values: ";cin >> int1 >> int2;
// invoke int version of minimum
cout << "The smaller integer value is: " << minimum(int1, int2);
// demonstrate minimum with char values
char char1(' '); 
// first char value
char char2(' '); // second char value
cout << "\n\nInput two characters: ";cin >> char1 >> char2;
// invoke char version of minimum
cout << "The smaller character value is: " << minimum(char1, char2);
// demonstrate minimum with double values
double double1(0); // first double value
double double2(0); // second double value
cout << "\n\nInput two double values: ";cin >> double1 >> double2;
// invoke double version of minimum
cout<< "The smaller double value is: " << minimum(double1, double2) << endl;

return 0;
} 

