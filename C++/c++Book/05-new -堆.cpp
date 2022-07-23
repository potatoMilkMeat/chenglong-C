#include <iostream>
using namespace std;

int* func() {
	int* p = new int(10);
	return p;
}
void msg(int* p) {
	cout << p << '\t' << *p << endl;
}

void main05() {

	int* p = func();
	msg(p);
	msg(p);
	delete p; // 释放空间

	int* arr = new int[10];
	for (int i = 0; i < 10; i++)	{
		arr[i] = i + 100;
		msg(arr + i);
	}

	// 释放数组
	delete[] arr;

	system("pause");
}