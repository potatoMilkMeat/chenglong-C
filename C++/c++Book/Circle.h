#pragma once
#include "Point.h"
class Circle
{
public:
	void setR(int r);
	void setCenter(Point point);
	Point getCenter();
	int getR();

private:
	int R; // °ë¾¶
	Point center; // center
};