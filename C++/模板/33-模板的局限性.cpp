#include "public.h"

// 模板的局限性
template<class T>
void compare33(T &a,T &b) {
	cout << (a == b ? "a == b" : "a != b") << endl;
}

// 特殊的类或数组
class Person33
{
public:
	Person33(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

template<>
void compare33(Person33 &a, Person33 &b) {
	cout << (a.name == b.name && a.age == b.age ? "p1 == p2" : "p1 != p2") << endl;
}

void test33() {
	int a = 10, b = 10;
	char c = 'c';
	compare33(a, b);
	compare33(a, *new int(c));

	Person33 p1("tom", 10), p2("tom", 10);
	compare33(p1, p2);
}