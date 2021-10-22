#include <stdlib.h>
#include <stdio.h>

int main()
{
    int value, sum = 0;
    char symbol;
    printf("Enter 3 numbers separated by semicolons\n");
start:
    for(int i = 0; i < 3; i++)
    {   
        if(scanf("%d%c", &value, &symbol) != 2 || symbol != ';')
        {
            if(symbol != '\n')
                scanf("%*[^\n]");
            printf("Wrong input! Try again\n");
            sum = 0;
            goto start;
        }
        else{
            printf("%c", symbol);
            sum+=value;
        }
    }
    printf("Enter file name(max size 30 symbol): ");
    char filename[30];
outfile:
    scanf("%s", filename);
    FILE *file = fopen(filename, "w");
    if(file == NULL)
    {
        printf("File not open! Try again, please\n");
        goto outfile;
    }

    int i = 0;
    
    for(; filename[i] != '.'; i++)
        ;
    if(filename[i+1] != 't' || filename[i+2] != 'x' || filename[i+3] != 't')
    {
        printf("The file must have the txt extension. Try again, please");
        goto outfile;
    }
    fprintf(file, "%d", sum/3);
    return 0;
}