#include <stdio.h>
#include <math.h>

int main()
{ 
  int i = 2;
  char c = '0';
  char cc = '1';
  
  printf("cc：  %u  %d  %c\n", &cc, sizeof cc, cc);
  printf("c ：  %u  %d  %c  %d\n", &c, sizeof c, c, c);
  printf("i ：  %u  %d  %d\n", &i, sizeof i, i);
  printf("内存覆盖展示，请输入一个数字并回车，会把数值赋值给c, 把i值 的低位 覆盖 \n");
  scanf("%d", &c);
  printf("c ：  %u  %d  %c  %d\n", &c, sizeof c, c, c);
  printf("i ：  %u  %d  %d\n", &i, sizeof i, i);
  return 0;
}
