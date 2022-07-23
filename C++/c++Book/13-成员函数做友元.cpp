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
	friend void GoodFriend13::visit(); // 成员函数 做友元
public:
	Building13();
	string m_SittingRoom; // 客厅
private:
	string m_BedRoom; // 卧室
};

Building13::Building13() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodFriend13::GoodFriend13() {
	building = new Building13;
}
void GoodFriend13::visit() {
	cout << "visit成员函数 正在访问: " << building->m_SittingRoom << endl;
	cout << "visit成员函数 正在访问: " << building->m_BedRoom << endl;
}
void GoodFriend13::visit02() {
	cout << "visit02成员函数 正在访问: " << building->m_SittingRoom << endl;
	cout << "visit02成员函数  sizeof building: " << sizeof *building << "  \t" << sizeof string << endl;
}

void test13_01() {
	GoodFriend13 f;
	f.visit();
	f.visit02();
	cout << "visit02成员函数  sizeof GoodFriend13 " << sizeof GoodFriend13 << endl;
}

int main() {
	test13_01();
	system("pause");
	return 0;
}