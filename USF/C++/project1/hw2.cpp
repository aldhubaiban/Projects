#include <iostream> 
#include <array> 

using namespace std;


int main() {

	const size_t SIZE(20); // size of array
	array<int, SIZE> a;
	size_t subscript(0);
	bool duplicate(false);

	cout << "Enter 20 integers between 10 and 100:\n";

	// get 20 nonduplicate integers in the range between 10 and 100

	unsigned int i(0);

	

	while (i < a.size()) 
	{
		duplicate = false;
		int value(0); // number entered by user
		cin >> value;
		


		while(value<10 || value>100)
		{
			cout<< "please enter a number between 10 and 100 \n";
			cin >> value;
		}


for (size_t j=0;j<subscript; ++j)
{

if (value==a[j])
{

	duplicate=true;
	break;
}


}
if(!duplicate)
{
a[subscript++]=value;

}

i++;
		}


		cout << "\n The nonduplicate values are:\n";
		// display array of nonduplicates
		for (size_t index(0); index < subscript; ++index) {
			cout << a[index] << ' ';
			}

			cout << endl;
			
		}
