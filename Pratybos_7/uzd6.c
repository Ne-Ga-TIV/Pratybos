#include <stdio.h>
#include <stdlib.h>


int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
{

    int select = 0;
    do
    {
        printf("%s\n", menuTitle);

        for (size_t i = 1; i <= menuSize; i++)
            printf("%-15s [%lu]\n", menuOptions[i-1], i);
        
        printf("%s: ", inputMsg);

        if(scanf("%d", &select) != 1 || select  < 0 || select > menuSize){
            scanf("%*[^\n]");
            system("clear");
        }

    } while (select  < 0 || select > menuSize);
    
   
}
int main()
{
    char *menu[] = {"New game", 
                    "Loading", 
                    "Options", 
                    "Exit",};
    showMenu("Main menu", menu, 4, "Enter your select, please");
    return 0;
}