#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int kopia(char * readFile, char * writeFile, int bufforSize);

int kop(char * readFile, char * writeFile);

void process(int argc, char* argv[]);   
