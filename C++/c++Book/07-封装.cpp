#include <iostream>
#include <string>
using namespace std;

// 圆周率
const double PI = 3.14125;

//// 类
//class Circle {
//	// 访问权限
//	// 公共权限
//public:
//	// 属性
//	int m_r; // 半径
//	// 行为
//	// 获取周长
//	double calculateZC() {
//		return 2 * PI * m_r;
//	}
//};
//
//// 学生类
//class Student {
//public:
//	string name;
//	int id;
//
//	void showStudent() {
//		cout << "姓名 \t" << name << "    编号 \t" << id << endl;
//	}
//
//	void setName(string val) {
//		name = val;
//	}
//	void setId(int val) {
//		id = val;
//	}
//};
//
//// 权限控制
//class Person {
//public:
//	string name; // 公共
//protected:
//	string car; // 保护，子类可以访问
//private:
//	int passworld; // 私有，只能自己访问
//
//public:
//	void func() {
//		name = "姓名";
//		car = "汽车";
//		passworld = 123456;
//	}
//};
//
//// class 默认是私有 ，并且是传引用
//// struce 默认是公共，并且是传值
//
//// 属性设为私有，
//// 采用punlic 来设置读写属性
//// 在设置值时，可以校验有效性 并给出提示。
//
//int main07() {
//	//实例化
//	Circle cl;
//	// 半径
//	cl.m_r = 10;
//	cout << cl.calculateZC() << endl;
//
//	Student a;
//	a.name = "chenglong";
//	a.id = 1111;
//	a.showStudent();
//
//	Student b;
//	b.setId(2222);
//	b.setName("bbbb");
//	b.showStudent();
//
//	Person man;
//	man.func();
//
//	cout << man.name << endl;
//
//	system("pause");
//	return 0;
//}