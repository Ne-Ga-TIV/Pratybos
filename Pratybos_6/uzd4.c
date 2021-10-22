#include <stdio.h>
#include <stdlib.h>
int date(int y, int m, int d)
{
    int index_year, index_month;
    int indexes[] = { 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    index_year = (y % 100) / 12 + (y % 100) % 12 + ((y % 100) % 12) / 4;
    index_month = indexes[m-1];
    if(y / 100 < 20)
        index_year++;
    if(y % 4 == 0 && ((y % 100 == 0 && y % 400 == 0) || y % 100 != 0))
        index_year++;
    return (index_year + index_month + d) % 7;
}
void format_fail(int *day, int *month, int *year)
{
    printf("Klaida: netinkamas formatas\n");
    *day = *month = *year = 0;
}
int main()
{
    int day = 0, month = 0, year = 0;
    int month_day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char week[15] = "";
    printf("Iveskite data formatu YYYY MM DD: ");
    while (day == 0)
    {   
        char symbol1, symbol2, symbol3;
        int tmp = scanf("%d%c%d%c%d%c", &year, &symbol1, &month, &symbol2, &day, &symbol3); 
        if(symbol1 != ' ' || symbol2 != ' ' || symbol3 !='\n' || tmp != 6)
        {   
            if(symbol1 != '\n')
                scanf("%*[^\n]");
            format_fail(&day, &month, &year);
            continue;
        }   
        else
        {
            if(year < 1000 || month > 12 || month < 1 || day > month_day[month-1] || day < 1)
                format_fail(&day, &month, &year);
        }
    }
    day = date(year, month, day);
    FILE *file = fopen("week.txt", "r");
    if(file == NULL)
    {
        printf("Error: File not open\n");
        return -1;
    }
    
    for(int i = 0; i < day; i++)
        fscanf(file, "%s", week);
    
    printf("%s\n", week);
    
    return 0;
    
}