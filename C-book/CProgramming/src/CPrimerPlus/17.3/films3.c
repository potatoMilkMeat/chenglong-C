#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "list.c"

void showmovies(Item item);
char * s_gets(char * st, int n);

int main()
{
  List movies;
  Item temp;
  // 初始化
  InitializeList(&movies);
  if(ListIsFull(&movies)){
    fprintf(stderr, "没有内存空间来使用，程序退出。\n");
    exit(1);
  }
  // 获取用户输入并存储
  puts("请输入第一个电影名称：");
  while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
  {
    puts("输入电影评分<1-10>:");
    scanf("%d", &temp.rating);
    while (getchar() != '\n')
      continue;
    if(AddItem(temp, &movies) == false){
      fprintf(stderr, "错误：没有足够的内存 \n");
      break;
    }
    if(ListIsFull(&movies)){
      puts("链表已满。");
      break;
    }
    puts("输入新的电影名称，如果输入空行则退出程序：");
  }

  // 显示
  if(ListIsEmpty(&movies))
    printf("链表没有输入信息.\n");
  else{
    printf("以下是链表的信息：");
    Traverse(&movies,showmovies);
    printf("你输入了 %d个电影。\n", ListItemCount(&movies));
  }

  // 清理
  EmptyTheList(&movies);
  printf("再见！！");

  // 为不直接退出，显示“再见”
  char * s;
  scanf("%s", &s);

  return 0;
}

void showmovies(Item item){
  printf("电影： %s   评分：%d\n", item.title, item.rating);
}

char * s_gets(char * st, int n){
  char * ret_val;
  char * find;

  ret_val = fgets(st, n, stdin);
  if(ret_val){
    find = strchr(st, '\n');
    if(find)
      *find = '\0';
    else
      while(getchar() != '\n')
        continue;
  }
  return ret_val;
}
