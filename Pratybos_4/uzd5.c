#include <stdio.h>

int main()
{
	int n;
	double tmp, max, min, sum = 0;
	printf("Iveskite sekos nariu skaciu: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lf", &tmp);
		if(i == 0) 
			max = min = tmp;
		sum += tmp;
		max = max < tmp ? tmp : max;
		min = min > tmp ? tmp : min;

	}
	printf("MAX. = %.3f\nMIN. = %.3f\nVID. = %.3f\n", max, min, sum/n);	
	return 0;
}