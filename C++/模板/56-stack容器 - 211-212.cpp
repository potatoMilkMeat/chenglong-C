#include"public.h"
#include<stack>

// ջ���� �Ƚ������ֻ��ջ��һ������
// �������������Ϊ��push, pop, top, empty, size

// �������ӡ
void printStackTop(const stack<int>&s) {
	stack<int> s2 = s;
	while (!s2.empty())
	{
		cout << "ջ��Ԫ�أ� " << s2.top() << endl;
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
