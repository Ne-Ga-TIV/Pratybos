#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("out.txt", "w");
    int value;
    printf("Iveskite skaiciu :");
    scanf("%d", &value);
    fprintf(file, "%d\n", value);
    fclose(file);
    return 0;
}