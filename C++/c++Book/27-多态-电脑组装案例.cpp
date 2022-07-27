#include "00-main.h"

// CPU 抽象类
class AbstractCPU {
public:	virtual void calculate() = 0;
};

// 显卡 抽象类
class AbstractVideoCard {
public:	virtual void display() = 0;
	~AbstractVideoCard() { cout << "AbstractVideoCard 已经销毁" << endl; }
};

// 内存 抽象类
class AbstractMemory {
public:	virtual void storage() = 0;
	  ~AbstractMemory() { cout << "AbstractMemory 已经销毁" << endl; }
};

// 电脑类
class Computer {
public:
	Computer(AbstractCPU * cpu, AbstractVideoCard* videoCard, AbstractMemory* memory) {
		m_cpu = cpu;
		m_videoCard = videoCard;
		m_memory = memory;
		cout << "*****************              组装完毕 ****" << endl;
	}
	// 工作函数
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
	IntelCpu() { cout << "inter CPU 已经组装" << endl; }
	virtual void calculate() { cout << "inter CPU 开始计算" << endl; }
};

// cpu AMD
class AMDCpu :public AbstractCPU {
public:
	AMDCpu() { cout << "AMD CPU 已经组装" << endl; }
	virtual void calculate() { cout << "AMD CPU 开始计算" << endl; }
};

// Nvidia VideoCard
class NvidiaVcd :public AbstractVideoCard {
public:
	NvidiaVcd() { cout << "Nvidia VideoCard 已经组装" << endl; }
	virtual void display() { cout << "Nvidia VideoCard 开始运算" << endl; }
};

// AMD VideoCard
class AMDVcd :public AbstractVideoCard {
public:
	AMDVcd() { cout << "AMD VideoCard 已经组装" << endl; }
	virtual void display() { cout << "AMD VideoCard 开始运算" << endl; }
};

// Kingston Memory
class KingstonMemory :public AbstractMemory {
public:
	KingstonMemory() { cout << "Kingston Memory 已经组装" << endl; }
	virtual void storage() { cout << "Kingston Memory 开始使用" << endl; }
};

// Lenovo Memory
class LenovoMemory :public AbstractMemory {
public:
	LenovoMemory() { cout << "Lenovo Memory 已经组装" << endl; }
	virtual void storage() { cout << "Lenovo Memory 开始使用" << endl; }
};

void test27() {
	cout << "-----------------  第1台  ---------------------" << endl;
	Computer pc_home(new AMDCpu,new AMDVcd, new KingstonMemory);
	pc_home.work();

	cout << "-----------------  第2台  ---------------------" << endl;
	Computer pc_home2(new IntelCpu, new NvidiaVcd, new LenovoMemory);
	pc_home2.work();

	cout << "-----------------  第3台  ---------------------" << endl;
	Computer pc_home3(new IntelCpu, new NvidiaVcd, new KingstonMemory);
	pc_home3.work();
}
