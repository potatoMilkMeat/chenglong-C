#include "00-main.h"

// ������
class AbstractCalculator {
public:
	virtual int getResult() { return 0; };
	// ���麯�� - �����࣬�޷�ʵ���������������д���麯������������Ҳ�ǳ�����
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
	cout << "���ǳ���Ķ�̬, ����ָ�������ָ������" << endl;
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

	cout << "�����������ֱ��ʹ��������" << endl;
	DisCalculator dis(100, 20);
	dis.showResult();
}