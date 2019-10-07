#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#include<fcntl.h> 


int main () 
{ 

	// sample size (how many times loop runs for)
	int SAMPLE=1000000;
	// int for loop
	int i=0;
	
	// declaring timer varibales 
	struct timeval time1_begin,time2_end, empty_loop_begin, empty_loop_end;
	
	// timer start 
	gettimeofday(&time1_begin,NULL);



// loop for a function (getpid())
	for(;i<SAMPLE;i++)
	{

		getpid();
		 
    
	}
	// end of timer for function 
	gettimeofday(&time2_end,NULL);


// int for another loop 
int x=0;

// start to measure the cost of empty loop
	gettimeofday(&empty_loop_begin,NULL);

	for(;x<SAMPLE;x++){	}
	// end of empty loop 
	gettimeofday(&empty_loop_end,NULL);

	// difference of end and start for both loops 
	long int final_time=  (time2_end.tv_usec)-(time1_begin.tv_usec); 
	long int empty_loop= (empty_loop_end.tv_usec)- (empty_loop_begin.tv_usec);


// printing the results 
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");

    printf("(not conisder time to cost of loop)\n");
    printf(" time per %d system Calls %ld microseconds\n", SAMPLE,final_time);

    printf("\n");
    printf("\n");

	
	printf("(conisder time to cost of the loop without function)\n");
	printf("time per %d system Calls %ld microseconds\n",SAMPLE, empty_loop );
	printf("\n");
	printf("\n");

	printf(" time per one system call: %f microseconds \n",(final_time-empty_loop)/(1000000.0) );

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");


	


	












	return 0;
}