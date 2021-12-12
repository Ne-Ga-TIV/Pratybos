#include "file.h"
#ifndef INCLUDE 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define INCLUDE
#endif // INCLUDE

void saveToFile(int *arr, int size, FILE *file)
{
    fwrite(&size, sizeof(int), 1, file);
    fwrite(arr, sizeof(int), size, file);
    saveCount++;
}

void loadFromFile(int *arr, int size, FILE *file)
{
    int size_in;
    fread(&size_in, sizeof(int), 1, file);
    fread(arr, sizeof(int), size, file);
    loadCount++;
}