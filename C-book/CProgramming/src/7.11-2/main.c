#include <stdio.h>
#include "./enter_string.c"
#include "./deletE_string.c"
#include "./print_string.c"

int main()
{
  void enter_string(char str[]);
  void deletE_string(char str[], char ch);
  void print_string(char str[]);

  print_string("请先输入字符串语句，回车后，再输入需要删除的字符，在回车执行。");

  char c, str[80];
  enter_string(str);
  scanf("%c",&c);
  deletE_string(str,c);
  print_string(str);
  return 0;
}
