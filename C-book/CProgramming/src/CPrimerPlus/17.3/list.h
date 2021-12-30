#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

/* 特定程序的声明 */
#define TSIZE  51 /* 存储电影名称的字符数组大小 */
struct film
{
  char title[TSIZE];
  int rating;
};

/* 一般类型定义 */
typedef struct film Item;
typedef struct node{
  Item item;
  struct node * next;
} Node;
typedef Node * List;

/* 函数原型 */

// 操作：     初始化一个链表
// 前置条件：  plist 指向一个链表
// 后置条件：  链表初始化为空
void InitializeList(List * plist);

// 操作：     确定链表时候为空，plist 指向一个已初始化链表
// 后置条件：  如果链表为空，返回 true,否则返回 false
bool ListIsEmpty(const List * plist);

// 操作：     确定链表时候已满，plist 指向一个已初始化链表
// 后置条件：  如果链表已满，返回 true,否则返回 false
bool ListIsFull(const List * plist);

// 操作：     确定链表中的项数，plist 指向一个已初始化链表
// 后置条件：  返回该链表的项数
unsigned int ListItemCount(const List * plist);

// 操作：     在链表末尾添加项
// 前置条件：  item是一个待添加到链表的项，plist 指向一个已初始化链表
// 后置条件：  如果操作成功，该函数会在链表末尾添加一个项，且返回 true; 否则返回 false
bool AddItem(Item item, List * plist);

// 操作：     把函数作用于链表中的每一项
// 前置条件：  plist 指向一个已初始化链表，
//           pfun 指向一个函数，该函数接受一个Item类型的参数，且无返回值
// 后置条件：  pfun指向的函数作用月链表中的每一项
void Traverse(const List * plist, void(* pfun)(Item item));

// 操作：     释放已分配的内存(如果有的话)
// 前置条件：  plist 指向一个已初始化链表
// 后置条件：  释放了为链表分配的所有内存，链表设置为空
void EmptyTheList(List * plist);

#endif
