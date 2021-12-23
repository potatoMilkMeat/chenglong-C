#include <stdio.h>
int main(int argc, char const *argv[])
{
  int count;
  printf("命令行模式有%d个参数。\n", argc-1);
  for (count = 1; count < argc; count++)
  {
    printf("%d: %s\n", count, argv[count]);
  }
  
  return 0;
}
