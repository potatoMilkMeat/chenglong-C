#include <iostream>
using namespace std;

// ����ĳ�ʼ��������
class Base09{
public:
	Base09() { cout << "Base09 ���캯��" << endl; }
	~Base09() { cout << "Base09 ��������" << endl; }
};


class Person09 {
public:
	Person09();
	~Person09();
	Base09 m_base;
};


// �в�������������
Person09::Person09() {
	cout << "Person ���캯��" << endl;
}
Person09::~Person09() {
	cout << "Person ��������" << endl;
}

void test09() { Person09 p; }

