#include "00-main.h"

class Person14 {
	// ������˽�б����޷�����
	friend ostream& operator<<(ostream& cout, Person14& p); 
	friend Person14 operator+(Person14& p, Person14& p1);
	friend Person14 operator+(Person14& p, int num);
public:
	Person14() {}
	Person14(int a, int b) {
		m_A = a;
		m_B = b;
	}
	//// +���������
	//Person14 operator+(const Person14& p) {
	//	return Person14 (m_A + p.m_A, m_B + p.m_B);
	//}
private:
	int m_A;
	int m_B;
};

// ȫ�ֺ�������+��
Person14 operator+(Person14 &p,Person14 &p1) {
	return Person14(p1.m_A + p.m_A, p1.m_B + p.m_B);
}

// ȫ�ֺ�������+��
Person14 operator+(Person14& p, int num) {
	return Person14(num + p.m_A, num + p.m_B);
}

// << �����������
ostream& operator<<(ostream &cout, Person14 &p) {
	cout << " m_A= " << p.m_A << ";\t m_B= " << p.m_B; // �������
	return cout;
}

void test14() {
	Person14 p(10,11);
	Person14 p1(20, 21);
	cout << p << endl; //cout << p.m_A << '\t' << p.m_B << endl;
	
	Person14 p2;
	p2 = p + p1; // p.operator+(p1); // ȫ���Ǻ��� operator+(p1, p)
	cout << p << endl; //cout << p.m_A << '\t' << p.m_B << endl;

	cout << p2 << endl; // cout << p2.m_A << '\t' << p2.m_B << endl;
	
	p2 = p + 100; // ȫ���Ǻ��� operator+(p1, p)
	cout << p2 << endl; // cout << p2.m_A << '\t' << p2.m_B << endl;
}

class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger p);
public:
	MyInteger(int n) {
		m_num = n;
	}
	// ǰ��++
	MyInteger& operator++() {
		m_num++;
		return *this;
	}
	// ����++
	MyInteger operator++(int) {
		// ����
		MyInteger temp = *this;
		// ++
		m_num++;
		// ���ػ���
		return temp;
	}
private:
	int m_num;
};
// ++�������
ostream& operator<<(ostream& cout, MyInteger p) {
	cout << p.m_num; // ++����
	return cout;
}
void test14_1() {
	MyInteger p(0);
	MyInteger p1(10);

	cout << p << endl;
	cout << ++(++p) << endl;
	cout << p << endl;

	cout << p1 << endl;
	cout << p1++ << endl;
	cout << p1 << endl;
}
