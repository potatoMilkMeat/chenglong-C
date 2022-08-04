#include "public.h"

//����ʵ����Ҫ������ �����Ԫ
template<class T1, class T2> class Person41;
template<class T1, class T2> void showPerson2(Person41<T1, T2>& p);


template<class T1, class T2>
class Person41 {
public:
	//������Ԫ
	friend void showPerson(Person41<T1, T2>& p) { cout << "���� - ������" << p.name << "  ���䣺" << p.age << endl; }
	// ������Ԫ - ��ӿյĲ����б�<>, �����Ǻ���ģ��
	friend void showPerson2<>(Person41<T1, T2>& p);
	Person41(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}

private:
	T1 name;
	T2 age;
};

//������Ԫ
template<class T1, class T2>
void showPerson2(Person41<T1, T2>& p) { cout << "���� - ������" << p.name << "  ���䣺" << p.age << endl; }

void test41() {
	Person41<string, int>cl("����", 25);
	showPerson(cl);

	Person41<string, int>ts("��ɮ", 18);
	showPerson2(ts);
}