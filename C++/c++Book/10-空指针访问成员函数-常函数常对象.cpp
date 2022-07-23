#include <iostream>
using namespace std;
#include <string>

// 空指针调用成员函数

class Person01
{
public:
	void showClassName() {
		cout << "this is Person Class" << endl;
	}
	void showPersonAge() {
		// 报错是因为传入的指针为NULL
		if (this == NULL) return;
		cout << "this is Person Age" << this->m_Age << endl;
	}

	// 常函数
	// const Person * const this; 
	// 在成员函数后面加 const ,修饰的是this指向，让指针指向的值也不可以修改
	void showPerson() const
	{	
		// this 指针的本质 是指针常量 Person * const this， 指针的指向是不可以改点的
		// this = NULL: 
		//this->m_Age = 100;
		this->m_B = 100;

	}

 	int m_Age;
	mutable int m_B; // 特殊变量，即使在常函数中，也可以修改这个值，加关键字 mutable;
private:

};

void test0001() {
	Person01* p = NULL;
	p->showClassName();
	p->showPersonAge();
}
// 常对象 const修饰
void test0002() {
	const Person01 p;
	//p.m_Age = 100; // 普通的不能改变
	p.m_B = 200; // mutable 特殊变量, 能改变
	// 常对象只能调用常函数
	p.showPerson();
}

int main10() {
	test0001();
	int a = 10;
	// 指针常量  指针p 固定
	int* const p = &a; // const 修饰指针，指针的指向p固定，而 *p 值可以改变
	// 常量指针  指向*p 值 固定
	const int* p2 = &a; // const 修饰*p2, 指针的值固定，指向 p2可以改变。

	system("pause");
	return 0;
}