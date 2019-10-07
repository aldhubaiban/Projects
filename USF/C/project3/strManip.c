#include "strManip.h"
#include <string.h>
#include <stdio.h>

// function to replace words to 'REDACTED'
	void replaceFunction(char *reading,char *argv)
{



	char *s = reading;
	char *p;


		p= strstr(s,argv);
		
		strncpy(p,"REDACTED",9);

		strcat(s,"\n\n\n\n After findnig the word it will replace it with 'REDACTED'\n then  it will stop after first word found   ");


}


// function to counts number of characters
	void charCounter(char *reading)
{


  


		printf("number of characters are: %u\n", (unsigned)strlen(reading)); 


}





// function to counts number of characters
	int wordCounter( char *reading)
{

int counter=0;
  
  	char * pch;
 
	pch = strtok (reading,"!?\n\t,.;: ");
  		
  		while (pch != NULL)
  		{
    counter++;
    pch = strtok (NULL, "!?\n\t,.;: ");
  		}
  
  
			printf("number of words are %d\n",counter);
	

	return counter;
}
