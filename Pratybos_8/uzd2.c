#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * maxFileName(int nameCount, char **fileName)
{
    int id, max = 0;
    for (int i = 1; i < nameCount; i++){
        
        int tmp = strlen(fileName[i]);
        
        if(max < tmp){
            id = i;
            max = tmp;
        }
    }
    return fileName[id];
    
}


int main(int argc, char **argv)
{
    
    return 0;
}