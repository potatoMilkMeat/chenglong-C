#include "00-main.h"

class Person15 {
public:
	Person15(int age) {
		m_Age = new int(age);
	}
	~Person15()
	{
		if (m_Age != NULL) {
			cout << "销毁 p 的年龄" << *m_Age << endl;
			delete m_Age;
			m_Age = NULL;
		}
	}
	// 重载 赋值运算符
	Person15& operator=(Person15 &p) {
		// 编译器提供的是浅拷贝
		//m_Age = p.m_Age;

		// 判断是否有属性在堆区，如果有先释放干净
		if (m_Age != NULL) { 
			cout << "赋值  销毁 p 的年龄" << *m_Age << endl;
			delete m_Age; }
		// 深拷贝出一个区域
		m_Age = new int(*p.m_Age);
		return *this;
	}
	int* m_Age;
};

void test15() {
	Person15 p(18);
	Person15 p1(20);
	Person15 p2(30);
	cout << "p 的年龄" << *p.m_Age << endl;
	cout << "p1 的年龄" << *p1.m_Age << endl;
	cout << "p2 的年龄" << *p2.m_Age << endl;

	//p1 = p;
	p2 = p1 = p;
	cout << "p1 的年龄" << *p1.m_Age << endl;
	cout << "p2 的年龄" << *p2.m_Age << endl;
}
