#include"public.h"
#include<queue>

// 队列，先进先出 push, pop, back，front, size, empty
// 不能遍历, 只有队头和队位才能被外界访问

void printQueueFront(const queue<int> &q) {
	queue<int> q2 = q;
	while (!q2.empty())
	{
		cout << "队列头元素： " << q2.front() << endl;
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