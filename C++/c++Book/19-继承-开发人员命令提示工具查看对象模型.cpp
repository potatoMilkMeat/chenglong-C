#include "00-main.h"

class Father {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Son : private Father {
public:
	int m_d;
};

class GrendSon : public Son {
public:
	int m_d;
};

void test19() {
	GrendSon gs;
	cout << "sizeof(gs) = " << sizeof(gs) << endl;
}

/*
��һ����  vs 2017�Ŀ�����Ա������ʾ��
�ڶ����л���cpp�ļ���·��
������������������
cl /d1 reportSingleClassLayout���� �ļ�.cpp
cl /d1 reportSingleClassLayoutFather "19-�̳�-������Ա������ʾ���߲鿴����ģ��.cpp"
cl /d1 reportSingleClassLayoutSon "19-�̳�-������Ա������ʾ���߲鿴����ģ��.cpp"
cl /d1 reportSingleClassLayoutGrendSon "19-�̳�-������Ա������ʾ���߲鿴����ģ��.cpp"
*/