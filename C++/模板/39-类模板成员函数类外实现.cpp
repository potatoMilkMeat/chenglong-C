#include "public.h"

template<class T1, class T2>
class Person39
{
public:
	Person39(T1 name, T2 age);
	/*{
		this->name = name;
		this->age = age;
	};*/
	void show();
	/*{
		cout << "姓名：  " << this->name << "  年龄：  " << this->age << endl;
	}*/
	T1 name;
	T2 age;
};

//39 - 类模板成员函数类外实现
template<class T1, class T2>
Person39<T1, T2>::Person39(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

template<class T1, class T2>
void Person39<T1, T2>::show() { cout << "姓名1：  " << this->name << "  年龄：  " << this->age << endl; }

void test39() {
	Person39<string, int> cl("程龙", 25);
	cl.show();
}