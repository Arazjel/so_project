#include "demon.h"

int kopia(char * readFile, char * writeFile, int bufforSize){
	int rozmiar = bufforSize;
	char * bufor;
	size_t wczytaneBajty;	
	bufor = malloc(sizeof(rozmiar));
	FILE * odczyt = fopen(readFile, "r");
	FILE * zapis = fopen(writeFile, "w");

	while(!feof(odczyt)){
		wczytaneBajty = fread(bufor, sizeof(char), rozmiar, odczyt);		
		fwrite(bufor, sizeof(char), wczytaneBajty, zapis);
	}
	free(bufor);
	fclose(odczyt);
	fclose(zapis);
	return 0;
}

int kop(char * readFile, char * writeFile){
	int rozmiar = 512;
	char * bufor;
	size_t wczytaneBajty;	
	bufor = malloc(sizeof(rozmiar));
	FILE * odczyt = fopen(readFile, "r");
	FILE * zapis = fopen(writeFile, "w");

	while(!feof(odczyt)){
		wczytaneBajty = fread(bufor, sizeof(char), rozmiar, odczyt);		
		fwrite(bufor, sizeof(char), wczytaneBajty, zapis);
	}
	free(bufor);
	fclose(odczyt);
	fclose(zapis);
	return 0;
}

void process(int argc, char* argv[]){
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
