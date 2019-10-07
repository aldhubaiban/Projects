
#ifndef BASEPLUS_H
#define BASEPLUS_H
#include <string>
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee{
public:

	BasePlusCommissionEmployee(const std::string&, const std::string&, const std::string&, double = 0.0, double = 0.0, double = 0.0);


	void setGrossSales(double); 
	void setCommissionRate(double);
	void setBaseSalary(double);
	void setFirstName(const std::string&);
	void setLastName(const std::string&);
	void setSocialSecurityNumber(const std::string&);


	
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getSocialSecurityNumber() const;
	double getGrossSales() const;
	double getCommissionRate() const;
	double getBaseSalary() const;


	double earnings() const; 
	std::string toString() const;

private:
	double baseSalary;

	
	CommissionEmployee commissionEmployee;

};

#endif
