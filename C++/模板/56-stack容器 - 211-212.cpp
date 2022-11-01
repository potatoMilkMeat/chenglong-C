#include"public.h"
#include<stack>

// 栈容器 先进后出，只有栈顶一个出口
// 不允许遍历的行为，push, pop, top, empty, size

// 拷贝后打印
void printStackTop(const stack<int>&s) {
	stack<int> s2 = s;
	while (!s2.empty())
	{
		cout << "栈顶元素： " << s2.top() << endl;
		s2.pop();
	}
}

void test56() {
	stack<int> s;
	s.push(10);
	s.push(50);
	s.push(20);
	s.push(-30);

	printStackTop(s);
}
