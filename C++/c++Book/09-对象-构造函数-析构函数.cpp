#include <iostream>
using namespace std;

// ����ĳ�ʼ��������

class Person
{
public:
	Person();
	~Person();

private:

};

// �в�������������
Person::Person() {
	cout << "Person ���캯��" << endl;
}
Person::~Person() {
	cout << "Person ��������" << endl;
}

void test0000() { Person p; }

int main09() {
	//test0000();
	Person p;
	
	system("pause");
	return 0;
}