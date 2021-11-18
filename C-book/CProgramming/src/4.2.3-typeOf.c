#include <stdio.h>
#include <stdlib.h>

int main()
{ 
  int NumberFun(void);
  NumberFun();

  int charfun(void);
  charfun();
  
  return EXIT_SUCCESS;
}
int NumberFun(void){
  const double x = 1.0;
  const double y = 3.0;
  double a = x / y;
  float b = x / y;
  printf("double %.16f  字节%d , float %.16f  字节%d \n", a, sizeof a, b, sizeof b); //
  const int n = 256;
  short c = 256;
  long dd = 2566;
  printf("%d的16进制是%#x  字节%d\n", n, n, sizeof n);
  printf("%d的16进制是%#x  字节%d\n\n", c, c, sizeof c);
  return 0;
}

int charfun(void)
{
  char a = '1';
  char aa = a+a;
  short b = 1;
  short bb = b+b;
  printf("两个字符1, char aa = a+a;实际还是二进制相加,  相加 得到 %c, 16进制 %#x\n", aa,aa);
  printf("两个数字1, 相加 得到 %d, 16进制 %#x\n", bb,bb);

  unsigned char c = 128;
  printf("ASCⅡ扩展部分 %d: %c\n", c,c); // ASCⅡ扩展部分
  return 0;
}
