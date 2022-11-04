#include"public.h"
#include<set>


// set multiset容器 概念
// 插入时会自动被排序  关联式容器，底层结构是二叉树实现
// set 不容许有重复元素
// multiset 荣誉有重复元素

// 打印
void printSet(set<int> &s) {
	for (set<int>::iterator it = s.begin(); it != s.end();it++) {
		cout << "  " << *it;
	}
	cout << endl;
}

// 打印
void printMultiSet(multiset<int>&s) {
	for (multiset<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "  " << *it;
	}
	cout << endl;
}


// set容器 构造和赋值
void initSet() {
	set<int> s;
	s.insert(5); s.insert(10); s.insert(2); s.insert(1); s.insert(1);
	printSet(s);

	set<int> s2(s);
	printSet(s2);

	set<int>s3;
	s3 = s2;
	printSet(s3);
}

// set容器 大小和交换
void  sizeSet() {
	set<int> s;
	cout << " 大小： " << s.size() << "    为空： " << s.empty() << endl;
	s.insert(5); s.insert(10); s.insert(2); s.insert(1);

	printSet(s);
	cout << " 大小： " << s.size() << "    为空： " << s.empty() << endl;

	set<int> s2;
	s2.insert(50); s2.insert(100);
	s.swap(s2);
	printSet(s);
}


// set容器 插入和删除  clear
void insertSet() {
	set<int> s;
	s.insert(5); s.insert(10); s.insert(2); s.insert(1); s.insert(1);
	printSet(s);

	s.erase(s.begin());
	printSet(s);

	s.erase(10);
	printSet(s);

	s.erase(s.begin(), --s.end());
	printSet(s);
}

// set容器 查找和统计 find    count
// find 找到 给迭代器，否则给结束的迭代器 end()
// count 返回 0, 1
void findSet() {
	set<int> s;
	s.insert(5); s.insert(10); s.insert(2); s.insert(1); s.insert(1);
	printSet(s);

	set<int>::iterator it;
	it = s.find(5);
	if (it != s.end()) {
		cout << " 5 找到了: " << *it << endl;
	}else cout << " 5 没找到 " << endl;
	
	int num = s.count(5);
	cout << " 5 统计次数： " << num << endl;
}


// 打印 pair
void printPair(pair<set<int>::iterator, bool> &ret) {
	if (ret.second) {
		cout << "第一次插入成功 " << endl;
	}
	else {
		cout << "插入失败 " << endl;
	}
}

// set容器 set 和 multiset区别
void difSet() {
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	cout << " 对组出现的迭代器：" << *(ret.first) << endl;
	printPair(ret);

	ret = s.insert(10);
	printPair(ret);


	multiset<int> ms;
	ms.insert(10); ms.insert(10);
	printMultiSet(ms);
}

// pair对组创建
// 成对出现的数据，利用对组可以返回两个数据
void initPair() {
	pair<string, int> p("chengl", 20);
	cout << p.first << "  " << p.second << endl;

	pair<string, int> p2 = make_pair("chenglong", 34);
	cout << p2.first << "  " << p2.second << endl;
}


// set容器排序 - 内置内型
class MyCompareDef {
public:
	// vs2019 报C3848错误，需要把参数改成 const引用, 参数()后面添加 const 修饰
	bool operator() (const int& v1, const int& v2) const // 此处添加const修饰
	{
		return v1 > v2;
	}
};
void printSetDef(set<int, MyCompareDef>& s) {
	for (set<int, MyCompareDef>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "  " << *it;
	}
	cout << endl;
}

void sortSet_default() {
	set<int> s1;
	s1.insert(10); s1.insert(20); s1.insert(40); s1.insert(30);
	printSet(s1);

	// 指定排序规则从大到小
	set<int, MyCompareDef> s2;
	s2.insert(10); s2.insert(20); s2.insert(40); s2.insert(30);
	printSetDef(s2);

}


// set容器排序 - 自定义内型
// 自定义类型，指定排序规则

class Student_d
{
public:
	Student_d(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	};
	string m_name;
	int m_age;
};
class MyCompareStud {
public:
	// vs2019 报C3848错误，需要把参数改成 const引用, 参数()后面添加 const 修饰
	bool operator() (const Student_d & v1, const Student_d & v2) const // 此处添加const修饰
	{
		return v1.m_age < v2.m_age;
	}
};
void printSetStud(set<Student_d, MyCompareStud>& s) {
	for (set<Student_d, MyCompareStud>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "姓名：" << it->m_name << "     年龄：" << it->m_age << endl;
	}
}
void sortSet_conf() {
	Student_d p1("刘备", 24);
	Student_d p2("张三", 14);
	Student_d p3("李四", 34);
	Student_d p4("王五", 54);

	set<Student_d, MyCompareStud> s;
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	printSetStud(s);
}

void test59() {
	//initSet();
	//sizeSet();
	//insertSet();
	//findSet();
	//difSet();
	//initPair();
	//sortSet_default();
	sortSet_conf();
}