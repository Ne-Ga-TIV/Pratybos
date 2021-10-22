#include <stdio.h>
#include <stdlib.h>
int prime_numb(int value)
{
    for(int i = 2; i <= value / 2; i++)
        if(value % i == 0)
            return 0;
    if(value > 2)
        return 1;
    return 0;
}
int uni_numb(int value, int *arr, int size)
{
    for(int i = 0; i < size; i++)
        if(arr[i] == value)
            return 0;

    return value;
}
int main()
{
    int tmp, arr[1000], i = 0;
    printf("Iveskite skaicius\n");
    while (scanf("%d", &tmp), tmp > 0)
        arr[i++] = uni_numb(tmp, arr, i);
    printf("Pirmini skaiciai\n");
    for(int j = 0; j < i; j++)
        if(prime_numb(arr[j]))
            printf("%d\n", arr[j]);
    return 0;
}