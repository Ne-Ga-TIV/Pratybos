#include <stdlib.h>
#include <stdio.h>

void swap(int *value1, int *value2)
{
    int tmp = *value1;
    *value1 = *value2;
    *value2 = tmp;
}

int main()
{
    return 0;
}