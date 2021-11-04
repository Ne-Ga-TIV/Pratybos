#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArray(size_t size, int low, int high)
{
    srand(time(NULL));

    int *arr = calloc(size, sizeof(int)), i = 0;
    
    if(arr == NULL)
        return NULL;

    for(; i < size; i++, arr++)
        *arr = low + rand() % (high - low + 1);
    
    return arr - i;
}
int main(int argc, char **argv)
{  
    return 0;    
}