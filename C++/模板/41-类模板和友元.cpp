#include "public.h"

//内外实现需要先申明 类和友元
template<class T1, class T2> class Person41;
template<class T1, class T2> void showPerson2(Person41<T1, T2>& p);


template<class T1, class T2>
class Person41 {
public:
	//类内友元
	friend void showPerson(Person41<T1, T2>& p) { cout << "类内 - 姓名：" << p.name << "  年龄：" << p.age << endl; }
	// 类外友元 - 添加空的参数列表<>, 表明是函数模板
	friend void showPerson2<>(Person41<T1, T2>& p);
	Person41(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}

private:
	T1 name;
	T2 age;
};

//类外友元
template<class T1, class T2>
void showPerson2(Person41<T1, T2>& p) { cout << "类外 - 姓名：" << p.name << "  年龄：" << p.age << endl; }

void test41() {
	Person41<string, int>cl("程龙", 25);
	showPerson(cl);

	Person41<string, int>ts("唐僧", 18);
	showPerson2(ts);
}