#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Stack Stack;
typedef struct Point Point;
struct Point
{
    double x, y;
};
struct Stack
{
    Point *data; 
    size_t size;
};

void printPoint(Point *p)
{
    printf("(%.1f;%.1f)", p->x, p->y);
}

Point createPoint(double x, double y)
{
    Point *newPoint = malloc(sizeof(Point));
    newPoint->x = x, newPoint->y = y;
    return *newPoint;
}

double getDistance(Point a, Point b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}



void destroyStack(Stack *stack);

void initStack(Stack *stack)
{
    stack->size = 0;
    stack->data = NULL;
}

Point top(Stack *stack)
{
    if(!stack->data){
        Point *tmp = malloc(sizeof(Point));
        tmp->x = 0.0, tmp->y = 0.0;
        return *tmp;
    }
    return stack->data[stack->size - 1];
}

int getStackSize(Stack *stack)
{
    return stack->size;
}

void push(Stack *stack, Point value)
{
    Point *tmp = calloc(stack->size + 1, sizeof(Point));
    
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
        printPoint(stack->data+i);
}

void destroyStack(Stack *stack)
{
    for(int i = 0; i < stack->size; i++)
        free(stack->data+i);
    stack->size = 0;
    stack->data = NULL;

}
Point pop(Stack *stack)
{
    if(!stack->size){
        Point *tmp = malloc(sizeof(Point));
        tmp->x = 0.0, tmp->y = 0.0;
        return *tmp;
    }

    Point last = top(stack);
    stack->size--;
    Point *tmp = calloc(stack->size, sizeof(int));

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
    printStack(&s);
    return 0;
}