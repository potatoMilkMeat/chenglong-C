#include <iostream>
using namespace std;
#include <string>

// ��ָ����ó�Ա����

class Person01
{
public:
	void showClassName() {
		cout << "this is Person Class" << endl;
	}
	void showPersonAge() {
		// ��������Ϊ�����ָ��ΪNULL
		if (this == NULL) return;
		cout << "this is Person Age" << this->m_Age << endl;
	}

	// ������
	// const Person * const this; 
	// �ڳ�Ա��������� const ,���ε���thisָ����ָ��ָ���ֵҲ�������޸�
	void showPerson() const
	{	
		// this ָ��ı��� ��ָ�볣�� Person * const this�� ָ���ָ���ǲ����Ըĵ��
		// this = NULL: 
		//this->m_Age = 100;
		this->m_B = 100;

	}

 	int m_Age;
	mutable int m_B; // �����������ʹ�ڳ������У�Ҳ�����޸����ֵ���ӹؼ��� mutable;
private:

};

void test0001() {
	Person01* p = NULL;
	p->showClassName();
	p->showPersonAge();
}
// ������ const����
void test0002() {
	const Person01 p;
	//p.m_Age = 100; // ��ͨ�Ĳ��ܸı�
	p.m_B = 200; // mutable �������, �ܸı�
	// ������ֻ�ܵ��ó�����
	p.showPerson();
}

int main10() {
	test0001();
	int a = 10;
	// ָ�볣��  ָ��p �̶�
	int* const p = &a; // const ����ָ�룬ָ���ָ��p�̶����� *p ֵ���Ըı�
	// ����ָ��  ָ��*p ֵ �̶�
	const int* p2 = &a; // const ����*p2, ָ���ֵ�̶���ָ�� p2���Ըı䡣

	system("pause");
	return 0;
}