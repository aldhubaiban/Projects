
/*Abdulrahman ALdhubaiban 
U  16706634 

*/


    // include libraries 
        #include <stdio.h>
        #include <string.h>
        #include "employee.h"
        

        // define constants 
        #define TAX_RATE  0.15f
        #define FULL_TIME 40
        #define OVERTIME_RATE_MULTIPLIER 1.5f




                // calling functions 
                void getSalaryInfo(struct employee* emp);
                int findMax(struct employee a[], int n);
                void selectionSort(struct employee a[], int n);

//you probably shouldn't need to alter main...
    int main(int argc, char* argv[])
    {
        

        struct employee list[MAX_NUM_EMPLOYEES];

        if(argc < 3)
         {
            printf("Usage: payroll <input filename> <output filename>\n\n");
          return 1;
         }

         //Build list of employees
         int numEmployees = buildEmployeeList(list, argv[1]);
	
	       int i=0;
         //calculate employee income
            for(i = 0; i < numEmployees; i++)
            {
                getSalaryInfo(&list[i]); //pass pointer to struct
            }


	       selectionSort(list,numEmployees);

            //Write employee income to output file
            writeSalaryInfoToFile(list, numEmployees, argv[2]);
    }

//calculate net income and taxes withheld - adapt your code from project 1!
//Store the results in the corresponding members of the struct pointed to by 'emp'
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









int findMax(struct employee a[], int n)
{
            int maxIndex = 0;
            for(int i=1; i<n; i++)
            {
                if ( strcmp (a[i].name,a[maxIndex].name) > 0 )
                 maxIndex=i;

            }
    
    return maxIndex;
}

void selectionSort(struct employee a[], int n)
{
    if(n > 1)
    {
        //Find index of largest element in subarray
        int maxIndex = findMax(a,n);

        //Swap this element with the last element in the subarray
        struct employee temp = a[n-1];
        a[n-1] = a[maxIndex];
        a[maxIndex] = temp;

        //Recurrsive call to sort next smallest subaray (size n-1)
        selectionSort(a,n-1);
    }
}


