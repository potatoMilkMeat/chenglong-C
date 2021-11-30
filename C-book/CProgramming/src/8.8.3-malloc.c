#include <stdio.h>
#include <stdlib.h>

int main()
{
  void printf_s(char *p);
  void copy_s(char *p, char *str);
  char *p = (char *)malloc(50 * sizeof(char));
  char str[] = "ChengLong is No.1";
  char *p2 = str;
  char *p1 = p;
  printf_s(p);

  copy_s(p1, p2);
  printf_s(p);
  return 0;
}

void printf_s(char *p)
{
  printf("%u   %s \n", p, p);
}

void copy_s(char *p, char *str)
{
  while (*p++ = *str++)
  {
    printf("%c", *(p-1));
  }
  printf("\n");
}
