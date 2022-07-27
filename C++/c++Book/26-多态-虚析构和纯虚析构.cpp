#include "00-main.h"

class Animale26 {
public:
	virtual void speak() = 0; // 纯虚函数
	// 虚析构
	//virtual ~Animale26() { cout << "Animale26 在析构" << endl; }
	
	// 纯虚析构
	virtual ~Animale26() = 0;
};
// 纯虚析构的函数定义
Animale26::~Animale26() { cout << "Animale26 纯虚 在析构" << endl; }

class Cat26: public Animale26{
public:
	Cat26(string name) { m_name = new string(name); }
	~Cat26(){
		cout << "Cat26 在析构" << endl;
		delete m_name;
	}
	void speak() { cout << *m_name << "猫在说话" << endl; }
	string * m_name;
};

void test26() {
	Animale26* cat = new Cat26("Tom");
	cat->speak();
	delete cat;
}