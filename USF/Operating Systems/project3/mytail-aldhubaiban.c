#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1

int c = 0;

void read_nlines(int fd,long number)
{
	
	char buffer[BUFSIZE];
	int pos=0;
	long int length=lseek(fd, 0, SEEK_END);//gone to the end of file
	if (number == 0)
	{
		return;
	}
	//number++;//as we are reading backward we get one less line break
	if(length==0)//file is empty
	{
		return;
	}
	while(number>0)
	{
		
		pos=pos-BUFSIZE;
		lseek (fd, pos, SEEK_END);
		read (fd, &buffer, BUFSIZE);
		if(buffer[0] == '\n') // strcmp( &buffer, "\n") == 0
		{
			number--;
			
		}
		c++;
	}
}
void print_func(int fp)
{
	char buffer[c+1];
	while (read (fp, buffer, c) > 0)
    {
    	printf("\n");
		printf("%s", buffer);
		printf("\n");
    }
}
int main(int argc, char *argv[])
{
	int fp;
	char *file = argv[2];
	if(argc<3)
	{
		printf("Usage: mytail -n file\n");
		printf("Usage: mytail -5 file\n");
		return 1;
	}
	else
	{
		char *len= argv[1];
		len = len +1;//getting only numeric part
		if((fp = open(file,O_RDONLY))< -1)
		{
			printf("Cannot Open file %s",file);
			return 1;
		}
		long lines=strtol(len,NULL,10);
		
		read_nlines(fp,lines);
		print_func(fp);
		close(fp);
	}
	return 0;
}
