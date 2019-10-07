#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	DIR *d;
	struct dirent *dir;
	char *dir_path=".";
	int options = 0;//false
	if(argc == 3)// we must be pass -l as well
	{
		dir_path= argv[2];
		if(strcmp (argv[1],"-l")==0)
		{
			options =1;// true
		}
		
	}
	else if(argc ==2)
	{
		if(strcmp (argv[1],"-l")==0)
		{
			options =1;// true
		}
	}
	d = opendir(dir_path);//opening directory
	if(d)
	{
		if (options==0)//show only files
		{
			while ((dir = readdir(d)) != NULL)
			{
				if(dir->d_type!=DT_DIR)//ignoring directories
				{
					printf("%s\n", dir->d_name);
				}
			}
		}
		else
		{
			while ((dir = readdir(d)) != NULL)
			{
				if(dir->d_type!=DT_DIR)//ignoring directories
				{
					struct stat fileStats;
					char p[2000]="";
					strcat(p,dir_path);
					strcat(p,"/");
					// full path for stat 
					strcat(p,dir->d_name);
					if(stat(p,&fileStats) < 0)
					{
						printf("Error Cannot Run Stats() System Call on the %s\n",dir->d_name);
						return 1;
					}
					else
					{
							printf("Stats for file: %s\n ",p);
						printf("File Size %lld (Btyes)\n ",fileStats.st_size);
						printf("Number of Blocks: %lld \n",fileStats.st_blocks);
						printf("Number of Links: %hu \n",fileStats.st_nlink);
						


						// printing file permission
						printf("File permission: \n");
						printf("%-s ", dir->d_name);
						printf((fileStats.st_mode & S_IRUSR)? "r":"-");
						printf((fileStats.st_mode & S_IWUSR)? "w":"-");
						printf((fileStats.st_mode & S_IXUSR)? "x":"-");
						printf((fileStats.st_mode & S_IRGRP)? "r":"-");
						printf((fileStats.st_mode & S_IWGRP)? "w":"-");
						printf((fileStats.st_mode & S_IXGRP)? "x":"-");
						printf((fileStats.st_mode & S_IROTH)? "r":"-");
						printf((fileStats.st_mode & S_IWOTH)? "w":"-");
						printf((fileStats.st_mode & S_IXOTH)? "x":"-");
						
						
						printf("Number of Inode: %llu\n",fileStats.st_ino);
					}
					
				}
			}
		}
	}
	else
	{
		printf("Couldn't open the directory %s",dir_path);
		return 1;
	}
	closedir(d);
	return 0;
}
