#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	


if (argc!=2)
{
	printf("Error\n");
	return -1;
}

	const char *file_folder= argv[1];

	struct stat fileStats;

	if(stat(file_folder,&fileStats) < 0)
	{
		printf("Error Cannot Run Stats() System Call on the file/folder\n");
		return 1;
	}
	// printing the stats 
	printf("Stats for file: %s\n ",file_folder);
	printf("File Size %lld (Btyes)\n ",fileStats.st_size);
	printf("Number of Blocks: %lld \n",fileStats.st_blocks);
	printf("Number of Links: %hu \n",fileStats.st_nlink);
	
	printf("File permission: \n");
	
	printf((fileStats.st_mode & S_IRUSR)? "r":"-");// file permission 
	printf((fileStats.st_mode & S_IWUSR)? "w":"-");
	printf((fileStats.st_mode & S_IXUSR)? "x":"-");
	
	printf((fileStats.st_mode & S_IRGRP)? "r":"-");
	printf((fileStats.st_mode & S_IWGRP)? "w":"-");
	printf((fileStats.st_mode & S_IXGRP)? "x":"-");
	
	printf((fileStats.st_mode & S_IROTH)? "r":"-");
	printf((fileStats.st_mode & S_IWOTH)? "w":"-");
	printf((fileStats.st_mode & S_IXOTH)? "x":"-");
	printf("\n");
	printf("Number of Inode: %llu\n",fileStats.st_ino);
	
	return 0;
}
