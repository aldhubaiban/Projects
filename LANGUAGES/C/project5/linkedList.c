// ABDULRAHMAN Aldhubaiban
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedList.h"
#include "employee.h"

//Add the struct 'emp' to the end of the linked list pointed to
//by 'listHead' (the first node in the list)
//return a pointer to the first node in the list (listHead)
struct employee* append(struct employee* listHead, struct employee* emp)
{
	// for the first node 
	if(listHead== NULL)
	{

	listHead = emp;
	emp->next = NULL;
	}

	// to check the rest of the nodes 
	else {
	
	struct employee *cur = listHead;

	while (cur->next != NULL)
	{
		cur = cur->next; 
	}
	cur->next = emp;
	
	emp->next = NULL;


		}




// return the listhead 
 return listHead;
}

// a function for search 
struct employee* search(struct employee* listHead, char* name)
{

	struct employee *p;  

	for (p = listHead; p != NULL; p = p->next)   
    {
    
    if (strcmp(p->name, name) ==0)
    {      
	
	return p;
    }
	}



	return NULL;

}

//delete all nodes in the list. This means freeing memory
void clearList(struct employee* listHead)
{

struct employee * p;

  while(listHead != NULL)  
 {    
 	p = listHead;     
 	listHead = listHead->next;    

   if( p!= NULL)          
   free(p);  
}

}
