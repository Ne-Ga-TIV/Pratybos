#ifndef INCLUDE 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define INCLUDE
#endif // INCLUDE
extern int saveCount, loadCount;

void saveToFile(int *arr, int size, FILE *file);
void loadFromFile(int *arr, int size, FILE *file);