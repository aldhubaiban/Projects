#include <iostream> 
#include <vector> 

using namespace std;


int main() {

	const size_t SIZE(20); // size of array
vector<int> v;
	size_t subscript(0);
	bool duplicate(false);

	cout << "Enter 20 integers between 10 and 100:\n";

	// get 20 nonduplicate integers in the range between 10 and 100

	unsigned int i(0);

	

	while (i <= SIZE ) 
	{
		duplicate = false;
		int value(0); // number entered by user
		cin >> value;
		


		while(value<10 || value>100)
		{
			cout<< "please enter a number between 10 and 100 \n";
			cin >> value;
		}


for (int j=0;j<v.size(); ++j)
{

if (value==v[j])
{

	duplicate=true;
	break;
}


}
if(!duplicate)
{
v.push_back(value);
++subscript;

}

i++;
		}


		cout << "\n The nonduplicate values are:\n";
		// display array of nonduplicates
		for (size_t index(0); index < subscript; ++index) {
			cout << v[index] << ' ';
			}

			cout << endl;
			
		}

