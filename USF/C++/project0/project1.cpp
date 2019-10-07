#include <stdio.h>
#include <iostream>

int main (void){

int num1,num2,num3;

std::cout << "Input three different integers: ";
std::cin >> num1;
std::cin >> num2;
std::cin >> num3;

std::cout << "sum is ";

std::cout << (num1+num2+num3);
std::cout <<"\n";
std::cout << "Average is ";

std::cout << (num1+num2+num3)/3 ;
std::cout <<"\n";
std::cout << "product is ";

std::cout << (num1*num2*num3) ;
std::cout <<"\n";



if (num1<=num2 && num1<= num3)
{
	std::cout << "Smallest is ";
	std:: cout << num1;
	std::cout <<"\n";
}
else 

if (num2<=num3 && num2<= num1 )
{

	std::cout << "Smallest is ";
	std:: cout << num2;
	std::cout <<"\n";
}
else 
if (num3<=num1 && num3<= num2)
{

	std::cout << "Smallest is ";
	std:: cout << num3;
	std::cout <<"\n";
}

if (num1>=num2 && num1>= num3)
{
	std::cout << "Largest is ";
	std:: cout << num1;
	std::cout <<"\n";
}
else 

if (num2>=num3 && num2>= num1 )
{

	std::cout << "Largest is ";
	std:: cout << num2;
	std::cout <<"\n";
}
else 
if (num3>=num1 && num3>= num2)
{

	std::cout << "Largest is ";
	std:: cout << num3;
	std::cout <<"\n";
}
return 0;
}