#include "00-main.h"

// 抽象类
class AbstractCalculator {
public:
	virtual int getResult() { return 0; };
	// 纯虚函数 - 抽象类，无法实例化，子类必须重写纯虚函数，否则子类也是抽象类
	// virtual int getResult() = 0;
	virtual void showResult() { cout << m_x << ' ' << oper << ' ' << m_y << " = " << getResult() << endl; };
	int m_x;
	int m_y;
	char oper;
};

// +
class AddCalculator : public AbstractCalculator {
public:
	AddCalculator(int x, int y) { oper = '+'; m_x = x; m_y = y; }
	virtual int getResult() { return m_x + m_y; }
};
// -
class SubCalculator : public AbstractCalculator {
public:
	SubCalculator(int x, int y) { oper = '-'; m_x = x; m_y = y; }
	virtual int getResult() { return m_x - m_y; }
};
// *
class MulCalculator : public AbstractCalculator {
public:
	MulCalculator(int x, int y) { oper = '*'; m_x = x; m_y = y; }
	virtual int getResult() { return m_x * m_y; }
};
// /
class DisCalculator : public AbstractCalculator {
public:
	DisCalculator(int x, int y) { oper = '/'; m_x = x; m_y = y; }
	virtual int getResult() { return m_x / m_y; }
};

void test24() {
	cout << "这是抽象的多态, 父类指针或引用指向子类" << endl;
	AbstractCalculator* ab = new AddCalculator(10, 10);
	ab->showResult();
	delete ab;

	ab = new SubCalculator(50, 20);
	ab->showResult();
	delete ab;

	ab = new MulCalculator(5, 9);
	ab->showResult();
	delete ab;

	ab = new DisCalculator(100, 5);
	ab->showResult();
	delete ab;

	cout << "这是子类对象直接使用自身方法" << endl;
	DisCalculator dis(100, 20);
	dis.showResult();
}