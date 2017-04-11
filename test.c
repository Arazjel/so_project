#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>

int main(int argc, char* argv[]){
    	DIR * dir;
    	struct dirent * dp;
    	char * fileName;
    	dir = opendir(argv[1]);

    	struct stat fileStat;
    	char fullpath[256];


    	struct stat sb = {0};

    	while ((dp=readdir(dir)) != NULL) {
        	if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") )
        	{
           	 // do nothing (straight logic)
        	} else {
        		fileName = dp->d_name;
        	printf("%s\t",fileName);

		if(stat(fileName, &sb) == 0 && S_ISDIR(sb.st_mode)){
        		printf("Folder\n\n");
    	}else {
        		printf("NOT Folder\n");
        		if (!stat(fileName, &fileStat)){
        			/*
        							tu dać funkcjonalnosc jezeli
        							obiekt jest plikiem
        			*/
        		    printf("---------------------------\n");
        		    printf("Modyfication: \t\t%ld\n",fileStat.st_mtime);
        		    printf("\n\n");
        		}

		}
		printf("\n");
        }
    }
    closedir(dir);
    return 0;
}
