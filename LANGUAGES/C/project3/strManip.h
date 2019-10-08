#ifndef STRMANIP_H
#define STRMANIP_H
#include <string.h>
#include <stdio.h>
//place your string manipulation function declarations here


void replaceFunction(char *reading,char *argv);
/*



replace the BLACKLISTED words to "REDACTED" 

* reading to the file 

*argv points to the command line pointer

*/

void charCounter(char *reading);
/*



counts how many characters in the file  
* reading to the file 


after reading it it will prints how many characters

*/


int wordCounter(char *reading);



/*



counts how many words in the file  
* reading to the file 

after reading it it will prints how many words



*/


#endif //STRMANIP_H
