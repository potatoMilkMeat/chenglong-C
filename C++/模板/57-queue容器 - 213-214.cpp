#include"public.h"
#include<queue>

// ���У��Ƚ��ȳ� push, pop, back��front, size, empty
// ���ܱ���, ֻ�ж�ͷ�Ͷ�λ���ܱ�������

void printQueueFront(const queue<int> &q) {
	queue<int> q2 = q;
	while (!q2.empty())
	{
		cout << "����ͷԪ�أ� " << q2.front() << endl;
		q2.pop();
	}
}


void test57() {
	queue<int> q;
	q.push(20);
	q.push(50);
	q.push(10);
	q.push(-30);
	
	printQueueFront(q);
}