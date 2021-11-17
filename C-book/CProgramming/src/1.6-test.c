#include <stdio.h>
#include <stdlib.h> // 提供 EXIT_SUCCESS

int main()
{
  // 字符串写法
  char a[] = "*****";
  char s1[] = "  ";
  // 打印时重复次数
  printf("%s\n", a);
  printf("%s%s\n", s1, a);
  printf("%s%s%s\n", s1, s1, a);
  printf("%s%s%s%s\n", s1, s1, s1, a);

  for (int i = 0, l = 4; i < l; i++)
  {
    printf("for 循环，这是第%d次，共有%d次\n", i, l);
  }
  return EXIT_SUCCESS;
}