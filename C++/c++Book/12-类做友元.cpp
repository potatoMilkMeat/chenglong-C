#include <iostream>
using namespace std;
#include <string>

class Building12;
class Goodfrend12 
{
public:
	Goodfrend12();
	void visit(); // 参观函数 访问 Building 中的属性
	Building12* building;
};
class Building12 
{
	// 类做友元
	friend class Goodfrend12; // Goodfrend12 是友元，可以访问私有成员
public:
	Building12();
	string m_SittingRoom; // 客厅
private:
	string m_BedRoom; // 卧室
};

// 类外写成员函数
Goodfrend12::Goodfrend12() {
	building = new Building12;
};
Building12::Building12() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

void Goodfrend12::visit() {
	cout << "好朋友全局函数 正在访问: " << building->m_SittingRoom << endl;
	cout << "好朋友全局函数 正在访问: " << building->m_BedRoom << endl;
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