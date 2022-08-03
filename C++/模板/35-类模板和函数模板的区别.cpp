#include "public.h"

// 类模板和函数模板的区别
// 类模板没有自动类型的推导
// 类模板可以有类型的默认参数

template<class NameT,class AgeT = int> // 类模板可以有默认参数  class AgeT = int
class Person35{
public:
	Person35(NameT name, AgeT age = 1) {
		this->name = name;
		this->age = age;
	}
	void showPerson() {
		cout << "姓名： " << name << " \t 年龄： " << age << endl;
	}
	NameT name;
	AgeT age;
};



void test35() {
	// 类模板没有自动类型的推导
	//Person35("孙悟空", 1000);
	Person35<string, int>swk("孙悟空", 1000);
	swk.showPerson();

	Person35<string>zbj("猪八戒",888);
	zbj.showPerson();
}
