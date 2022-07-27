#include "00-main.h"

// CPU ������
class AbstractCPU {
public:	virtual void calculate() = 0;
};

// �Կ� ������
class AbstractVideoCard {
public:	virtual void display() = 0;
	~AbstractVideoCard() { cout << "AbstractVideoCard �Ѿ�����" << endl; }
};

// �ڴ� ������
class AbstractMemory {
public:	virtual void storage() = 0;
	  ~AbstractMemory() { cout << "AbstractMemory �Ѿ�����" << endl; }
};

// ������
class Computer {
public:
	Computer(AbstractCPU * cpu, AbstractVideoCard* videoCard, AbstractMemory* memory) {
		m_cpu = cpu;
		m_videoCard = videoCard;
		m_memory = memory;
		cout << "*****************              ��װ��� ****" << endl;
	}
	// ��������
	void work() {
		m_cpu->calculate();
		m_videoCard->display();
		m_memory->storage();
	}
	AbstractCPU* m_cpu;
	AbstractVideoCard* m_videoCard;
	AbstractMemory* m_memory;
};

// inter cpu
class IntelCpu:public AbstractCPU {
public:
	IntelCpu() { cout << "inter CPU �Ѿ���װ" << endl; }
	virtual void calculate() { cout << "inter CPU ��ʼ����" << endl; }
};

// cpu AMD
class AMDCpu :public AbstractCPU {
public:
	AMDCpu() { cout << "AMD CPU �Ѿ���װ" << endl; }
	virtual void calculate() { cout << "AMD CPU ��ʼ����" << endl; }
};

// Nvidia VideoCard
class NvidiaVcd :public AbstractVideoCard {
public:
	NvidiaVcd() { cout << "Nvidia VideoCard �Ѿ���װ" << endl; }
	virtual void display() { cout << "Nvidia VideoCard ��ʼ����" << endl; }
};

// AMD VideoCard
class AMDVcd :public AbstractVideoCard {
public:
	AMDVcd() { cout << "AMD VideoCard �Ѿ���װ" << endl; }
	virtual void display() { cout << "AMD VideoCard ��ʼ����" << endl; }
};

// Kingston Memory
class KingstonMemory :public AbstractMemory {
public:
	KingstonMemory() { cout << "Kingston Memory �Ѿ���װ" << endl; }
	virtual void storage() { cout << "Kingston Memory ��ʼʹ��" << endl; }
};

// Lenovo Memory
class LenovoMemory :public AbstractMemory {
public:
	LenovoMemory() { cout << "Lenovo Memory �Ѿ���װ" << endl; }
	virtual void storage() { cout << "Lenovo Memory ��ʼʹ��" << endl; }
};

void test27() {
	cout << "-----------------  ��1̨  ---------------------" << endl;
	Computer pc_home(new AMDCpu,new AMDVcd, new KingstonMemory);
	pc_home.work();

	cout << "-----------------  ��2̨  ---------------------" << endl;
	Computer pc_home2(new IntelCpu, new NvidiaVcd, new LenovoMemory);
	pc_home2.work();

	cout << "-----------------  ��3̨  ---------------------" << endl;
	Computer pc_home3(new IntelCpu, new NvidiaVcd, new KingstonMemory);
	pc_home3.work();
}
