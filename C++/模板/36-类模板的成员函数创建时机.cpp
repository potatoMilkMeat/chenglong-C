#include "public.h"

// ��ģ��ĳ�Ա����. ������һ��ʼ�ʹ����ģ�������ģ�����ʱ������
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
	//m.func2();  Person36_2 ����ʹ��
}