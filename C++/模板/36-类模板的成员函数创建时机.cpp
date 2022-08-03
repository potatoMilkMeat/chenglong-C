#include "public.h"

// 类模板的成员函数. 并不是一开始就创建的，而是在模板调用时再生成
class Person36_1 {
public:
	void showPerson1() { cout << "Person36_1 " << endl;	}
};
class Person36_2 {
public:
	void showPerson2() { cout << "Person36_2 " << endl;	}
};

template<class T>
class Person36 {
public:
	void func1() { obj.showPerson1(); }
	void func2() { obj.showPerson2(); }
	T obj;
};

void test36() {
	Person36<Person36_1> m;
	m.func1();
	//m.func2();  Person36_2 才能使用
}