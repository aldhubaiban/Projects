#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

// function decleration 
void fifo(char *filename, int frames, char *output);
void lru(char *filename, int frames, char *output);
void vms(char *filename, int frames, char *output);
// main to get from command line 
int main(int argc, char *argv[])
{
	if (argc!=5)
	{
		printf("Command LINE Should be :\nmemsim <tracefile> <nframes> <lru|fifo|vms> <debug|quiet>\n\n");
	}
		if (strcmp(argv[3],"fifo") == 0)
		{
		fifo(argv[1], atoi(argv[2]), argv[4]);
		}
		if (strcmp(argv[3],"lru") == 0){
		lru(argv[1], atoi(argv[2]), argv[4]);
		}
			if (strcmp(argv[3],"vms") == 0){
		vms(argv[1], atoi(argv[2]), argv[4]);
		}
return 0;
}
// first in first out policy 
void fifo(char *filename, int nframes, char *output)
{
// memory queue  
Q *memory;
memory=(Q*) malloc(sizeof(Q));
if(memory== NULL)	{printf(" failed to malloc\n"); // malloc Failed 
	exit(1);}
allocate_memory(memory,nframes);
unsigned addr;	//address 
char rw;	//read or write 
int write=0; // number of write on disk
int read=0;  //number of read on disk
int trace=0; // events readed from file 
int hit=0; // number of hits
int miss=0; // number of misses 
// open a file 
FILE *file; 	
file=fopen(filename,"r");
if(file== NULL)	
{
printf(" File cannot be Found \n");
exit(1);
}
while(   fscanf(file,"%x %c",&addr,&rw)!= EOF  )// a loop for read a file 
{
	trace+=1; // tarce how many reads occurs 
// page tracing 
	page *p;
	p=(page*) malloc(sizeof(p));
	if(p== NULL)	{printf(" failed to malloc\n"); // malloc Failed 
	exit(1);}

	p->vpf= addr/4096; // right shift of 12 bit  (divided by 2^12) 
	p->dirty=0;

	// debug 
	if(strcmp(output, "debug") == 0)
	{
		printf("current trace %d \n",trace);
		printf("current virtual address %x \n", addr);
		printf("current access type %c \n", rw);
		printf("current virtual page frame %x \n", p->vpf);
	}
	// page in memory  
	if (match(memory,p)!=-1)
	{hit++; // hit +1 	
		if (rw=='W')
		{
			memory->arrays[match(memory,p)].dirty=1; //set dirty bit  
		}
	}
	// page not found in memory 
	else 
		{
			miss++; // miss +1
			// memory is full 
			if (full_q(memory))
			{
				if (front(memory).dirty==1)
				{
					write++;
				}// write to desk 
				dequeue(memory);
			}
			// read from desk
			read++;
			if (rw=='W')// acccess type = Write set dirty then load to memory 
			{
				p->dirty=1;
			}
			enqueue(memory,p);
		}
		free (p); // free page 
		// debug
		if(strcmp(output, "debug") == 0)
	{
		printf("current trace %d \n",trace);
		printf("current read %d \n", read);
		printf("current write  %d \n", write);
	}
}
fclose(file);
deallocate(memory);// close file a deallocate memory 
if(strcmp(output, "quiet") == 0)// print overall output 
	{
	printf("total memory frames: %d\n", nframes);
	printf("events in trace: %d\n", trace);
	printf("total disk reads: %d\n", read);
	printf("total disk writes: %d\n", write);
	printf("# of hits %d\n", hit);
	printf("# of misses %d\n",miss );
	}
}
// Least Recently Used policy 
void lru(char *filename, int nframes, char *output)
{
	// declare a memory queue  
Q *memory;
memory=(Q*) malloc(sizeof(Q));
if(memory== NULL)	{printf(" failed to malloc\n"); // malloc Failed 
	exit(1);}
allocate_memory(memory,nframes);

unsigned addr;	//address 
char rw;	//read or write 
int write=0; // number of write on disk
int read=0;  //number of read on disk
int trace=0; // events readed from file 
int hit=0; // number of hits
int miss=0; // number of misses 
//open file
FILE *file; 	
file=fopen(filename,"r");
if(file== NULL)	
{
printf(" File cannot be Found \n");
exit(1);
}

while(   fscanf(file,"%x %c",&addr,&rw)!= EOF  )// a loop for read a file
{
	trace++; // tarce how many reads occurs 
	page *p;
	p=(page*) malloc(sizeof(p));
	if(p== NULL)	{printf(" failed to malloc\n"); // malloc Failed 
	exit(1);}

	p->vpf= addr/4096; // right shift of 12 bit 
	p->dirty=0;

		if(strcmp(output, "debug") == 0)
	{
		printf("current trace %d \n",trace);
		printf("current virtual address %x \n", addr);
		printf("current access type %c \n", rw);
		printf("current virtual page frame %x \n", p->vpf);
	}
	// page in memory 
	if(match(memory,p) !=-1)
	{hit++; //hit+1
		
		if(rw=='W')
		{p->dirty=1;}//acccess type = Write set dirty 
	remove_LRU(memory,match(memory,p)); // add page to the end 
	enqueue(memory,p);

	}
	else // page is not in memory 
	{miss++;
			if (full_q(memory)) // memory is full 
			{
				if (memory->arrays[0].dirty==1)
				{
					write++;
				}
				remove_LRU(memory,0);
			}
			read++; // read page to be loaded from disk 
			if (rw=='W')
			{
				p->dirty=1;
			}
			enqueue(memory,p);
	}
	free(p);

		if(strcmp(output, "debug") == 0)
	{
		printf("current trace %d \n",trace);
		printf("current read %d \n", read);
		printf("current write  %d \n", write);
	}
}
fclose(file);
deallocate(memory);

if(strcmp(output, "quiet") == 0)
	{
	printf("total memory frames: %d\n", nframes);
	printf("events in trace: %d\n", trace);
	printf("total disk reads: %d\n", read);
	printf("total disk writes: %d\n", write);	
	printf("# of hits %d\n", hit);
	printf("# of misses %d\n",miss );
	}

}
void vms(char *filename, int nframes, char *output)
{

Q *memory; // memory
memory=(Q*) malloc(sizeof(Q));
if(memory== NULL)	{printf(" failed to malloc\n"); // malloc Failed 
	exit(1);}
allocate_memory(memory,nframes);
Q *clean; // clean
clean=(Q*) malloc(sizeof(Q));
if(clean== NULL)	{printf(" failed to malloc\n"); // malloc Failed 
	exit(1);}
allocate_memory(clean,(nframes/2)+1);
Q *dirty; // dirty 
dirty=(Q*) malloc(sizeof(Q));
if(dirty== NULL)	{printf(" failed to malloc\n"); // malloc Failed 
	exit(1);}
allocate_memory(dirty,(nframes/2)+1);
Q *FIFO_A; // process A
FIFO_A=(Q*) malloc(sizeof(Q));
if(FIFO_A== NULL)	{printf(" failed to malloc\n"); // malloc Failed 
	exit(1);}
allocate_memory(FIFO_A,nframes/2);
Q *FIFO_B; // process B 
FIFO_B=(Q*) malloc(sizeof(Q));
if(FIFO_B== NULL)	{printf(" failed to malloc\n"); // malloc Failed 
	exit(1);}
allocate_memory(FIFO_B,nframes/2);

unsigned addr;	//address 
char rw;	//read or write 
unsigned FiFo_3=0; // to check hex address for process A or other processes 
int write=0; // number of write on disk
int read=0;  //number of read on disk
int trace=0; // events readed from file 
int hit=0; // number of hits
int miss=0; // number of misses 
FILE *file; 	
file=fopen(filename,"r");
if(file== NULL)	
{
printf(" File cannot be Found \n");
exit(1);
}

while(   fscanf(file,"%x %c",&addr,&rw)!= EOF  )
{
	
	page *p;
	p=(page*) malloc(sizeof(page));
	if(p== NULL)	{printf(" failed to malloc\n"); // malloc Failed 
	exit(1);}

	page *temp;
	temp=(page*) malloc(sizeof(page));
	if(p== NULL)	{printf(" failed to malloc\n"); // malloc Failed 
	exit(1);}

	trace++;
	p->vpf=addr/4096;

	if (rw=='W')
	{p->dirty=1;}
	else{p->dirty=0;} 
		if(strcmp(output, "debug") == 0)
	{
		printf("current trace %d \n",trace);
		printf("current virtual address %x \n", addr);
		printf("current access type %c \n", rw);
		printf("current virtual page frame %x \n", p->vpf);
		printf("Hex address begin with '3' %x \n", FiFo_3);
	}

		FiFo_3=addr/268435456; // right shift for 28 bit (2^28 ) to get hex address
	if (FiFo_3==(unsigned)3) // compare if it belgon to prcessor A or others 
	{
		//page found in proccess A
		if (match(FIFO_A,p)!=-1)
		{hit++;
			if (rw=='W')
			{
				FIFO_A->arrays[match(FIFO_A,p)].dirty=1;
			}
		}
		

		//page is not found in FIFO_A
		else 
		{	
			if (match(clean,p)!=-1) // looking in clean (second chance ) 
			{hit++;

				if (full_q(FIFO_A)) // if found in clean but fifoA is full take first element to either clean or dirty 
				{
					temp-> vpf=front(FIFO_A).vpf;
					temp->dirty=front(FIFO_A).dirty;
					if (front(FIFO_A).dirty==1)
					{
						enqueue(dirty,temp);
					}
						else 
						{
							enqueue(clean,temp);
						}
						dequeue(FIFO_A);
				}
				// not full just add it to A and delete it from clean 
				temp->vpf=clean->arrays[match(clean,p)].vpf;
				temp->dirty=clean->arrays[match(clean,p)].dirty;
				enqueue(FIFO_A,temp);
				remove_LRU(clean,match(clean,p));
				hit ++;

			}
			// search in dirty 
			else if (match(dirty,p)!=-1)
			{hit++;
				if (full_q(FIFO_A))// if found in dirty but fifoA is full take first element to either clean or dirty 
				{
					temp-> vpf=front(FIFO_A).vpf;
					temp->dirty=front(FIFO_A).dirty;
					if (front(FIFO_A).dirty==1)
					{
						enqueue(dirty,temp);
					}
						else 
						{
							enqueue(clean,temp);
						}
						dequeue(FIFO_A);
				}
				// not full just add it to A and delete it from dirty 
				temp->vpf=dirty->arrays[match(dirty,p)].vpf;
				temp->dirty=dirty->arrays[match(dirty,p)].dirty;
				enqueue(FIFO_A,temp);
				remove_LRU(dirty,match(dirty,p));

			}
			else 
			{ miss++;
				read++; // read from disk 
					 if (!full_q(FIFO_A) && !full_q(memory)) // if both are not full just add it //(life is easy )
				{

					enqueue(FIFO_A,p);
					enqueue(memory,p);
				}


				// check weather memory is full or A is full if both are not full just add directly 
				else if(full_q(memory) && full_q(FIFO_A)) // both are full (check if clean is not empty or dirty is not empty)
				{
					if(!empty_q(clean))
					{
						temp->vpf=clean->arrays[0].vpf;
						temp->dirty=clean->arrays[0].dirty;
						remove_LRU(clean,0);
						remove_LRU(memory,match(memory,temp));
						temp-> vpf=front(FIFO_A).vpf;
						temp->dirty=front(FIFO_A).dirty;

						if(temp->dirty==1)
						{
							enqueue(dirty,temp);
						}
						else {enqueue(clean,temp);}
					}

					else if(!empty_q(dirty))
					{
						temp->vpf=dirty->arrays[0].vpf;
						temp->dirty=dirty->arrays[0].dirty;

						remove_LRU(dirty,0);
						remove_LRU(memory,match(memory,temp));
						temp-> vpf=front(FIFO_A).vpf;
						temp->dirty=front(FIFO_A).dirty;

						if(temp->dirty==1)
						{
							enqueue(dirty,temp);
						}
						else {enqueue(clean,temp);}
					}
					else
					{
						temp-> vpf=front(FIFO_A).vpf;
						temp->dirty=front(FIFO_A).dirty;
						remove_LRU(memory,match(memory,temp));
						if(temp->dirty)
							{write++;}
						
					}

					dequeue(FIFO_A);
					enqueue(FIFO_A,p);
					enqueue(memory,p);

				}


				else if (full_q(FIFO_A) && !full_q(memory)) // (fifa_A is full but memory is not) take first elemnt save to dirty or clean
				{ 											// then remove it from A 
						temp-> vpf=front(FIFO_A).vpf;
						temp->dirty=front(FIFO_A).dirty;

						if (front(FIFO_A).dirty==1)
						{
							enqueue(dirty,temp);
						}
						else
						{
							enqueue(clean,temp);
						}
						dequeue(FIFO_A);
						enqueue(FIFO_A,p);
						enqueue(memory,p);
				}


				else if (!full_q(FIFO_A) && full_q(memory)) // fifa A is not full but memory is full (check clean and dirty are not empty)
				{											
						
						if (!empty_q(clean))
						{
						temp->vpf=clean ->arrays[0].vpf;
						temp->dirty=clean ->arrays[0].dirty;
						if (temp->dirty){write++;};// write to disk if dirty 
						remove_LRU(memory,match(memory,temp));
						remove_LRU(clean,0); // remove first element from clean 
						}
						else if(!empty_q(dirty))
						{
						temp->vpf=dirty->arrays[0].vpf;
						temp->dirty=dirty->arrays[0].dirty;

						if (temp->dirty){write++;};

						remove_LRU(memory,match(memory,temp));
						remove_LRU(dirty,0);
						
						}
						else //if both dirty and clean are empty just erase first element from memory then add it to FIFA_A
						{
							temp-> vpf=front(FIFO_A).vpf;
							temp->dirty=front(FIFO_A).dirty;
							remove_LRU(memory,match(memory,temp));
							dequeue(FIFO_A);
						}
						enqueue(FIFO_A,p);
						enqueue(memory,p);						
				}
			}
		}
	}

	// could have used function to avoid redundancy ...  
// process FIFO_B 
	else 
	{	//page found in FIFO_B 
		if (match(FIFO_B,p)!=-1)
		{hit++;
			if (rw=='W')
			{
				FIFO_B->arrays[match(FIFO_B,p)].dirty=1;
			}
		}
		else //page not found in FIFO_B 
		{
			if (match(clean,p)!=-1)// looking in clean (second chance ) 
			{hit++;
				if (full_q(FIFO_B)) // if found in clean but fifoA is full take first element to either clean or dirty
				{
					temp-> vpf=front(FIFO_B).vpf;
					temp->dirty=front(FIFO_B).dirty;
					if (front(FIFO_B).dirty==1)
					{
						enqueue(dirty,temp);
					}
						else 
						{
							enqueue(clean,temp);
						}
						dequeue(FIFO_B);
				}
				// not full just add it to A and delete it from clean 
				temp->vpf=clean->arrays[match(clean,p)].vpf;
				temp->dirty=clean->arrays[match(clean,p)].dirty;
				enqueue(FIFO_B,temp);
				remove_LRU(clean,match(clean,p));
			}

			else if (match(dirty,p)!=-1)// search in dirty 
			{hit++;
				if (full_q(FIFO_B))// if found in dirty but fifoA is full take first element to either clean or dirty 
				{
					temp-> vpf= front(FIFO_B).vpf;
					temp->dirty=front(FIFO_B).dirty;
					if(front(FIFO_B).dirty ==1)
					{
						enqueue(dirty,temp);
					}
					else
					{
						enqueue(clean,temp);
					}
					dequeue(FIFO_B);
				}
				// not full just add it to A and delete it from dirty 
				temp->vpf=dirty->arrays[match(dirty,p)].vpf;
				temp-> dirty= dirty->arrays[match(dirty,p)].dirty;
				enqueue(FIFO_B,temp);
				remove_LRU(dirty,match(dirty,p));
			}


			// miss 
			else 
			{// check weather memory is full or FIFO_B is full if both are not full just add directly 
				miss++;
				read++;
					if (!full_q(FIFO_B) && !full_q(memory))// if both are not full just add it //(life is easy )
				{			
					enqueue(FIFO_B,p);
					enqueue(memory,p);
				}




				else if(full_q(memory) && full_q(FIFO_B))// both are full (check if clean is not empty or dirty is not empty)
				{
					if(!empty_q(clean))
					{
						temp->vpf=clean->arrays[0].vpf;
						temp->dirty=clean->arrays[0].dirty;
						remove_LRU(clean,0);
						remove_LRU(memory,match(memory,temp));
						temp-> vpf=front(FIFO_B).vpf;
						temp->dirty=front(FIFO_B).dirty;

						if(temp->dirty==1)
						{
							enqueue(dirty,temp);
						}
						else {enqueue(clean,temp);}
					}
					else if(!empty_q(dirty))
					{
						temp->vpf=dirty->arrays[0].vpf;
						temp->dirty=dirty->arrays[0].dirty;

						remove_LRU(dirty,0);
						remove_LRU(memory,match(memory,temp));
						temp-> vpf=front(FIFO_B).vpf;
						temp->dirty=front(FIFO_B).dirty;

						if(temp->dirty==1)
						{
							enqueue(dirty,temp);
						}
						else {enqueue(clean,temp);}
					}
					else
					{
						temp-> vpf=front(FIFO_B).vpf;
						temp->dirty=front(FIFO_B).dirty;
						remove_LRU(memory,match(memory,temp));
						if(temp->dirty)
						{
							write++;
						}
					}
					dequeue(FIFO_B);
					enqueue(FIFO_B,p);
					enqueue(memory,p);
				}




				else if (full_q(FIFO_B) && !full_q(memory))// (fifa_A is full but memory is not) take first elemnt save to dirty or clean
				{										   // then remove it from B
						temp-> vpf=front(FIFO_B).vpf;
						temp->dirty=front(FIFO_B).dirty;

						if (front(FIFO_B).dirty==1)
						{
							enqueue(dirty,temp);
						}
						else
						{
							enqueue(clean,temp);
						}
						dequeue(FIFO_B);
						enqueue(FIFO_B,p);
						enqueue(memory,p);
				}



				else if (!full_q(FIFO_B) && full_q(memory))// fifa A is not full but memory is full (check clean and dirty are not empty)
				{
						
						if (!empty_q(clean))
						{
						temp->vpf=clean ->arrays[0].vpf;
						temp->dirty=clean ->arrays[0].dirty;
						if (temp->dirty) {write++;}
						remove_LRU(memory,match(memory,temp));
						remove_LRU(clean,0);
						}
						else if(!empty_q(dirty))
						{
						temp->vpf=dirty->arrays[0].vpf;
						temp->dirty=dirty->arrays[0].dirty;
						if (temp->dirty){write++;}
						remove_LRU(memory,match(memory,temp));
						remove_LRU(dirty,0);
						}
						else 
						{
							temp-> vpf=front(FIFO_B).vpf;
							temp->dirty=front(FIFO_B).dirty;

							remove_LRU(memory,match(memory,temp));
							dequeue(FIFO_B);
						}
						enqueue(FIFO_B,p);
						enqueue(memory,p);									
				}
			}
		}
	}
	free(p);
	free(temp);
}
fclose(file);
deallocate(memory); //free all memories (memory, clean,fifo_a,fifo_B,dirty)
deallocate(FIFO_A);
deallocate(FIFO_B);
deallocate(clean);
deallocate(dirty);
	if(strcmp(output, "quiet") == 0)
	{
	printf("total memory frames: %d\n", nframes);
	printf("events in trace: %d\n", trace);
	printf("total disk reads: %d\n", read);
	printf("total disk writes: %d\n", write);
	printf("# of hits %d\n", hit);
	printf("# of misses %d\n",miss );	
	}
}