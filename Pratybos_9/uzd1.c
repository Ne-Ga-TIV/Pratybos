#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Point Point;

struct Point
{
    double x, y;
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
int main()
{
    Point p1 = {2.0, -3.0}, p2 = {-4.0, 5.0};
    printf("%.1f\n", getDistance(p1, p2));


    return 0;
}



