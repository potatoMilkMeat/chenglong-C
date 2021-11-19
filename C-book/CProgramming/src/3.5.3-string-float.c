#include <stdio.h>
#include <stdlib.h>

int main()
{
  const char *str = "I am Chenglong.";
  printf("%s sizeof %d\n", str, sizeof str);
  int floatNumber();
  floatNumber();
  return EXIT_SUCCESS;
}

int floatNumber()
{
  double a= 1.0/3.0;
  printf("%f\n%d\n%20.15f\n%-20.15f\n",a,a,a,a);
  return 0;
}
