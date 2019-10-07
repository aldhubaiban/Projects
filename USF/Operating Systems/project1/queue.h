#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// page have virtual page frame and a dirty bit 
typedef struct page 
{

unsigned vpf ;// virtual page frame 
int dirty ; // dirty bit 

} page;
// queue declration usuing arrays  
typedef struct Q
{
page *arrays ;//
int elements   ; // elements number 
int size ;
}Q; 
// Queue Functions  
void enqueue( Q *q,  page* items);
void shift (Q *q);
void dequeue(Q *q);
bool full_q(Q *q);
bool empty_q(Q *q);
int match(Q *q, page *p);
page front (Q *q);
void print_queue (Q *q);
void allocate_memory(Q *q,int S);
void deallocate (Q *q);
// function  for LRU  manny common function between FIFO AND LRU 
void shift_LRU (Q *q, int begin);
void remove_LRU(Q *q, int begin);
