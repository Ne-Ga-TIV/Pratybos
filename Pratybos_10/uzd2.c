#include <stdio.h>
#include <stdlib.h>

int myStrCmp(const char *str2, const char *str1)
{
    while(*str2 == *str1){
        if(!(*str1))
            return 1;
        str2++, str1++;
    }
    while (1){
        if(!(*str2))
            return 0;
        if(!(*str1))
            return -1;
        str2++, str1++;
    }
}

int main()
{
    printf("%d\n", myStrCmp("sfв", "sfа"));
    return 0;
}