#include <stdio.h>

int main(int argc, char const *argv[])
{
  char *p;
  p=NULL;
  printf("null\n");
  printf("null %d\n", *p); // 禁止读取内存地址0的机器，会中指运行。
  return 0;
}
