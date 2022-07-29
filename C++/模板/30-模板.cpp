#include "public.h"


// 两个整形交换函数
void swapInt30(int &a, int &b) {
	int temp = a;
	a = b;	b = temp;
}
// 两个浮点交换函数
void swapDouble30(double& a, double& b) {
	double temp = a;
	a = b;	b = temp;
}

// 函数模板 - 类型抽象化
template<typename T>
void mySwap30(T &a, T&b) {
	T temp = a;
	a = b;	b = temp;
}

void test30() {
	int a = 1, b = 2;
	double c = 0.1, d = 0.2;

	//swapInt30(a, b);
	//swapDouble30(c, d);
	
	// 自动推导 是不会隐式类型转换
	// 1、自主推到出来的 int，类型要相同
	mySwap30(a, b);

	// 指定类型 是会隐式类型转换
	// 2、显示指定类型 double; 使用前必须确定类型
	mySwap30<double>(c, d);

	cout << a << '\t' << b << endl;
	cout << c << '\t' << d << endl;
}