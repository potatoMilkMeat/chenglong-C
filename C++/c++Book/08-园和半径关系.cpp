#include <iostream>
#include <string>
using namespace std;
#include "Point.h"
#include "Circle.h"

//class Point
//{
//public:
//	void setX(int m) { X = m; };
//	void setY(int n) { Y = n; };
//	void setXY(int m, int n) { setX(m); setY(n); };
//	int getX() { return X; };
//	int getY() { return Y; };
//
//private:
//	int X; // x坐标
//	int Y; // 与坐标
//};

//class Circle
//{
//public:
//	void setR(int r) { R = r; };
//	void setCenter(Point point) { center = point; }
//	Point getCenter() { return center; };
//	int getR() { return R; };
//
//private:
//	int R; // 半径
//	Point center; // center
//};

// 判断点和圆关系
void isInCircle(Circle &c, Point &p) {
	int x = p.getX();
	int y = p.getY();
	int X = c.getCenter().getX();
	int Y = c.getCenter().getY();
	int R = c.getR();
	int distance = (X - x) * (X - x) + (Y - y) * (Y - y);
	int R_2 = R * R;
	string res = distance < R_2 ? "里面" : distance == R_2 ? "上" : "外面";
	cout << "点(" << x << ", " << y << ") 在圆（" << X << ", " << Y << ", " << R << ")" << res << endl;
}


int main08() {
	Circle c;
	c.setR(10);
	Point center;
	center.setXY(10, 10);
	c.setCenter(center);

	Point d;
	d.setXY(20, 10);

	isInCircle(c, center);
	isInCircle(c, d);

	system("pause");
	return 0;
}