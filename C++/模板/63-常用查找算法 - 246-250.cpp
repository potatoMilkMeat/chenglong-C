#include"public.h"
#include<vector>
#include<algorithm>

// find
// 人，重载 == 判定
class Person {
public:
	bool operator==(const Person& p) {
		return this->m_age == p.m_age && this->m_name == p.m_name;
	};
	Person(string name, int age) {
		this->m_age = age;
		this->m_name = name;
	};
	string m_name;
	int m_age;

};
void t_find() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }

	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end()) { cout << "没找到！" << endl; }
	else { cout << "找到：" << *it << endl; }

	vector<Person> v1;
	Person p1("aaa", 10); v1.push_back(p1);
	Person p2("bbb", 20); v1.push_back(p2);
	Person p3("ccc", 30); v1.push_back(p3);
	Person p4("ddd", 40); v1.push_back(p4);

	Person pp("bbb", 20);
	vector<Person>::iterator it2 = find(v1.begin(), v1.end(), pp);
	if (it2 == v1.end()) { cout << "没找到！" << endl; }
	else { cout << "找到： 姓名 " << it2->m_name << "   年龄 " << it2->m_age << endl; }
	
}

// find_if


// adjacent_find 查找相邻重复元素


// binary_search  二分查找


// count

// count_if

void test63() {
	t_find();
}