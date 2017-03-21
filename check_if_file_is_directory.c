#include <stdio.h>
#include <sys/stat.h>

void main (int argc, char* argv[])
{
struct stat sb = {0};

    if (stat(argv[1], &sb) == 0 && S_ISDIR(sb.st_mode))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }


};
