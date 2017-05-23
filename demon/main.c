#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include "sleepMode.h"
#include "fileinfo.h"

void isDirectory(char* argv[])
{
struct stat sb = {0};

    if (!(stat(argv[1], &sb) == 0 && (S_ISDIR(sb.st_mode))))
    {
        fprintf(stderr, "Pierwszy z podanych katalogow nie istnieje.\n");
	exit(EXIT_FAILURE);
    }

    if (!(stat(argv[2], &sb) == 0 && (S_ISDIR(sb.st_mode))))
    {
        fprintf(stderr, "Drugi z podanych katalogow nie istnieje.\n");
	exit(EXIT_FAILURE);
    }

}
int isRegularFile(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int main(int argc,char** argv)
{

isDirectory(argv); //jesli podane foldery nie istnieja program wychodzi z komunikatem bledu
int secs;
if (argc==3) waitFor(secs=(uintptr_t) argv[2]);
	else waitFor(STANDARD_TIME); //odczekanie podanej wartosci lub 5 minut

struct dirent *first;
struct dirent *second;

while ((first = readdir(argv[1])) != NULL)
{
    while ((second = readdir(argv[2])) != NULL)
    {
        
    }
}



return 0;
}
