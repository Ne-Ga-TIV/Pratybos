#include <stdlib.h>
#include <stdio.h>

int getFactorial(int number)
{
    if(number < 0)
        return 0;
    if(number < 2)
        return number;

    return number * getFactorial(number-1);
}

int main()
{
    return 0;
}