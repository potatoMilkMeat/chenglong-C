#include <stdio.h>

int main()
{
  char *p,*q;
  q = p = "xyz";
  printf("都指向字符串首元素的地址 %s %s", q, p);
  /* 下面这句不会执行 */
  p[1] = 'Y';
  printf("出来了就是能执行  p[1] = 'Y'; %s", p);
  return 0;
}
