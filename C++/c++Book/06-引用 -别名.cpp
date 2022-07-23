#include <iostream>
using namespace std;

void msg(int* p);
// 引用做函数参数传递
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main66() {
	int a = 10;

	int& b = a;
	// 别名 - 必须初始化，不能再改变。
	// 指针变量的根本是变量， 所以存储的指针地址（值）是可以随时改变的。

	msg(&a);
	msg(&b);

	a = 100;
	msg(&a);
	msg(&b);

	b = 200; // 其实是赋值操作，而不是改变引用  int c = 200;b = c;
	msg(&a);
	msg(&b);

	// 引用做函数参数传递
	cout << "引用做函数参数传递" << endl;
	int d = 99;
	mySwap03(a, d);
	msg(&a);
	msg(&d);


	system("pause");
	return 0;
}