#include <stdio.h>

int main()
{
  const char a = 'C', b = 'L';
  putchar(a);
  putchar(b);
  putchar('\n');
  putchar(a + 32);
  putchar(b + 32);
  putchar('\n');

  int getChar_3();
  getChar_3(); 
  return 0;
}

int getChar_3()
{
  char a, b;
  a = getchar();
  b = getchar();
  printf("%c%c",a,b);
  return 0;
}
