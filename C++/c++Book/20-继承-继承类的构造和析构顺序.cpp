#include "00-main.h"

class Base20{
public:
	Base20() { cout << "Base20 ���캯��" << endl; };
	~Base20() { cout << "Base20 ��������" << endl; };
};

class Son20: public Base20 {
public:
	Son20() { cout << "Son20 ���캯��" << endl; };
	~Son20() { cout << "Son20 ��������" << endl; };
};

void test20() { Son20 s; }