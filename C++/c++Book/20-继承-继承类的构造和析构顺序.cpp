#include "00-main.h"

class Base20{
public:
	Base20() { cout << "Base20 构造函数" << endl; };
	~Base20() { cout << "Base20 析构函数" << endl; };
};

class Son20: public Base20 {
public:
	Son20() { cout << "Son20 构造函数" << endl; };
	~Son20() { cout << "Son20 析构函数" << endl; };
};

void test20() { Son20 s; }