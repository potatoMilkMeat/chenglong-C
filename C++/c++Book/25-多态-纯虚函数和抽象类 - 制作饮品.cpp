#include "00-main.h"

// ��Ʒ������
class AbstractDrinking {
public:
	// ��ˮ
	virtual void Boil() { cout << "��ɽȪˮ" << endl; }
	// ����
	virtual void Brew() = 0;
	// ���뱭��
	virtual void PourInCup() { cout << "���뱭��" << endl; }
	// ���븨��
	virtual void PutSomeThing() = 0;
	
	// ������Ʒ
	virtual void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomeThing();
	}
};

// ����
class Coffee: public AbstractDrinking {
public:
	// ��ˮ
	virtual void Boil() { cout << "������ˮ" << endl; }
	// ����
	virtual void Brew() { cout << "����ȸ������" << endl; }
	// ���븨��
	virtual void PutSomeThing() { cout << "�����Ǻ�ţ��" << endl; }
};

// ��
class Tea : public AbstractDrinking {
public:
	// ����
	virtual void Brew() { cout << "���ݱ��ݴ�" << endl; }
	// ���븨��
	virtual void PutSomeThing() { cout << "�������" << endl; }
};

// ��������
void doWork(AbstractDrinking * ad) { 
	ad->makeDrink();
	delete ad;
}

// ִ�е�ʵ�� ���Ͳ�ͬ��ִ�еķ�����ͬ��
void test25() {
	doWork(new Coffee);
	cout << "--------------------------" << endl;
	doWork(new Tea);
}