#include <iostream>
using namespace std;
#include <string>

// ��������
class Building
{
	// GoodFriend ȫ�ֺ����� ��Ԫ, ���Է���˽��
	friend void GoodFriend(Building* building);

public:
	Building() {
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}
	string m_SittingRoom; // ����
private:
	string m_BedRoom; // ����
};

// ȫ�ֺ��� friend 
void GoodFriend(Building *building)
{
	cout << "������ȫ�ֺ��� ���ڷ���: " << building->m_SittingRoom << endl;
	cout << "������ȫ�ֺ��� ���ڷ���: " << building->m_BedRoom << endl;
}

void test11_01() {
	Building b;
	GoodFriend(&b);
}

int main11() {
	test11_01();
	system("pause");
	return 0;
}