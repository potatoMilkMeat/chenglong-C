#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int chartArr(), getStr(), worldLen();
  chartArr();
  getStr();
  // 输入内容 "qqqq cheng i am is men"
  // scanf 优先捕获，按照 空格 区分输入的 scanf[1] ="qqqq", scanf[2] ="cheng"2, scanf[3] ="i am is men"2字符串数组。
  // gets在 scanf 后执行，允许输入字符串中带空格，此例子中只能匹配第三个输入 "i am is men"。

  char hello[30] = "Hello ";
  char name[17];
  printf("请输入你的名字，回车结束。\n");
  scanf("%s", name);
  worldLen(); // 在这里，第二个空格之后的才是输入的语句。
  puts(strcat(hello, name));

  return EXIT_SUCCESS;
}

int chartArr()
{
  char str[] = "我是程龙，在C语言 焊接";
  printf("%s\n", str);
  return 0;
}

int getStr()
{
  printf("请输入字符串，长度为16, 空格结束，回车提交\n");
  char str[17];
  scanf("%s", str);
  printf("%s\n", str);
  return 0;
}

int worldLen()
{
  char string[81];
  int i, num = 0, world = 0;
  char c;
  gets(string);
  for (i = 0; (c = string[i]) != '\0'; i++)
    if (c == ' ')
      world = 0;
    else if (world == 0)
    {
      world = 1;
      num++;
    }

  printf("这是单词的总数 %d\n", num);
  return 0;
}