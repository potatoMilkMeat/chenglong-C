#include <stdio.h>

int main()
{
  char a[] = "Chenglong";
  a[5] = 'L';
  char *b = "Chenglong";
  printf("%s\n%s\n", a, b);
  printf("%d\n", a + 5);
  printf("%d     %d \n", *(a + 5), a[5]);
  return 0;
}
