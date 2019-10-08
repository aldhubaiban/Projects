		#ifndef EMPLOYEE_H
		#define EMPLOYEE_H

		#define MAX_NAME_LEN 15
		#define MAX_NUM_EMPLOYEES 10
		#define TAX_RATE  0.15f
// declare the struct 
		struct employee
		{
		char name[MAX_NAME_LEN+1];
		int id;
		double hours_worked;
		double hourly_rate; 
		double taxes_withheld;
		double net_income;
		};

int buildEmployeeList(struct employee list[],char* filename);
int writeSalaryInfoToFile(struct employee list[],int numEmployees,char* filename);

#endif //EMPLOYEE_H


