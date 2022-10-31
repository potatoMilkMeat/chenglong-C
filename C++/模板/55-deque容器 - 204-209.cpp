#include"public.h"
#include <deque>
#include<algorithm>
// 排序 sort

// deque容器概念 - 双端数组
// 中控器来维护每段缓冲区的内容，缓冲区（不连续）存放正式数据。
// 双端插入快，内存空间不连续，访问速度低，也支持随机访问。


void printDeque(const deque<int> &d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// deque 构造
void initDeque() {
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int> d3(10, 100);
	printDeque(d3);

	deque<int> d4(d3);
	printDeque(d4);
}

// deque 赋值
void assignDeque() {
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	

	deque<int> d2 = d1;
	printDeque(d2);

	deque<int> d3;
	d3.assign(10, 100);
	printDeque(d3);

	deque<int> d4;
	d4.assign(d3.begin(), d3.begin()+4);
	printDeque(d4);
}

// deque 大小操作
void sizeDeque() {
	deque<int> d1;
	cout << d1.empty() << "  "  << d1.size() << endl;

	for (int i = 0; i < 10; i++){
		d1.push_back(i);
	}
	printDeque(d1);
	cout << d1.empty() << "  " << d1.size() << endl;


	d1.resize(13);
	printDeque(d1);
	cout << d1.size() << endl;

	d1.resize(20, 100);
	printDeque(d1);
	cout << d1.size() << endl;
}

// deque 插入和删除 clear
void insertDeque() {
	deque<int> d1;
	for (int i = 0; i < 4; i++) {
		d1.push_back(i);
	}
	printDeque(d1);
	d1.pop_back(); d1.pop_back();
	printDeque(d1);

	d1.push_front(-1);
	d1.push_front(-2);
	printDeque(d1);
	d1.pop_front();
	printDeque(d1);

	d1.insert(d1.begin(), -100);
	d1.insert(d1.begin(), 4, -10);
	printDeque(d1);

	deque<int> d2(4, -2);
	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1);

	d1.erase(d1.begin());
	printDeque(d1);
	d1.erase(d1.begin(), d1.begin() + 8);
	printDeque(d1);
}

// deque 数据存取 back, front
void atDeque() {
	deque<int> d1;
	for (int i = 0; i < 4; i++) {
		d1.push_back(i);
	}
	d1[3] = 100;
	printDeque(d1);

	d1.at(0) = -3;
	printDeque(d1);
}

// deque 排序
void sortDeque() {
	deque<int> d;
	d.push_back(20);
	d.push_back(10);
	d.push_back(100);
	d.push_back(50);
	printDeque(d);

	// 默认从小到大
	// 对于支持随机访问的迭代器的容器，都可以利用sort算法直接对齐进行排序
	// vector容器也支持 sort
	sort(d.begin(), d.end());
	printDeque(d);
}



void test55() {
	//initDeque();
	//assignDeque();
	//sizeDeque();
	//insertDeque();
	//atDeque();
	sortDeque();
}
