#include <iostream>
#include <string>
using namespace std;

// Բ����
const double PI = 3.14125;

//// ��
//class Circle {
//	// ����Ȩ��
//	// ����Ȩ��
//public:
//	// ����
//	int m_r; // �뾶
//	// ��Ϊ
//	// ��ȡ�ܳ�
//	double calculateZC() {
//		return 2 * PI * m_r;
//	}
//};
//
//// ѧ����
//class Student {
//public:
//	string name;
//	int id;
//
//	void showStudent() {
//		cout << "���� \t" << name << "    ��� \t" << id << endl;
//	}
//
//	void setName(string val) {
//		name = val;
//	}
//	void setId(int val) {
//		id = val;
//	}
//};
//
//// Ȩ�޿���
//class Person {
//public:
//	string name; // ����
//protected:
//	string car; // ������������Է���
//private:
//	int passworld; // ˽�У�ֻ���Լ�����
//
//public:
//	void func() {
//		name = "����";
//		car = "����";
//		passworld = 123456;
//	}
//};
//
//// class Ĭ����˽�� �������Ǵ�����
//// struce Ĭ���ǹ����������Ǵ�ֵ
//
//// ������Ϊ˽�У�
//// ����punlic �����ö�д����
//// ������ֵʱ������У����Ч�� ��������ʾ��
//
//int main07() {
//	//ʵ����
//	Circle cl;
//	// �뾶
//	cl.m_r = 10;
//	cout << cl.calculateZC() << endl;
//
//	Student a;
//	a.name = "chenglong";
//	a.id = 1111;
//	a.showStudent();
//
//	Student b;
//	b.setId(2222);
//	b.setName("bbbb");
//	b.showStudent();
//
//	Person man;
//	man.func();
//
//	cout << man.name << endl;
//
//	system("pause");
//	return 0;
//}