#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE   41

struct film {
  char title[TSIZE];
  int rating;
  struct film * next; // 指向链表的下一个
};
char * s_gets(char *st, int n);

int main(void){
  struct film * head = NULL;
  struct film * prev, *current;
  char input[TSIZE];

  puts("请输入第一个电影名称：");

  while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
  {
    current = (struct film *) malloc(sizeof(struct film));
    if(head == NULL){
      head = current;
    }else{
      prev->next = current;
    }
    
    current->next = NULL;
    strcpy(current->title, input);

    puts("请输入评分 <0-10>:");
    scanf("%d", &current->rating);
    while (getchar() != '\n')
      continue;
      
    
    puts("请输入下一个电影名称 （空行直接停止）：");
    prev = current;
  }

  /* 显示电影列表 */
  if(head == NULL)
    printf("没有输入数据！");
  else
    printf("这是电影列表：\n");
  current = head;
  while (current != NULL)
  {
    printf("电影：%s   评分：%d\n", current->title, current->rating);
    current = current->next;
  }

  /* 完成任务，释放已分配的内存 */
  current = head;
  while (current != NULL)
  {
    head = current->next;
    free(current);
    current = head;
  }
  printf("结束,内存已释放。\n");

  return 0;
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
      while (getchar() != '\n')
        continue;
  }
  return ret_val;
}
