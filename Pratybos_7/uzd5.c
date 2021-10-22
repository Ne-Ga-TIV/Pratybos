#include <stdlib.h>
#include <stdio.h>

long getFileSize(char *fileName)
{
    FILE *file = fopen(fileName, "rb");

    if(file == NULL)
        return -1;

    fseek(file, 0L, SEEK_END);
    return ftell(file);
}
int main()
{
    return 0;
}