#include <iostream>
using std::cout;
#include "SalariedEmployee.h"



SalariedEmployee::SalariedEmployee( const string &first,
  const string &last, const string &ssn, int month, int day, int year, double salary ): Employee( first, last, ssn, month, day, year )
  {
    setWeeklySalary( salary );
  }

  void SalariedEmployee::setWeeklySalary( double salary )
  {
    weeklySalary = ( salary < 0.0 ) ? 0.0 : salary;

  }

  double SalariedEmployee::getWeeklySalary() const
  {
    return weeklySalary;
  }

  double SalariedEmployee::earnings() const
  {
    return getWeeklySalary();
  }

  void SalariedEmployee::print() const
  {
    cout << "salaried employee: ";
    Employee::print();
    cout << "\nweekly salary: " << getWeeklySalary();
  }
