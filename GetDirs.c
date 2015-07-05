#include "GetDirs.h"
#include <stdio.h>

int GetFileCount(DIR *dp)
{
	int count=0;
	while(readdir(dp)!=NULL)
		count++;
	//reset dp index
	rewinddir(dp);
	return count;
}

int GetDirs(char *currDir, fileobj **Files)
{
	DIR *dirp;
	int count=0;
	struct dirent *dirEntry;
	fileobj *f;
	//Open handle to directory path
	if((dirp = opendir(currDir)) != NULL)
	{
		//file count
		count = GetFileCount(dirp);
		f = malloc(count*sizeof(fileobj));
		int iFile=0;
		while((dirEntry=readdir(dirp))!=NULL)
		{
			//if file object is a directory, then set Color Red - Else Green
			if(dirEntry->d_type == DT_DIR)
				strcpy(f[iFile].color, RED);
			else
				strcpy(f[iFile].color, GREEN);
			strcpy(f[iFile].name,dirEntry->d_name);
			iFile=iFile+1;
		}          
		*Files=f;
		return count;
	}
	else
	{
		return 0;
	}
}
