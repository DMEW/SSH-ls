#include <stdio.h>
#include <stdlib.h>
#include "GetDirs.h"

void printDir(fileobj *f, int count);

int main()
{
	char currDir[256];
	fileobj *Files;
	int fileCount;
	//Get current working directory
	if(getcwd(currDir, sizeof(currDir)))
	{
		//get directory listing of CWD
		fileCount = GetDirs(currDir,&Files);
		if(fileCount!=0)
		{
			printDir(Files,fileCount);
		}
		else
		{
			printf("%s", "Error getting Directories/Files...Exiting");					exit(0);
		}
	}
	else
	{
		printf("%s", "Error getting CWD...Exiting");
		exit(0);
	}
}


void printDir(fileobj *f, int count)
{
	char output[300];
	int iFile=0;
	while(iFile<count)
	{
		strcpy(output,f[iFile].color);
		strcat(output,f[iFile].name);
		strcat(output,RESET);
			
		printf("%s   ",output);
		iFile++;
	}
	printf("\n");
}
