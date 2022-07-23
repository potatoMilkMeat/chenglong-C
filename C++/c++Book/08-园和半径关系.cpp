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
//	int X; // x����
//	int Y; // ������
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
//	int R; // �뾶
//	Point center; // center
//};

// �жϵ��Բ��ϵ
void isInCircle(Circle &c, Point &p) {
	int x = p.getX();
	int y = p.getY();
	int X = c.getCenter().getX();
	int Y = c.getCenter().getY();
	int R = c.getR();
	int distance = (X - x) * (X - x) + (Y - y) * (Y - y);
	int R_2 = R * R;
	string res = distance < R_2 ? "����" : distance == R_2 ? "��" : "����";
	cout << "��(" << x << ", " << y << ") ��Բ��" << X << ", " << Y << ", " << R << ")" << res << endl;
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