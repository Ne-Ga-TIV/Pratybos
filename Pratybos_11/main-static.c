#include <stdio.h>

int loadCount = 0;
int saveCount = 0;
int main()
{
    int arr[6] = {1, 5, 5, 6, 6, 6};
    saveToFile(arr, 6, fopen("test.bin", "w+b"));
    return 0;
}