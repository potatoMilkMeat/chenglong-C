#include "public.h"

// ��ģ��ͺ���ģ�������
// ��ģ��û���Զ����͵��Ƶ�
// ��ģ����������͵�Ĭ�ϲ���

template<class NameT,class AgeT = int> // ��ģ�������Ĭ�ϲ���  class AgeT = int
class Person35{
public:
	Person35(NameT name, AgeT age = 1) {
		this->name = name;
		this->age = age;
	}
	void showPerson() {
		cout << "������ " << name << " \t ���䣺 " << age << endl;
	}
	NameT name;
	AgeT age;
};



void test35() {
	// ��ģ��û���Զ����͵��Ƶ�
	//Person35("�����", 1000);
	Person35<string, int>swk("�����", 1000);
	swk.showPerson();

	Person35<string>zbj("��˽�",888);
	zbj.showPerson();
}
