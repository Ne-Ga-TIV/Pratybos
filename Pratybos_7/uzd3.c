#include <stdlib.h>
#include <stdio.h>
//Nelabai man paviko suprasti uzduoti(
int getPositiveNumber(char *msg)
{
    int number;
    char tmp[256] = { 0 };
    do
    {
        printf("%s\n", msg);
        scanf("%255s", tmp);
    } while (sscanf(tmp, "%d",&number) != 1);
    
    return number;

}
int main()
{
    char msg[] = "Please, enter number";
    getPositiveNumber(msg);
    return 0;
}