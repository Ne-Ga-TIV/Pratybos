#include <stdio.h>
#include <stdlib.h>

int isInRange(int number, int low, int high)
{
    return number >= low && number <= high && low < high;
}
int main()
{
    return 0;
}