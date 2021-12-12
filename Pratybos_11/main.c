#ifndef INCLUDE 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <libfile.lib>
#define INCLUDE
#endif // INCLUDE

int loadCount = 0, saveCount = 0;

void printArray(int *arr, int size)
{
    while(size--)
        printf("%d%c", *(arr++), size == 0 ? '\n' : ' ');
}

void fillArray(int *arr, int size)
{
    
    while(size--)
        *(arr++) = rand() % 1000;
}

void cmpArray(int *arr_1, int *arr_2, int size)
{
    while(size--)
        if(*(arr_1++) != *(arr_2++)){
            printf("something’s wrong\n");
            return;
        }
    printf("all good\n");
}

void cmpCounts()
{
    if(saveCount == loadCount == 3)
        printf("all good\n");
    else
        printf("something’s wrong\n");
}
int main()
{   
    srand(time(NULL));
    return 0;
}