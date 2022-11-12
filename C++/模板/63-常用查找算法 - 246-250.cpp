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
// 函数，仿函数，一元谓词
bool greater_5(int val) {
	return val > 5;
}
// 年龄大于20岁的人
class Greater20 {
public:
	bool operator()(const Person &p) {
		return p.m_age > 20;
	}
};
void t_find_if() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }

	vector<int>::iterator it = find_if(v.begin(), v.end(), greater_5);
	if (it == v.end()) { cout << "没找到！" << endl; }
	else { cout << "找到：" << *it << endl; }

	vector<Person> v1;
	Person p1("aaa", 10); v1.push_back(p1);
	Person p2("bbb", 20); v1.push_back(p2);
	Person p3("ccc", 30); v1.push_back(p3);
	Person p4("ddd", 40); v1.push_back(p4);

	vector<Person>::iterator it2 = find_if(v1.begin(), v1.end(), Greater20());
	if (it2 == v1.end()) { cout << "没找到！" << endl; }
	else { cout << "找到： 姓名 " << it2->m_name << "   年龄 " << it2->m_age << endl; }
}


// adjacent_find 查找相邻重复元素
void t_adjacent_find() {
	vector<int> v;
	v.push_back(0); v.push_back(2);
	v.push_back(0); v.push_back(3);
	v.push_back(1); v.push_back(4);
	v.push_back(3); v.push_back(3);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) { cout << "没找到相邻重复元素！" << endl; }
	else { cout << "找到：" << *it << "   " <<  *(++it) << endl; }
}

// binary_search  二分查找  有序结构
// 最好使用set,插入就二叉排序
// 返回 true  false
void t_binary_search() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	v.push_back(2); // 启动此行，变成无序序列 ，结果找不到9
	sort(v.begin(), v.end()); // 重新排序后，结果能找到9

	bool result = binary_search(v.begin(), v.end(), 9);
	cout << "找到：" << result  << endl;
}

// count 返回整数
void t_count() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	v.push_back(2);
	cout << "找到数量：" << count(v.begin(), v.end(), 2) << endl;


	vector<Person> v1;
	Person p1("aaa", 10); v1.push_back(p1);
	Person p2("bbb", 20); v1.push_back(p2);
	Person p3("ccc", 30); v1.push_back(p3);
	Person p4("ddd", 40); v1.push_back(p4);

	Person pp("bbb", 20); v1.push_back(pp);

	cout << "找到数量：" << count(v1.begin(), v1.end(), p2) << endl;

}

// count_if 返回整数
void t_count_if() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	cout << "找到数量：" << count_if(v.begin(), v.end(), greater_5) << endl;
}

void test63() {
	//t_find();
	//t_find_if();
	//t_adjacent_find();
	//t_binary_search();
	//t_count();
	t_count_if();
}