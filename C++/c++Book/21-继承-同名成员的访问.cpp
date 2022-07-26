#include "00-main.h"

class Base21 {
public:
	void func() { cout << "Base21 func() " << endl; }
	void func(int a) { cout << "Base21 func(int a) " << endl; }
	Base21() { m_a = 100; }
	int m_a;
	static int m_A;
};
int Base21::m_A = 101;

class Son21:public Base21 {
public:
	void func() { cout << "Son21 func() " << endl; }
	Son21() { m_a = 200; }
	int m_a;
	static int m_A;
};
int Son21::m_A = 201;

void test21() {
	Son21 s;
	cout << "s.m_a " << s.m_a << endl;
	cout << "s.Base21::m_a " << s.Base21::m_a << endl;
	s.func();
	s.Base21::func();
	s.Base21::func(10);

	cout << "***************** " << endl;
	cout << "s.m_A " << s.m_A << endl;
	cout << "s.Base21::m_A " << s.Base21::m_A << endl;

	cout << "*****\t static 成员多了一种类访问" << endl;
	cout << "Son21::m_A " << Son21::m_A << endl;
	cout << "Son21::Base21::m_A " << Son21::Base21::m_A << endl;
	cout << "*****\t static 函数成员 与static 变量成员一至" << endl;
}