#include <iostream>
using namespace std;
#include <string>

class Building12;
class Goodfrend12 
{
public:
	Goodfrend12();
	void visit(); // �ιۺ��� ���� Building �е�����
	Building12* building;
};
class Building12 
{
	// ������Ԫ
	friend class Goodfrend12; // Goodfrend12 ����Ԫ�����Է���˽�г�Ա
public:
	Building12();
	string m_SittingRoom; // ����
private:
	string m_BedRoom; // ����
};

// ����д��Ա����
Goodfrend12::Goodfrend12() {
	building = new Building12;
};
Building12::Building12() {
	m_SittingRoom = "����";
	m_BedRoom = "����";
}

void Goodfrend12::visit() {
	cout << "������ȫ�ֺ��� ���ڷ���: " << building->m_SittingRoom << endl;
	cout << "������ȫ�ֺ��� ���ڷ���: " << building->m_BedRoom << endl;
};

void test12_01() {
	Goodfrend12 f;
	f.visit();
}

int main12() {
	test12_01();
	system("pause");
	return 0;
}