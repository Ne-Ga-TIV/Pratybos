#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    // uzduotis 5a
    double x, y, z;
    scanf("%lf%lf%lf", &x, &y, &z);
    printf("%lf\n", x + y*4 + z*z*z);
    // uzduotis 5b
    scanf("%lf%lf%lf", &x, &y, &z);
    printf("%lf\n", (x + sqrt(y))*(pow(z, 4) - abs(z) +46.3));
    return 0;
}