#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char* argv[]){
    	DIR * dir;
    	struct dirent * dp;
    	char * fileName;
    	dir = opendir(argv[1]);
	struct stat sb = {0};

    	while ((dp=readdir(dir)) != NULL) {
        	if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") )
        	{
           	 // do nothing (straight logic)
        	} else {
		fileName = dp->d_name;
        	printf("%s\t",fileName);

		if (stat(fileName, &sb) == 0 && S_ISDIR(sb.st_mode)){
        		printf("Folder");
    		}else {
        		printf("NOT Folder");
			/*
				tu dać funkcjonalnosc jezeli
				obiekt jest plikiem
			*/
		}
		printf("\n");
        }
    }
    closedir(dir);
    return 0;

}
