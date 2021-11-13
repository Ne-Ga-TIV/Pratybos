#include <stdio.h>
#include <stdlib.h>
typedef struct List List;

struct List
{
    int data;
    List *next;
};

List *createList(int value)
{
    List *tmp = malloc(sizeof(List));
    tmp->data = value;
    tmp->next = NULL;
    return tmp;
}

void printList(List *list)
{
    if(!list)
        return;

    printf("%d%c", list->data, list->next ? ' ' : '\n');

    printList(list->next);
}

int getListSize(List *list)
{
    if(!list)
        return 0;

    return getListSize(list->next) + 1;
}

void insertElement(List **list, int value)
{
    List *tmp = malloc(sizeof(List));
    tmp->data = value;
    tmp->next = *list;
    *list = tmp; 
}

int getElement(List *list)
{
    return list->data;
}
int deleteElement(List **list)
{
    if(!list)
        return 0;
    
    List *tmp = (*list)->next;
    int data = (*list)->data;

    free(*list);
    *list = tmp;

    return data;
}
void destroyList(List **list)
{
    if(!list)
        return;

    for(List *i = (*list)->next; i; *list = i, i = (*list)->next)
        free(*list);
    
    free(*list);
    *list = NULL;
}
int main()
{
    List *list = createList(1);
    insertElement(&list, 5);
    destroyList(&list);
    printList(list);

    return 0;
}