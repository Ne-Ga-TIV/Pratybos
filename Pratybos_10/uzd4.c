#include <stdio.h>
#include <stdlib.h>

char *myStrChr(const char *str, int chr)
{
    for(;str;str++)
        if(*str == chr)
            return str;

    return NULL;        
}
