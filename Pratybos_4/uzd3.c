#include <stdio.h>

int main()
{
	int a, b, c, f;
	printf("Iveskite 1 ir 2 sekos nari\n");
	scanf("%d%d", &a, &b);
	printf("Iveskite nario eiles numeri, kurio norite gauti\n");
	scanf("%d", &c);
	f = a+b;
	for(int i = 0; i <  c - 2; i++){
		a = b;
		b = f;
		f = a + f;
	}
	printf("%d-asis sekos naris lygus: %d\n", c, f);
	return 0;
}