#include "fileUtils.h"
#include "strManip.h"
#include <stdio.h>
#include <string.h>



int main(int argc, char* argv[]) 
{
    
		int wordcounter=0;
		int i=0;
					
   					

   					char* inputFilename =  argv[1];

   					char* outputFilename =  argv[2];

   					char p[MAX_CHAR_COUNT];
					
					
					char q[MAX_CHAR_COUNT];

   					char str[MAX_CHAR_COUNT];



// to read from a file 
readFromFile(str,inputFilename);
  

  	//copy str to p
	strcpy(p,str);

	// pass p for charCounter
	charCounter(p);
  
  	// pass p for wordCounter
 	 wordcounter=wordCounter(p);
  
  	// read from the file  for q
   	readFromFile(q,inputFilename);


				// command line for argv and limited to argc
				for (i=3;i<argc;i++)
				{

				replaceFunction(q,argv[i]);

				}

		// prints out the string after replacing function 
	puts(q);



   writeToFile(q,outputFilename,0);

return 0;
}
