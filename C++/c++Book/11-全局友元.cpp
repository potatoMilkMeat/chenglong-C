#include <iostream>
using namespace std;
#include <string>

// 建筑物类
class Building
{
	// GoodFriend 全局函数是 友元, 可以访问私有
	friend void GoodFriend(Building* building);

public:
	Building() {
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
	string m_SittingRoom; // 客厅
private:
	string m_BedRoom; // 卧室
};

// 全局函数 friend 
void GoodFriend(Building *building)
{
	cout << "好朋友全局函数 正在访问: " << building->m_SittingRoom << endl;
	cout << "好朋友全局函数 正在访问: " << building->m_BedRoom << endl;
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