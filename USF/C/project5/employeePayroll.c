// ABDULRAHMAN Aldhubaiban


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "linkedList.h"

#define TAX_RATE  0.15f
#define FULL_TIME 40
#define OVERTIME_RATE_MULTIPLIER 1.5f

void getSalaryInfo(struct employee* emp);

int main(int argc, char* argv[])
{

// to make sure have three line argument 
 if(argc < 3)
         {
            printf("Usage: payroll <input filename> <output filename> \n\n");
          return 1;
         }

// to create a pointer point to the first of the list 
struct employee* list= buildEmployeeList( argv[1] );

// declaring variables
 struct employee *p;
  struct employee *ptr;
 int bonus=0;

for (p = list; p != NULL; p = p->next)
{
getSalaryInfo(p);


}




ptr=search(list,argv[3]);



char * amount =argv[4];

	strcpy(amount,argv[4]);

bonus=atoi(amount);

ptr->net_income+= bonus;



writeSalaryInfoToFile(list,argv[2]);


clearList(list);

}




void getSalaryInfo(struct employee* emp)
{
   if (emp->hours_worked<=40)
        {
             emp->taxes_withheld = emp->hours_worked  * emp->hourly_rate   *   TAX_RATE;
             emp->net_income=      emp->hours_worked  * emp->hourly_rate   - emp->taxes_withheld;
        }
    
             else if (emp->hours_worked>40)
             {
                     emp->taxes_withheld =         (emp->hourly_rate *FULL_TIME  +  (emp->hourly_rate*OVERTIME_RATE_MULTIPLIER * emp->hours_worked-FULL_TIME)) * TAX_RATE;
                     emp->net_income=              (emp->hourly_rate *FULL_TIME  +  (emp->hourly_rate*OVERTIME_RATE_MULTIPLIER * emp->hours_worked-FULL_TIME)) - emp->taxes_withheld;
             }
}
