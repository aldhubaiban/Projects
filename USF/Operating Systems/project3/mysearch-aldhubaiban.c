#include <stdio.h>
#include <dirent.h>
#include <string.h>
void list_file(char* dir_path)
{
	DIR *d;
	struct dirent *dir;
	d = opendir(dir_path);//opening directory
	if(d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if(dir->d_type==DT_DIR)//hit directory
			{
				if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)//ignore . and .. directories
				{
					continue;
				}
				
				//processing 
				
				char rdirectory[1024];//for storing directory path
				snprintf(rdirectory, sizeof(rdirectory), "%s/%s", dir_path, dir->d_name); // creating path name for directory to search next
				printf("[%s]\n", dir->d_name);// printing 
				list_file(rdirectory);
				
			}
			printf("[-] %s\n", dir->d_name);//[-] for files
		}
	}
}
int main(int argc, char *argv[])
{
	char *current_path=".";
	if(argc ==2)
	{
		current_path=argv[1];
	}
	list_file(current_path);
	return 0;
}
