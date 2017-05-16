/*wywolywac to trzeba w takiej petli:
    if (argc=3) waitFor(secs=(uintptr_t) argv[2]);
	else waitFor(STANDARD_TIME);
STANDARD_TIME jest ustawiony definem na 300sekund == 5 minut
*/

#include <stdio.h>
#include "sleepMode.h"

void waitFor (unsigned int secs) {
FILE *f;
f = fopen("demon.log", "a+"); 
if (f == NULL) printf("Wystapil blad przy tworzeniu loga");
time_t currentTime;
currentTime= time(NULL);
int signal;

unsigned int  retTime = time(0) + secs;

printf(f,ctime(&currentTime)," ","Wejscie w tryb uspienia\n");

    while (time(0) < retTime)
	{
		if (signal==SIGUSR1) break;
	}


currentTime=time(NULL);
if (signal==SIGUSR1)
{
printf(f,ctime(&currentTime)," ","Powod zakonczenia uspienia: otrzymanie SIGUSR1\n");
}
else
{
fprintf(f,ctime(&currentTime)," ","Powod zakonczenia uspienia: uplyw czasu\n");
}
fclose(f);

}
