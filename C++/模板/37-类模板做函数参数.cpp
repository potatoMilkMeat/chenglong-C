#include "public.h"

// 类模板做函数参数
template<class T1, class T2 >
class Person37 {
public:
	Person37(T1 name, T2 age) {
		this->name = name;
		this->age = age;
		cout << "T1 的类型：" << typeid(T1).name() << endl;
		cout << "T2 的类型：" << typeid(T2).name() << endl;
	}
	void showPerson() {
		cout << "姓名： " << name << "  年龄： " << age << endl;
	}
	T1 name;
	T2 age;
};

//指定传入类型 - 只能适配一种
void printPerson(Person37<string, int>& p) { p.showPerson(); }

//参数模板化 - 可以适配多重
template<class T1, class T2>
void printPerson(Person37<T1, T2>& p) {
	p.showPerson();
}

//整个类模板化 - 使用的时候才知道是什么模板
template<class T>
void printPerson2(T &p) {
	p.showPerson();
	cout << "T 的类型：" << typeid(T).name() << endl;

}

void test37() {
	
	Person37<string, int> cl("程龙", 34);
	// 类直接使用
	//cl.showPerson();

	printPerson(cl);

	Person37<char, int> ts('t', 1001);
	printPerson(ts);

	Person37<string, int> swk("孙悟空", 999);
	printPerson2(swk);
}