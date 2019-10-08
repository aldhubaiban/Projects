/*
Cost of Context Switch 
Abdulrahman Aldhubaiban
Tracy Jackson
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <sched.h>
int main ()
{
// set timers 
struct timeval time1_begin,time2_end;
struct timeval empty_loop_begin, empty_loop_end;




// size of the loop 
int sample_size=10000;
// CPU 
cpu_set_t my_set;
CPU_ZERO(&my_set);
CPU_SET(0, &my_set);
unsigned int length_of_CPU= sizeof(&my_set);
// PIPE 
char BUFFER[1000];
int byte_lenght;
pid_t pid;
int mypipe[2];
// empty string to read and write 
char STRING_thing[]= "";


// fails to pipe 
if(pipe(mypipe)==-1)
{
	printf("PIPE FAILES\n");
	exit(1);
}
// fails to fork();
if((pid=fork())==-1)
{
printf("FORK FAILS\n");
exit(1);
}


// timer start 
gettimeofday(&time1_begin,NULL);
int i=0;
//array to store cost of context switch every time 
long int timer[sample_size+1];
for(;i<sample_size;i++){
	if (sched_setaffinity(0,length_of_CPU,&my_set) <1)
	{

		if(pid==0)
		{
		// close input of read and write the parents 
		close(mypipe[0]);
		write(mypipe[1], STRING_thing, (strlen(STRING_thing)+1));
		exit(0);

		}
			else 
			{// read from child and close write pipe
			byte_lenght = read(mypipe[0], BUFFER, sizeof(BUFFER));
			gettimeofday(&time2_end,NULL);
			// adding sample of time 
			timer[i]=(time2_end.tv_usec)-(time1_begin.tv_usec);

			
			//end timer 
			close (mypipe[1]);
			}

	}// end of if for CPU 
}// end of for loop 


int x=0;
// variable to show average of cost 
long int final_time;

//to add all the tries into single variable 
for(;x<sample_size;x++)
{
final_time+=timer[x];
}



gettimeofday(&empty_loop_begin,NULL);

	for(;x<sample_size;x++){	}
	// end of empty loop 
	gettimeofday(&empty_loop_end,NULL);

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");

	// difference of end and start for loop 
	long int empty_loop= (empty_loop_end.tv_usec)- (empty_loop_begin.tv_usec);
	printf("(conisder time to cost of the loop without function)\n");
	printf("time per %d system Calls is %ld microseconds\n",sample_size, empty_loop );
	printf("\n");
	printf("\n");

	final_time=final_time-	empty_loop;


printf(" cost of context switch on %d trials is%ld microseconds\n",sample_size,final_time );


	
printf("average cost of context switch is%lf\n microseconds",final_time/10000.0 );

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");

	return 0;
}