#include"public.h"
#include<vector>
#include<algorithm>
#include<numeric> // 小型算法

void print_Int66(int v) { cout << v << "  "; }
void print_V66(const vector<int>& v) {
	for_each(v.begin(), v.end(), print_Int66);
	cout << endl;
}
class Student66 {
public:
	Student66(string name, int money) {
		this->m_name = name;
		this->m_money = money;
	};
	string m_name;
	int m_money;
};
int student66_add(const int &val,const Student66& s) {
	return val + s.m_money;
};
// accumulate  计算元素容器累积总和
void t_accumulate() {
	vector<int> v;
	for (int i = 1; i < 101; i++) { v.push_back(i);}
	int total = accumulate(v.begin(), v.end(), 0); // 第三个参数是起始累加值
	cout << "总数： " << total << endl;

	// 自定义类型的累加
	vector<Student66> s;
	Student66 s1("aaa", 100);
	Student66 s2("bbb", 200);
	Student66 s3("ccc", 300);
	Student66 s4("ddd", 400);
	s.push_back(s1); s.push_back(s2); s.push_back(s3); s.push_back(s4);

	total = accumulate(s.begin(), s.end(), 0, student66_add);
	cout << "总数： " << total << endl;
}


// fill 向容器中添加元素
void t_fill() {
	vector<int> v;
	v.reserve(4);

	fill(v.begin(), v.end(), 1000);
	print_V66(v);
}

void test66() {
	//t_accumulate();
	t_fill();
}