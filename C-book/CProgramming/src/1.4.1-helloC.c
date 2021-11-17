#include <stdio.h>
int main()
{
	// 声明add 并求和后打印
	int add(int a, int b); // 使用函数前，需要先声明
	int sum = add(10, 20); // 直接求值
	printf("10+20=%d.\n", sum);

	// 求最大值，手动输入
	printf("请输入两个数字，以','隔开. 求最大值\n");
	int max(int x, int y);
	int a, b, c;
	scanf("%d,%d", &a, &b);
	c = max(a, b);
	printf("max is %d.\n", c);

	printf("This is C program. \n");
	return 0;
}
// 计算和
int add(int a, int b)
{
	return (a + b);
}
// 求最大值
int max(int x, int y)
{
	int z;
	if (x > y)
		z = x;
	else
		z = y;
	return (z);
}
