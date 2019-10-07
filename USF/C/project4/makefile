employee:	employeePayroll.o	employee.o
	c99	-o	employee	employee.o	employeePayroll.o
employeePayroll.o:	employeePayroll.c	employee.h
	c99	-c	-Wall	-g	employeePayroll.c
employee.o:	employee.c	employee.h
	c99	-c	-Wall	-g	employee.c
clean:
	rm	employeePayroll.o	employee.o	employee
