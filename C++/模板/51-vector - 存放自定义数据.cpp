#include "public.h"
#include <vector>
#include <algorithm>

class Person51 {
public:
	Person51(string name, int age) { this->name = name; this->age = age; };
	string name;
	int age;
};

void pringPerson51(Person51 p) {
	cout << "姓名：" << p.name << "   年龄：" << p.age << endl;
}

void pringPerson51_(Person51* p) {
	cout << "姓名：" << p->name << "   年龄：" << p->age << endl;
}

void test51() {
	vector<Person51> v;
	Person51 p1("aa", 10);
	Person51 p2("bb", 20);
	Person51 p3("cc", 30);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	for_each(v.begin(), v.end(), pringPerson51);

	vector<Person51*> v_;
	v_.push_back(&p1);
	v_.push_back(&p2);
	v_.push_back(&p3);

	for_each(v_.begin(), v_.end(), pringPerson51_);
}