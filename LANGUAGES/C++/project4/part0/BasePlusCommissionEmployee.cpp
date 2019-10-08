#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "BasePlusCommissionEmployee.h"
using namespace std;


BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, const string &ssn, 
			double sales, double rate, double salary) : commissionEmployee(first, last, ssn, sales, rate)
				{
					setBaseSalary(salary);
				}


void BasePlusCommissionEmployee::setFirstName(const string &first)
{
	commissionEmployee.setFirstName(first);
}

void BasePlusCommissionEmployee::setLastName(const string &last)
{
	commissionEmployee.setLastName(last);
}

void BasePlusCommissionEmployee::setSocialSecurityNumber(const string &ssn)
{
	commissionEmployee.setSocialSecurityNumber(ssn);
}

void BasePlusCommissionEmployee::setGrossSales(double sales)
{
	commissionEmployee.setGrossSales(sales);
}

void BasePlusCommissionEmployee::setCommissionRate(double rate)
{
	commissionEmployee.setCommissionRate(rate);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	if( salary < 0.0){
		throw invalid_argument("Salary must be >= 0.0 ");
	}

	baseSalary = salary; 
}



string BasePlusCommissionEmployee::getFirstName() const 
{
	return commissionEmployee.getFirstName();
}

string BasePlusCommissionEmployee::getLastName() const
{
	return commissionEmployee.getLastName();
}

string BasePlusCommissionEmployee::getSocialSecurityNumber() const
{
	return commissionEmployee.getSocialSecurityNumber();
}

double BasePlusCommissionEmployee::getGrossSales() const
{
	return commissionEmployee.getGrossSales();
}

double BasePlusCommissionEmployee::getCommissionRate() const
{
	return commissionEmployee.getCommissionRate();
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
	return baseSalary; 
}


double BasePlusCommissionEmployee::earnings() const
{
	return getBaseSalary() + commissionEmployee.earnings();
}


string BasePlusCommissionEmployee::toString() const
{
	ostringstream output;
	output << fixed << setprecision(2) << "Base-salaried " << commissionEmployee.toString()
			 << "\nBase salary: " << getBaseSalary();

	return output.str();

}












					