// ABDULRAHMAN Aldhubaiban
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "linkedList.h"




struct employee* buildEmployeeList(char * filename)
{
    			 
    			// open file
				FILE *pFILE; 
				pFILE=fopen(filename, "r");

// check if the file can be opened 
	if (pFILE==NULL)
	{
	printf("Error openning the file \n");
	
	}



			 
	struct employee *first=NULL;
  


   while (!feof(pFILE) && !ferror(pFILE))
    {


 


	struct employee *temporary=malloc(sizeof(struct employee))  ;
 	

 	if (temporary==NULL)
 	{


 		printf("memory allocation failled");
 		return NULL;
 	}
 	

    fscanf(pFILE, "%s %d %lf %lf\n", temporary->name, &temporary->id, &temporary->hours_worked, &temporary->hourly_rate);



    temporary->net_income=0.0;    

	temporary->taxes_withheld=0.0;

    temporary->next= NULL ;

    first=append(first,temporary);

   
	}
	 	
    
	

	fclose(pFILE); 
		
	return first;
}



void writeSalaryInfoToFile(struct employee* listHead, char* filename)
{


	FILE* f = fopen(filename, "w");


    if(f == NULL){

   printf("cannot open\n"); 
    	return ;
				}	

	struct employee *temp = listHead;
    
  
   while(temp!=NULL){

       


        fprintf(f,"%s,%d,%.2lf,%.2lf\n", temp->name, temp->id,temp->net_income, temp->taxes_withheld);
      
        temp=temp->next;

    }

    fclose(f);


    


}
