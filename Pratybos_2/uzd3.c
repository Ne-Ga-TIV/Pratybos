#include <stdio.h>

int main()
{
   int value;
   scanf("%d", &value);
   printf("Skaicius %d yra %s\n", value, value % 2 == 0 ? "lyginis" : "nelyginis");
   return 0;
}
