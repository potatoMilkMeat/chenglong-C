#include "public.h"

// ��ģ������������
template<class T1, class T2 >
class Person37 {
public:
	Person37(T1 name, T2 age) {
		this->name = name;
		this->age = age;
		cout << "T1 �����ͣ�" << typeid(T1).name() << endl;
		cout << "T2 �����ͣ�" << typeid(T2).name() << endl;
	}
	void showPerson() {
		cout << "������ " << name << "  ���䣺 " << age << endl;
	}
	T1 name;
	T2 age;
};

//ָ���������� - ֻ������һ��
void printPerson(Person37<string, int>& p) { p.showPerson(); }

//����ģ�廯 - �����������
template<class T1, class T2>
void printPerson(Person37<T1, T2>& p) {
	p.showPerson();
}

//������ģ�廯 - ʹ�õ�ʱ���֪����ʲôģ��
template<class T>
void printPerson2(T &p) {
	p.showPerson();
	cout << "T �����ͣ�" << typeid(T).name() << endl;

}

void test37() {
	
	Person37<string, int> cl("����", 34);
	// ��ֱ��ʹ��
	//cl.showPerson();

	printPerson(cl);

	Person37<char, int> ts('t', 1001);
	printPerson(ts);

	Person37<string, int> swk("�����", 999);
	printPerson2(swk);
}