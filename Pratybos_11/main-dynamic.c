#include <stdio.h>

int loadCount = 0;
int saveCount = 0;
int main()
{
    int arr[5];
    loadFromFile(arr, 5, fopen("test.bin", "r+b"));
    for(int i = 0; i < 5; i++)
        printf("%d\n", arr[i]);
}