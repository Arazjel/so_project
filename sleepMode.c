/*wywolywac to trzeba w takiej petli:
    if (argc=3) waitFor(secs=(uintptr_t) argv[2]);
	else waitFor(STANDARD_TIME);
STANDARD_TIME jest ustawiony definem na 300sekund == 5 minut
*/

#include <stdio.h>
#include "sleepMode.h"

void waitFor (unsigned int secs) {
unsigned int  retTime = time(0) + secs;
    while (time(0) < retTime);
}

