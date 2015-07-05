#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define MAGENTA "\x1b[35m"
#define RESET   "\x1b[0m"

typedef struct{
	char name[256];
	char color[32];
}fileobj;

int GetDirs(char *currDir,fileobj **Files);
int GetFileCount(DIR *dp);
