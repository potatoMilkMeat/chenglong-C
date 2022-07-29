#include "public.h"

// 32-模板函数和普通函数调用规则
// 1、均可调用，优先普通函数
// 2、空模板参数列表 强制调用函数模板
// 3、函数模板可以发生函数重载
// 4、如果函数模板可以产生更好的匹配，优先调用函数模板

// 普通-1
void myPrient32(int a, int b)
{
	cout << "普通" << endl;
}

// 模板-2
template<class T>
void myPrient32(T a, T b) {
	cout << "模板" << endl;
}

// 模板-3
template<class T>
void myPrient32(T a, T b, T c) {
	cout << "重载模板" << endl;
}

// 模板-4
template<class T>
void myPrient32(T a, char b) {
	cout << "模板 更匹配，不用隐式类型转换" << endl;
}

void test32() {
	int a = 10, b = 20;
	// 默认是函数，如果没有实现，会报错
	myPrient32(a, b);

	// 空模板参数列表 强制调用函数模板
	myPrient32<>(a, b);

	// 重载根据参数匹配
	myPrient32<>(a, b, 100);

	// 参数的匹配
	myPrient32(a, 'c');
}