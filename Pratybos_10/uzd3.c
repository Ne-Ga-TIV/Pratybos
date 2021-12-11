#include <stdlib.h>
#include <stdio.h>
char * myStrCpy(char *str2, const char *str1, size_t n)
{
    for(int i = 0; i < n && *str1;str1++, str2++)
        *str2 = *str1;

    *str2 = '\0';

    return str2;
}
