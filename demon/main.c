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
/*                      WAZNE!!!

W WARUNKACH TRZEBA DODAC SPRAWDZANIE DATY MODYFIKACJI. JEZELI DEMON RUSZAL DANY PLIK WCZESNIEJ
I NIE JEST ZMODYFIKOWANY TO TRZEBA GO IGNOROWAC(!!)

*/

while ((first = readdir(argv[1])) != NULL)
{   
    char *nameFirst=first->d_name;
    struct stat attrFirst;
    stat(nameFirst,&attrFirst);
    time_t lastModificationDateFirst=ctime(&attrFirst.st_mtime);

    while ((second = readdir(argv[2])) != NULL)
    {
    char *nameSecond=second->d_name;
    struct stat attrSecond;
    stat(nameSecond,&attrSecond);
    time_t lastModificationDateSecond=ctime(&attrSecond.st_mtime);
        if ((nameFirst==nameSecond)&&((difftime(lastModificationDateFirst, lastModificationDateSecond))>0 ))
        {
                //nazwy sie NIE roznia i plik jest nowszy, trzeba kopiowac plik z pierwszego do drugiego
        }
    

    }
//w tym miejscu przeszukalo caly drugi katalog w poszukiwaniu pliku z pierwszego i nie znalazlo
//trzeba tutaj przekiopowac plik z pierwszego do drugiego

}



return 0;
}
