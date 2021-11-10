#include <stdlib.h>
#include <stdio.h>
typedef struct Stack Stack;

struct Stack
{
    int *data; 
    size_t size;
};
void destroyStack(Stack *stack);
void initStack(Stack *stack)
{
    stack->size = 0;
    stack->data = NULL;
}
int top(Stack *stack)
{
    if(!stack->data)
        return 0;
    return stack->data[stack->size - 1];
}
int getStackSize(Stack *stack)
{
    return stack->size;
}
void push(Stack *stack, int value)
{
    int *tmp = calloc(stack->size + 1, sizeof(int));
    
    for(int i = 0; i < stack->size; i++)
        tmp[i] = stack->data[i];
    
    tmp[stack->size] = value;
    
    for(int i = 0; i < stack->size; i++)
        free(&stack->data[i]);
    stack->data = tmp;
    stack->size++;
}

void printStack(Stack *stack)
{
    for(int i = 0; i < stack->size; i++)
        printf("%d%c", stack->data[i], i == stack->size - 1 ? '\n' : ' ');
}

void destroyStack(Stack *stack)
{
    for(int i = 0; i < stack->size; i++)
        free(stack->data+i);
    stack->size = 0;
    stack->data = NULL;

}
int pop(Stack *stack)
{
    if(!stack->size)
        return 0;

    int last = top(stack);
    stack->size--;
    int *tmp = calloc(stack->size, sizeof(int));

    for(int i = 0; i < stack->size; i++)
        tmp[i] = stack->data[i];

    for(int i = 0; i < stack->size; i++)
        free(stack->data+i);
    
    stack->data = tmp;

    return last;
}
int main()
{
    Stack s;
    initStack(&s);
    push(&s, 1);
    push(&s, 2);
    pop(&s);
    printStack(&s);
    return 0;
}