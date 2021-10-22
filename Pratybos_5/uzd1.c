#include <stdio.h>

void print_arr(int *arr)
{
    for (size_t i = 0; i < 10; i++)
        printf("%d%c", arr[i], i == 9 ? '\n': ' ');    
}
void pop_element(int *arr, int index)
{
    for(int i = index; i < 9; i++)
        arr[i] = arr[i+1];
    arr[9] = 0;
}
void push_element(int *arr, int index, int value)
{
    for(int i = 9; i > index; i--)
        arr[i] = arr[i-1];
    arr[index] = value;
}
void new_value(int *arr, int index, int value)
{
    arr[index] = value;
}
int main()
{
    int arr[10] = {0}, index, value;
    print_arr(arr);
    arr[0] = 1, arr[3] = 2, arr[9] = 3;
    pop_element(arr, 2);
    push_element(arr, 6, 4);
    print_arr(arr);
    printf("Iveskite elemento numeri [1;10] ir nauja reiksme : ");
    scanf("%d%d", &index, &value);
    new_value(arr, index-1, value);
    printf("Iveskite istrinamuojo elemento numeri [1;10] : ");
    scanf("%d", &index);
    pop_element(arr, index-1);
    printf("Iveskite naujo elemento numeri [1;10] ir reiksme : ");
    scanf("%d%d", &index, &value);
    push_element(arr, index-1, value);
    print_arr(arr);

    return 0;
}