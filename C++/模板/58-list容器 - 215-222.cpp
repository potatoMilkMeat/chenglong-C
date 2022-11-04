#include"public.h"
#include<list>

// list 链表 - 非连续的存储结构，数据中结构顺序是通过链表中的指针链接实现的
// 对任意位置进行快速插入和删除，动态存储分配，不会造成内存浪费和溢出
// 缺点：
// 容器的遍历速度，没有数组快。
// 占用空间比数组大

void printList(const list<int>&l) {
	for (list<int>::const_iterator it =l.begin(); it != l.end(); it++) {
		cout << " " << (*it);
	}
	cout << endl;
}

// list 构造
void initList() {
	list<int> l;
	for (int i = 0; i < 10; i++) { l.push_back(i);	}
	printList(l);

	// 支持it--, 但是不支持 it = it - 4;
	list<int>::iterator it = l.end();
	for (int i = 0; i < 4; i++)
	{
		it = --it;
	}
	list<int> l2(l.begin(), it);
	printList(l2);

	list<int> l3(4, 100);
	printList(l3);

	list<int> l4(l3);
	printList(l4);
}

// list 赋值和交换 swap
void assignList() {
	list<int> l(4, 100);

	list<int> l2 = l;
	printList(l2);

	cout << "交换前： " << endl;
	list<int> l3;
	l3.assign(l.begin(), --l.end());
	printList(l3);

	list<int> l4;
	for (int i = 0; i < 10; i++) { l4.push_back(i); }
	printList(l4);

	cout << "交换后： " << endl;
	l3.swap(l4);
	printList(l3);
	printList(l4);
}

// list 大小操作 size empty resize
void sizeList() {
	list<int> l;
	cout << "大小: " << l.size() << "为空: " << l.empty() << endl;
	for (int i = 0; i < 10; i++) { l.push_back(i); }
	printList(l);
	cout << "大小: " << l.size() << "为空: " << l.empty() << endl;

	l.resize(13);

	l.resize(20, -100);
	printList(l);
	cout << "大小: " << l.size() << "为空: " << l.empty() << endl;
}

// list 插入和删除
void insertList() {
	list<int> l;
	l.push_back(10); l.push_back(20); l.push_back(30);
	l.push_front(-10); l.push_front(-20);
	printList(l);

	l.pop_back(); l.pop_front();
	printList(l);

	l.insert(++l.begin(), 50);
	l.insert(++l.begin(), 3, 99);
	printList(l);

	list<int> l4;
	for (int i = 0; i < 10; i++) { l4.push_back(i); }

	l.insert(++l.begin(), l4.begin(), l4.end());
	printList(l);

	l.remove(99);
	printList(l);

	list<int>::iterator p = l.erase(++l.begin());
	printList(l);
	cout << "erase 删除后指针： " << *p << endl;

	l.erase(l.begin(), l.end());
	cout << "erase(l.begin(), l.end()) 删除。 ";
	cout << "为空：" << l.empty() << endl;
}

// list 数据存取 支持双向，不支持随机访问
void seeList() {
	list<int> l;
	for (int i = 0; i < 10; i++) { l.push_back(i); }
	printList(l);
	cout << "头的元素：" << l.front() << "   尾的元素：" << l.back() << endl;

	list<int>::iterator it = l.begin();

	// 支持双向
	int i = 3;
	while (--i)	{ it++;	}
	cout << "第 3 + begin元素：" << *it << endl;
}

// list 反序和  排序 
// 因为不支持随机访问, 不能使用通用的sort(begin, end)
// 自带sort函数
bool myCompare(int v1, int v2) {
	return v1 > v2;
}
void sortList() {
	list<int> l;
	for (int i = 0; i < 10; i++) { l.push_back(i); }
	printList(l);
	l.reverse();
	printList(l);

	l.sort();
	printList(l);

	// 降序提供方法- 或者比较结构体的东西
	l.sort(myCompare);
	printList(l);
}

// 学生
class Student {
public:
	Student(string name, int age, int height) {
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}
	string m_name;
	int m_age;
	int m_height;
};

// 打印学生
void printList(const list<Student>& l) {
	for (list<Student>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << "姓名： " << (*it).m_name << "  年龄： " << it->m_age << "  身高： " << it->m_height << endl;
	}
	cout << endl;
}

bool sortAge(Student s1, Student s2) {
	return s1.m_age < s2.m_age;
}

// 年龄小，身高高
bool sortAgeHeight(Student s1, Student s2) {
	return s1.m_age < s2.m_age ||  (s1.m_age == s2.m_age && s1.m_height > s2.m_height);
}

// list 排序案例
void sortEg() {
	list<Student> l;
	Student s1("唐僧", 20, 175);
	Student s2("孙悟空", 50, 165);
	Student s3("猪八戒", 30, 155);
	Student s4("沙和尚", 15, 195);
	Student s5("罗小黑", 15, 225);
	Student s6("老君", 15, 135);

	l.push_back(s1);
	l.push_back(s2);
	l.push_back(s3);
	l.push_back(s4);
	l.push_back(s5);
	l.push_back(s6);

	printList(l);
	cout << "--------------排序后 年龄小----------------" << endl;
	l.sort(sortAge);
	printList(l);
	cout << "--------------排序后 年龄小，身高高----------------" << endl;
	l.sort(sortAgeHeight);
	printList(l);
}

void test58() {
	//initList();
	//assignList();
	//sizeList();
	//insertList();
	//seeList();
	//sortList();
	sortEg();
}