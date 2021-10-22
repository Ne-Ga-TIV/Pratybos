#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{   
    srand(time(NULL));
    int a, b, c, arr[1000];
    printf("Iveskite generojamu skaiciu intervala ir ju kieki : ");
    scanf("%d%d%d", &a, &b, &c);
    for(int i = 0; i < c; i++){
        arr[i] = a + rand() % (b - a);
        printf("%d%c", arr[i], i == c - 1 ? '\n' : ' ');
    }
    
    return 0;
}