#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  double a,b,c,disc,x1,x2,p,q;
  printf("ax*x+bx+c=0, 请输入a,b,c的值,以空格分隔\n");
  scanf("%lf%lf%lf",&a,&b,&c);
  disc = b*b-4*a*c;
  if (disc<0){
    printf("无解");
    return EXIT_FAILURE;
  }
  p=-b/(2.0*a);
  q=sqrt(disc)/(2.0*a);
  x1=p+q;x2=p-q;
  printf("x1=%7.2f\nx2=%7.2f\n",x1,x2);
  return EXIT_SUCCESS;
}
