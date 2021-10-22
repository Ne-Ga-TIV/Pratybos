#include <stdio.h>
#include <math.h>
int main()
{
  int a, b, c, d;
  printf("Prasau iveskite 3 sveikus skaicius: ");
  scanf("%d%d%d", &a, &b, &c);
  d = b*b-4*a*c;
  if(d >= 0)
      printf("Lygties %dx^2+%dx+%d yra \nx1 = %.3f, x2 = %.3f\n", a, b, c, (-b + sqrt(d))/(2*a), (-b - sqrt(d))/(2*a));
  else
      printf("Lygtis %dx^2+%dx+%d neturi sprendiniu\n", a, b, c);
  return 0;
}