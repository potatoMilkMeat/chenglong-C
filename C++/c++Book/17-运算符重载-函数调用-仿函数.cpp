#include "00-main.h"

class MyPrint
{
public:
	// 重载运算符 函数调用 - 又叫仿函数
	// 打印输出类
	void operator() (string text){
		cout << text << endl;
	}
};

// 打印函数
void MyPrit02(string text) {
	cout << text << endl;
}

// 
class MyAdd {
public:
	int operator() (int m, int n) {
		return m + n;
	}
};

void test17() {
	MyPrint myPrint;
	myPrint("Hello world! - 仿函数");
	MyPrit02("Hello world! - MyPrit0202");

	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret = " << ret << endl;
	
	// 匿名函数对象
	cout << "MyAdd()(10,100) : " << MyAdd()(10,100) << endl;
}