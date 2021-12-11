#include <stdlib.h>
#include <stdio.h>

void *myMemCpy (void *destination, const void *source, size_t n)
{
    int i, m;
    unsigned long  *wdst = destination; 
    unsigned long  *wsrc = source;  
    unsigned char  *cdst, *csrc;
 
    for(i = 0, m = n / sizeof(long); i < m; i++)  
    *(wdst++) = *(wsrc++);                   
 
    cdst = (unsigned char*)wdst;
    csrc = (unsigned char*)wsrc;

    for(i = 0, m = n % sizeof(long); i < m; i++)
    *(cdst++) = *(csrc++);
 
    return destination;
}

int main()
{
    int  b = '6';
    int *a = &b;
    void *prt = &(*a);
    
    printf("%d\n", sizeof(prt));
}