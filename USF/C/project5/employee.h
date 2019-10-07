// ABDULRAHMAN Aldhubaiban
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_NAME_LEN 15
#define MAX_NUM_EMPLOYEES 10

struct employee
		{
		char name[MAX_NAME_LEN+1];
		int id;
		double hours_worked;
		double hourly_rate; 
		double taxes_withheld;
		double net_income;
		struct employee *next; 
		};

struct employee* buildEmployeeList(char * filename);
void writeSalaryInfoToFile(struct employee * listHead, char * filename);


#endif //EMPLOYEE_H
