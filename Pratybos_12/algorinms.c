#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubleSort(int *arr, int size)
{
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - i - 1; j++)
            if(arr[j+1] < arr[j])
                swap(arr+j+1, arr+j);
}

void printArray(int *arr, int size)
{
    while(size--)
        printf("%d%c", *(arr++), size == 0 ? '\n' : ' ');
}

void fillArray(int *arr, int size)
{
    
    while(size--)
        *(arr++) = rand() % 1000;
}

int sortCheak(int *arr, int size)
{
    for(int i = 0; i < size - 1; i++)
        if(arr[i] > arr[i+1])
            return 0;
    
    return 1;
}


void insertSort(int *arr, int size)
{
    for(int i = 1; i < size; i++)
        for(int j = i; j > 0 && arr[j-1] > arr[j]; j--)
            swap(arr+j-1, arr+j);
}


void selectSort(int *arr, int size)
{
    for(int i = 0; i < size; i++){
        int minJ = i;
        for(int j = i+1; j < size; j++)
            if(arr[minJ] > arr[j]) minJ = j;
        
        swap(arr+minJ, arr+i);
    }

}

void quickSort(int *first, int *last)
{
    int *f = first, *l = last;
    int pivot = *(first + (last-first)/2);
    do{
        
        while(*f < pivot)
            f++;
        
        while(*l > pivot)
            l--;

        if(f <= l){
            swap(f, l);
            f++; 
            l--;
        }
    }while(f <= l);

    if(f < last)
        quickSort(f, last);
    if(l > first)
        quickSort(first, l);
    
}

void mergeSort(int *low, int *high)
{
    if(high <= low)
        return;

    int pivot =  (high - low) / 2;
   
    mergeSort(low, low + pivot);
    mergeSort(low + pivot + 1, high);
    
    int *buff = calloc(high - low + 1, sizeof(int));

    for(int *l = low; l <= high; l++, buff++)
         *buff = *l;
    buff -= high - low + 1;
   
    int buffJ =  pivot + 1;
    int buffI = 0;
    for(int i = 0; i <= high - low; i++){
       
        if(buffI > pivot){
            low[i] = buff[buffJ];
            buffJ++;
        }
        else if(buffJ > high - low){
                low[i] = buff[buffI];
                buffI++;
        }
        else if (buff[buffJ] < buff[buffI]) {
            low[i] = buff[buffJ];
            buffJ++;
        }else {
            low[i] = buff[buffI];
            buffI++;
        }
            
    }

}

int main()
{
    srand(time(NULL));

    time_t start, end;
    int arr[1000], arr_2[10000], arr_3[100000];

    const char *funNames[] = {"BubleSort:", "SelectSotr:",
                            "InsertSotr", "QuickSort", "MargeSotr"};
    int *arrPtr[] = {arr, arr_2, arr_3};
    
    void (*fun[])(int*, int) = {bubleSort, selectSort, insertSort};
    void (*fun2[])(int*, int*) = {quickSort, mergeSort};

    printf("Sotr:          n = 1000      n = 100000     n = 100000\n");
    // Default Sort
    for(int i = 0; i < 3; i++){
        printf("%-15s", funNames[i]);
        for(int j = 0; j < 3; j++){
            int size = 10*pow(10, j+2);
            fillArray(arrPtr[j], size);
            time(&start);
            fun[i](arrPtr[j], size);
            time(&end);
            printf("%-14f", difftime(end, start));
        }
        printf("\n");
    }
    // Quick Sort
    for(int i = 3; i < 5; i++){
        printf("%-15s", funNames[i]);
        for(int j = 0; j < 3; j++){
            int size = 10*pow(10, j+2);
            fillArray(arrPtr[j], size);
            time(&start);
            fun2[i-3](arrPtr[j], arrPtr[j]+size-1);
            time(&end);
            printf("%-14f", difftime(end, start));
        }
        printf("\n");
    }
    return 0;
}