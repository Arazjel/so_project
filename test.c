#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>

int main(int argc, char* argv[]){
    	DIR * dir1;
    	DIR * dir2;
    	dir1 = opendir(argv[1]);
    	//dir2 = opendir(argv[2]);
    	struct dirent * direntFirst;
    	struct dirent * direntSecond;
    	char * firstFile;
    	char * secondFile;


    	struct stat fileStat1;


    	struct stat sb = {0};

    	while ((direntFirst=readdir(dir1)) != NULL) {
        	if ( !strcmp(direntFirst->d_name, ".") || !strcmp(direntFirst->d_name, "..") )
        	{
           	 // do nothing (straight logic)
        	} else {
        		firstFile = direntFirst->d_name;
        	printf("%s\t",firstFile);

		if(stat(firstFile, &sb) == 0 && S_ISDIR(sb.st_mode)){
        		printf("Folder\n\n");
    	}else {
        		printf("NOT Folder\n");
        		if (!stat(firstFile, &fileStat1)){
        			/*
        							tu dać funkcjonalnosc jezeli
        							obiekt jest plikiem
        			*/
        		    printf("---------------------------\n");
        		    printf("Modyfication: \t\t%ld\n",fileStat1.st_mtime);
        		    printf("\n\n");
        		}

		}
		printf("\n");
        }
    }
    closedir(dir1);
    return 0;
}
