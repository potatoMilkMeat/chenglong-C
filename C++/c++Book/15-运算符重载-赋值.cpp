#include "00-main.h"

class Person15 {
public:
	Person15(int age) {
		m_Age = new int(age);
	}
	~Person15()
	{
		if (m_Age != NULL) {
			cout << "���� p ������" << *m_Age << endl;
			delete m_Age;
			m_Age = NULL;
		}
	}
	// ���� ��ֵ�����
	Person15& operator=(Person15 &p) {
		// �������ṩ����ǳ����
		//m_Age = p.m_Age;

		// �ж��Ƿ��������ڶ�������������ͷŸɾ�
		if (m_Age != NULL) { 
			cout << "��ֵ  ���� p ������" << *m_Age << endl;
			delete m_Age; }
		// �����һ������
		m_Age = new int(*p.m_Age);
		return *this;
	}
	int* m_Age;
};

void test15() {
	Person15 p(18);
	Person15 p1(20);
	Person15 p2(30);
	cout << "p ������" << *p.m_Age << endl;
	cout << "p1 ������" << *p1.m_Age << endl;
	cout << "p2 ������" << *p2.m_Age << endl;

	//p1 = p;
	p2 = p1 = p;
	cout << "p1 ������" << *p1.m_Age << endl;
	cout << "p2 ������" << *p2.m_Age << endl;
}
