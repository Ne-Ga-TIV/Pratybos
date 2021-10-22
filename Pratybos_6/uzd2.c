#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[30], value;
    int mantissa = 0, counter = 0;
start:    
    printf("Iveskite duomenu failo varda(max. 30 symb.) : ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Tokio failo nera. Pabandykite dar karta\n");
        goto start;
    }
    while ((value = fgetc(file)) != EOF)
    {
        if((value < 48 || value > 57) && value != ',' && value != ' ' && value != 10)
        {
            printf("Nekorektiski duomenis. Pabandykite dar karta\n");
            goto start;
        }
        if(value > 47 && value < 58)
            counter++;
        if(value == ',')
        {
            mantissa = 0;
            while((value = fgetc(file)) && value != ' ' && value != '\n')
            {
                mantissa++;
                if(mantissa > 3)
                {
                    printf("Nekorektiski duomenis. Pabandykite dar karta\n");
                    goto start;
                }
            }
            counter += mantissa;
        }
        if(value == ' ' && counter != 0)
        {
            printf("%d\n", counter);
            counter = 0;
        }

    }
    printf("%d\n", counter);
    return 0;
}