#include "00-main.h"

class Base22_1 {
public:
	Base22_1() { m_a = 10; }
	int m_a;
};

class Base22_2{
public:
	Base22_2() { m_a = 20; }
	int m_a;
};

class Son22: public Base22_1, public Base22_2 {
public:
	Son22() { m_b = 1; m_c = 2; }
	int m_b;
	int m_c;
};

void test22() {
	Son22 s;
	cout << "sizeof(s)  " << sizeof(s) << endl;
	cout << "s.m_b   " << s.m_b << endl;
	cout << "s.Base22_1::m_a   " <<s.Base22_1::m_a <<endl;
	cout << "s.Base22_2::m_a   " << s.Base22_2::m_a << endl;
}