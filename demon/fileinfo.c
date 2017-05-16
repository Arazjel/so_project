#include "fileinfo.h"

void fileInfo (int argc_, char **argv_)
{
    DIR *midir;
    struct dirent* info_archivo;
    struct stat fileStat;
    char fullpath[256];

    FILE *f; f = fopen("demon.log", "a+");
    if (f == NULL) printf("Wystapil blad przy tworzeniu loga"); 

    if (argc_ != 2)
    {
        perror("Please supply a folder name\n");
        exit(-1);
    }

    if ((midir=opendir(argv_[1])) == NULL)
    {
        perror("Error in opendir");
        exit(-1);
    }
	

	time_t currentTime;
	currentTime= time(NULL);


    while ((info_archivo = readdir(midir)) != 0)
    {
        fprintf (f,"FILENAME: %s \n", info_archivo->d_name);
        strcpy (fullpath, argv_[1]);
        strcat (fullpath, "/");
        strcat (fullpath, info_archivo->d_name);
        if (!stat(fullpath, &fileStat))
        {
               fprintf(f,"Information for folder %s	",argv_[1]);fprintf(f,ctime(&currentTime),"\n");
    fprintf(f,"---------------------------\n");
    fprintf(f,"File Size: \t\t%d bytes\n",fileStat.st_size);
    fprintf(f,"Number of Links: \t%d\n",fileStat.st_nlink);
    fprintf(f,"File inode: \t\t%d\n",fileStat.st_ino);
 
    fprintf(f,"File Permissions: \t");
    fprintf(f, (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    fprintf(f, (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    fprintf(f, (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    fprintf(f, (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    fprintf(f, (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    fprintf(f, (fileStat.st_mode & S_IROTH) ? "r" : "-");
    fprintf(f, (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    fprintf(f, (fileStat.st_mode & S_IXOTH) ? "x" : "-");
        fprintf(f,"\n\n");
        } else
        {
            perror("Error in stat");
        }
        fprintf(f,"\n");
    }

	
    closedir(midir);
    fclose(f);
}
