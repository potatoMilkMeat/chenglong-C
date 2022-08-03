#include "public.h"

//38 - 类模板和继承
template<class T>
class Base38 {
public:
	//Base38(T m) { this->m = m; }
	//void show() { count << "Base38：  " << m; }
	T m;
};

// 如果父类是类模板，子类需要指定父类的 类型，或者成为类模板并指定
template<class T1, class T2>
class Son38 : public Base38<T2> {
public:
	Son38(T1 son, T2 m) {
		 this->son = son;
		this->m = m;
		cout << "T1 的类型： " << typeid(T1).name() << endl;
		cout << "T2 的类型： " << typeid(T2).name() << endl;
	}
	T1 son;
};


void test38() {
	Son38<int, string> s1(15, "sdfsfd");
	cout << s1.son << "\t" << s1.m << endl;
}