#include "Point.h"

void Point::setX(int m) { X = m; };
void Point::setY(int n) { Y = n; };
void Point::setXY(int m, int n) { setX(m); setY(n); };
int Point::getX() { return X; };
int Point::getY() { return Y; };