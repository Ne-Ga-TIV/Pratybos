#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define OPERAND2 (arr[1] > arr[2] ? arr[1] : arr[2])

int* divilers(int a)
{
	int div = 2, coutn = 1,
	*arr_div = malloc(a*4);
	arr_div[0] = a;
	while(a != 1)
	{
		if(div == a){
			arr_div[coutn] = a;
			return arr_div;
		}
		if(a % div == 0)
		{
			arr_div[coutn++] = div;
			a /= div;
		}
		else div++;
	}
	*arr_div = 1;
	return arr_div;
}

int MBK(int *arr)
{
	int *arr_div[3], mbk = 1, *div_coutn, max;
	int const size = arr[0] > OPERAND2 ? arr[0]: OPERAND2;
	div_coutn = malloc(size*4);
	for(int i = 0; i < size;div_coutn[i] = 0, i++); 
	for(int i = 0; i < 3; i++){
		arr_div[i] = divilers(arr[i]);
		for(int k = 0; k < arr_div[i][0]; k++){
			max = 0;
			for(int j = 1; j < arr_div[i][0]; j++)
				if(arr_div[i][j] == k+2)
					max++;
			div_coutn[k] = div_coutn[k] < max ? max : div_coutn[k]; 
		}
	}
	for(int i = 0; i < size; i++) mbk *= pow(i+2, div_coutn[i]);
	return mbk;
}
int DBD(int *arr)
{
	for(int i = arr[0] ;;i--)
		if(!(arr[0] % i) && !(arr[1] % i) && !(arr[2] % i))
			return i;

}
int main()
{
	int arr[3], arr_copy[3];
	printf("Iveskite 3 naturalus skaicius\n");
	scanf("%d%d%d", arr, arr+1, arr+2);
	arr_copy[0] = arr[0], arr_copy[1] = arr[1], arr_copy[2] = arr[2];
	printf("Skaiciu %d %d %d DBD lygus: %d\n",arr[0], arr[1], arr[2], DBD(arr_copy));
	printf("Skaiciu %d %d %d MBK lygus: %d\n",arr[0], arr[1], arr[2], MBK(arr));
	return 0;
}