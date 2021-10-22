#include <stdio.h>
#include <stdlib.h>

int find_dog(char *str)
{
    int coutn = 0, i = 0, index;
    for(; str[i];i++)
    {
        if(str[i] == '@')
        {
            index = i;
            coutn++;
        }
    }
    if(coutn == 1)
        return index;
    else
        return 0;
}
int find_dote(char *str, int index)
{
    for(; str[index]; index++)
        if(str[index] == '.')
            return index;
    return 0;
}
int email_is_correct(char *str, int dog, int dote)
{
    int true = 0;

    for(int i = 0; i < dog; i++)
        if((str[i] > 47 && str[i] < 58) || (str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)){
            true++;
            
            break;
        }
    for(int i = dog+1; i < dote; i++)
        if((str[i] > 47 && str[i] < 58) || (str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)){
            true++;
            break;
        }
    for(int i = dote+1; str[i]; i++)
        if((str[i] > 47 && str[i] < 58) || (str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)){
            true++;
            break;
        }
    
    if(true == 3)
        return 1;
    return 0;
}
int main()
{
    char email[100] = "";
    int dog, dote;
    printf("Please, enter email adress:\n");
    while (scanf("%99s", email))
    {
        if(!(dog = find_dog(email)) || !(dote= find_dote(email, dog)))
            printf("Entered email is incorrect! try again\n");
        else if(email_is_correct(email, dog, dote))
                break;
        else
            printf("Entered email is incorrect! try again\n");
        
    }
    printf("Domen: %s\n", email+dog+1);
    FILE *file = fopen("emails.txt", "a+");
    fprintf(file, "%s\n", email);
    
    return 0;
}