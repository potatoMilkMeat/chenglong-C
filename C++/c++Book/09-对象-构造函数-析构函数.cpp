#include <iostream>
using namespace std;

// 对象的初始化和清理
class Base09{
public:
	Base09() { cout << "Base09 构造函数" << endl; }
	~Base09() { cout << "Base09 析构函数" << endl; }
};


class Person09 {
public:
	Person09();
	~Person09();
	Base09 m_base;
};


// 有参数，可以重载
Person09::Person09() {
	cout << "Person 构造函数" << endl;
}
Person09::~Person09() {
	cout << "Person 析构函数" << endl;
}

void test09() { Person09 p; }

