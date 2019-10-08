#include <stdio.h>
#include "employee.h"
#define TAX_RATE  0.15f
#define MAX_NUM_EMPLOYEES 10

//Open input file 'filename' and read the following information:
// char* name
// int id
// double hours worked
// double hourly rate
//Create employee structs from this information and store them in the array 'list'
//return the number of employee structs added to list

				int buildEmployeeList(struct employee list[], char* filename)
				{

										// pointer  to a file 
										FILE *pFILE;
										// open a file and write on it 
										pFILE=fopen(filename, "r");

										// check if the file can be opened 
										if (pFILE==NULL)
										{
											printf("Error openning the file \n");
										}
			
			
					int counter=0; 

            		while(!feof(pFILE))
            		{

            		fscanf(pFILE, "%s%d%lf%lf", list[counter].name,&list[counter].id,&list[counter].hours_worked , &list[counter].hourly_rate);	

					counter++;
					}
					// to erase an extra line after getting out the loop 
					counter --;

		fclose(pFILE); 
		
		return counter;
				}

//Open output file 'filename' and write the following information:
// char* name
// double net income
// double taxes withheld
//These items should be separated by commas (no spaces), numbers should have two
//decimal points of precision, and numbers should have no padding (see example output)
		int writeSalaryInfoToFile(struct employee list[], int numEmployees, char* filename)
		{

		FILE *pointerFILE;
		// open the file 
		pointerFILE=fopen(filename,"w");


		if (pointerFILE==NULL)
		{
			printf("Error openning the file \n");
		return 1;
		}

			int i=0;

			for(i=0;i<numEmployees;i++)
			{
			fprintf(pointerFILE,"%s,%d,%.2lf,%.2lf\n", list[i].name,list[i].id,list[i].net_income,list[i].taxes_withheld);
			}




		fclose(pointerFILE);

		return 0;

		}














