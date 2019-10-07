#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"



void enqueue(Q*q, page* items)
{
if (q->elements==q->size){printf("queue is FULL. NO ITEM CAN BE ADDED\n"); return;}

q->arrays[q->elements].vpf= items -> vpf;
q->arrays[q->elements].dirty=items -> dirty;
q->elements=q->elements+1;
return;

}

void shift (Q *q)
{
	int i;
	for (i=0;i<q->elements-1;i++)
	{
		q->arrays[i].vpf=q->arrays[i+1].vpf;
		q->arrays[i].dirty=q->arrays[i+1].dirty;

	}
	q->arrays[q->elements-1].vpf=0;
	q->arrays[q->elements-1].dirty=0;
	
}



void dequeue(Q *q)
{
	shift(q);
	if (q->elements!=0)
	q->elements=q->elements-1;

	
}
bool full_q(Q *q)
{
	if (q->elements==q->size)
	{
		return true;
	}
	return false;
}
bool empty_q(Q *q)
{
	if (q->elements==0)
		return true;
	return false;
}

int match(Q *q, page *item)
{
	int i;
	for (i=0;i<q->elements;i++)
	{
		if(q->arrays[i].vpf==item->vpf)
		{
			return i; // matched 
		}
	}
	return -1;// indicate not matched 
}

page front (Q *q) // return first elemnt of queue 
{
	
	return q->arrays[0];
}

void print_queue (Q *q)
{
	int i;
	printf("\nBEGINS HERE {");
	for (i=0;i<q->elements;i++)
	{
		printf(" %x",q->arrays[i].vpf );
		if (i!=q->elements)
		{
			printf("\n");
		}
	}
	printf("} ENDS HERE \n");
}
void allocate_memory(Q *q,int S)
{
	q->arrays= (page*) malloc(sizeof(page) *S);
	if (q->arrays==NULL)
	{
		printf("Failed to malloc\n");
		exit(1);
	} 
	q->elements=0;
	q->size=S;
}
void deallocate (Q *q)
{   
	free(q->arrays); 
	free(q);
} 


void shift_LRU (Q *q, int begin)
{

int i;
	for (i=begin;i<q->elements-1;i++)
	{
		q->arrays[i].vpf=q->arrays[i+1].vpf;
		q->arrays[i].dirty=q->arrays[i+1].dirty;

	}
	q->arrays[q->elements-1].vpf=0;
	q->arrays[q->elements-1].dirty=0;
	
}

void remove_LRU(Q *q, int begin)
{
	shift_LRU(q,begin);
	q->elements=q->elements-1;
}



