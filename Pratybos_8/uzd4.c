#include <stdlib.h>
#include <stdio.h>

int splitData(int *mainArray, int mainSize, int firstArrSize, int **firstArr, int **secondArr)
{
    if(mainSize <= firstArrSize || mainArray== NULL)
        return -1;
    
    *firstArr = calloc(firstArrSize, sizeof(int));
    *secondArr = calloc(mainSize - firstArrSize, sizeof(int));


    for(int i = 0; i < mainSize; i++){
        if(i < firstArrSize){
            (*firstArr)[i] = mainArray[i];
        }
        else
            (*secondArr)[i - firstArrSize] = mainArray[i];
    }

    return 0;

}

int main()
{
    return 0;
}