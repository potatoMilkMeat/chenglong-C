#include "public.h"

//38 - ��ģ��ͼ̳�
template<class T>
class Base38 {
public:
	//Base38(T m) { this->m = m; }
	//void show() { count << "Base38��  " << m; }
	T m;
};

// �����������ģ�壬������Ҫָ������� ���ͣ����߳�Ϊ��ģ�岢ָ��
template<class T1, class T2>
class Son38 : public Base38<T2> {
public:
	Son38(T1 son, T2 m) {
		 this->son = son;
		this->m = m;
		cout << "T1 �����ͣ� " << typeid(T1).name() << endl;
		cout << "T2 �����ͣ� " << typeid(T2).name() << endl;
	}
	T1 son;
};


void test38() {
	Son38<int, string> s1(15, "sdfsfd");
	cout << s1.son << "\t" << s1.m << endl;
}