#include <stdio.h>

int main()
{
	int a, b, c, i, found = 0;
	printf("Iveskite intervala (nuo; iki]:\n");
	scanf("%d%d", &a, &b);
	printf("Iveskite dalykli:\n");
	scanf("%d", &c);
	printf("Skaiciai kurie intervalose (%d;%d] dalynasi is %d su liekana 1:\n", a, b, c);
	for(i = a + 1; i <= b; i++){
		if(i % c == 1){
			printf("%d ", i);
			found = 1;
		}
		if(i == b)
			printf("\n");
	}
	if(!found)
		printf("Tokiu skaiciu nera :(\n");
	return 0;
}