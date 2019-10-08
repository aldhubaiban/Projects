employee:	employeePayroll.o	employee.o	linkedList.o
	c99	-o	employee	employee.o	employeePayroll.o	linkedList.o
employeePayroll.o:	employeePayroll.c	employee.h	linkedList.h
	c99	-c	-Wall	-g	employeePayroll.c
employee.o:	employee.c	employee.h
	c99	-c	-Wall	-g	employee.c
clean:
	rm	employeePayroll.o	employee.o	employee
