#include <stdio.h>

int main()
{
	int value, max = -1;
	printf("Iveskite skaiciu seka\n");
	while(scanf("%d", &value), value > 0)
	{
		max = max < value ? value : max;
	}
	printf("Daugiausiai skaitmenu turi skaicius %d\n", max);
	return 0;
}