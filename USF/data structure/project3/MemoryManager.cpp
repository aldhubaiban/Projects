#include <cassert>
#include <iostream>
#include "MemoryManager.h"

MemoryManager::MemoryManager(unsigned int memtotal)
{
   memsize = memtotal; // size of the "heap"
   baseptr = new unsigned char[memsize]; // allocate the heap
   // create empty blocknode list
   header = new blocknode();
   trailer = new blocknode();
   header->next = trailer;
   trailer->prev = header;
   // create blocknode to represent the entire heap
   blocknode *  originalBlocknode = new blocknode(memsize,baseptr,true);  
   header->insertAfter(originalBlocknode);
}

void MemoryManager::showBlockList() 
{
   blocknode *tmp = header->next;
   while(tmp->next != trailer) {
      cout << tmp << "->";
      tmp = tmp->next;
   }
   cout << tmp << "\n\n";
}

void MemoryManager::splitBlock(blocknode *p, unsigned int chunksize)
{

// creating a new block
blocknode *newP = new blocknode (p->blocksize-chunksize, p->blockptr+chunksize,true);


// insert it after p
p->insertAfter(newP);

  
}

unsigned char * MemoryManager::malloc(unsigned int request)
{
// allocating allowed after header 
blocknode * temp=header->next;

// looping until trailer 
while (temp!=trailer)
{

   if(temp->blocksize==request &&temp->free==true)
  {
    temp->free=false;
    temp->blocksize = request;
    break;
  }
  else if(temp->blocksize>request &&temp->free==true)
  {
    temp->free=false;
    splitBlock(temp,request);
    temp->blocksize=request;
    break;
  }
 



    temp=temp->next;
  

}
// if requested was trailer is not allowed 
 if (temp==trailer)
  {
    
    return nullptr;
  }
  else 

return temp->blockptr;

}

void MemoryManager::mergeForward(blocknode *p)
{

blocknode *temp=p->next;

p->blocksize+=p->next->blocksize;

//MAKE SENSE
p->next=temp->next;

p->next->prev=p;
delete temp;
}

void MemoryManager::mergeBackward(blocknode *p)
{ 
blocknode *temp=p->prev;

p->blocksize+=p->prev->blocksize;


p->prev=temp->prev;

p->prev->next=p;
p->blockptr=temp->blockptr;
delete temp;
}

void MemoryManager::free(unsigned char *ptr2block)
{


blocknode * temp=header->next;

//trailer->free=false;


while (temp->blockptr!=ptr2block )
{
temp=temp->next;
}

assert(temp != trailer);

  temp->free=true;

// check this syntax
if (temp->next->free==true)
{
mergeForward(temp);
}


if(temp->prev->free==true)
{
  mergeBackward(temp);
}









}




