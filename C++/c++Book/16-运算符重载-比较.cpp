#include "00-main.h"

class Person16 {
public:
	Person16(string name, int age) {
		m_name = name;
		m_age = age;
	}
	// 相等
	bool operator==(Person16 &p) {
		return m_name == p.m_name && m_age == p.m_age;
	}
	// 不等
	bool operator!=(Person16& p) {
		return m_name != p.m_name || m_age != p.m_age;
	}

	string m_name;
	int m_age;
};

void test16() {
	Person16 p("Tom", 18);
	Person16 p1("Jerry", 18);

	bool res = p == p1;
	bool res_No = p != p1;
	cout << (res ? "p == p1" : "p != p1") << endl;
	cout << (res_No ? "p != p1" : "p == p1") << endl;
}
