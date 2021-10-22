#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generateArray(int data[], int size, int low, int high)
{
    srand(time(NULL));
    for(int i = 0; i < size; i++)
        data[i] = rand() % (high - low + 1) + low;
}
int main()
{
    return 0;
}