#include "00-main.h"

class Animale26 {
public:
	virtual void speak() = 0; // ���麯��
	// ������
	//virtual ~Animale26() { cout << "Animale26 ������" << endl; }
	
	// ��������
	virtual ~Animale26() = 0;
};
// ���������ĺ�������
Animale26::~Animale26() { cout << "Animale26 ���� ������" << endl; }

class Cat26: public Animale26{
public:
	Cat26(string name) { m_name = new string(name); }
	~Cat26(){
		cout << "Cat26 ������" << endl;
		delete m_name;
	}
	void speak() { cout << *m_name << "è��˵��" << endl; }
	string * m_name;
};

void test26() {
	Animale26* cat = new Cat26("Tom");
	cat->speak();
	delete cat;
}