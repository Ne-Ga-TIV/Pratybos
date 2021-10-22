#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int sort(int numb)
{  
    int size = 0, copy = numb, j, i, max = 0, new_numb = 0;
    while (copy)
    {
        size++,copy /=10;
    }
    copy = numb;
    for(int k = size - 1; k >= 0; k--)
    {
        copy = numb;
        i = 0, max = 0;
        while (copy)
        {
            if(copy % 10 > max)
            {
                max = copy % 10;
                j = i;
            }
            i++;
            copy /=10;
        }
        numb -= max * pow(10, j);
        new_numb += max * pow(10, k);

    }
    return new_numb;
}

int main()
{   
    printf("%d\n", sort(18103));
    return 0;
}