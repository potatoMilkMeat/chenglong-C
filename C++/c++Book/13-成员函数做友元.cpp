#include <iostream>
using namespace std;
#include <string>

class Building13;
class GoodFriend13 {
public:
	GoodFriend13();
	void visit();
	void visit02();
	Building13* building;
};

class Building13 {
	friend void GoodFriend13::visit(); // ��Ա���� ����Ԫ
public:
	Building13();
	string m_SittingRoom; // ����
private:
	string m_BedRoom; // ����
};

Building13::Building13() {
	m_SittingRoom = "����";
	m_BedRoom = "����";
}

GoodFriend13::GoodFriend13() {
	building = new Building13;
}
void GoodFriend13::visit() {
	cout << "visit��Ա���� ���ڷ���: " << building->m_SittingRoom << endl;
	cout << "visit��Ա���� ���ڷ���: " << building->m_BedRoom << endl;
}
void GoodFriend13::visit02() {
	cout << "visit02��Ա���� ���ڷ���: " << building->m_SittingRoom << endl;
	cout << "visit02��Ա����  sizeof building: " << sizeof *building << "  \t" << sizeof string << endl;
}

void test13_01() {
	GoodFriend13 f;
	f.visit();
	f.visit02();
	cout << "visit02��Ա����  sizeof GoodFriend13 " << sizeof GoodFriend13 << endl;
}

int main() {
	test13_01();
	system("pause");
	return 0;
}