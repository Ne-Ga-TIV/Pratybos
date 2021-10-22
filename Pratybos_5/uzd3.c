#include <stdlib.h>
#include <stdio.h>
int main()
{
    int n, s, tmp;
    printf("Iveskite n ir s reiksmes : ");
    scanf("%d%d", &n, &s);
    int *arr = malloc(n*4);
    printf("Iveskite n elementu\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if(tmp <= 0)
        {
            printf("Skaicius turi buti teigiamas! Pandykite dar karta\n");
            i--;
            continue;
        }
        arr[i] = tmp;
    }
    printf("___________________\n");
    for(int i = 0; i < n; i++)
        if(i * arr[i] == s)
            printf("(%d;%d)\n", i, arr[i]);
    return 0;
}