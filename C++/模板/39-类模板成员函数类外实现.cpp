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
		cout << "������  " << this->name << "  ���䣺  " << this->age << endl;
	}*/
	T1 name;
	T2 age;
};

//39 - ��ģ���Ա��������ʵ��
template<class T1, class T2>
Person39<T1, T2>::Person39(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

template<class T1, class T2>
void Person39<T1, T2>::show() { cout << "����1��  " << this->name << "  ���䣺  " << this->age << endl; }

void test39() {
	Person39<string, int> cl("����", 25);
	cl.show();
}