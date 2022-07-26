#include "00-main.h"

class Animal {
public:
	int m_age;
};

class Sheep : public Animal {};
class Tuo : public Animal {};

class SheepTuo : public Sheep, public Tuo {};

class Sheep1 : virtual public Animal {}; // Ðé¼Ì³Ð
class Tuo1 : virtual public Animal {}; // Ðé¼Ì³Ð
class SheepTuo1 : public Sheep1, public Tuo1 {};

void test23() {
	SheepTuo s;
	s.Sheep::m_age = 18;
	s.Tuo::m_age = 28;

	cout << "sizeof(s) = " << sizeof(s) << endl;
	
	cout << "Sheep::m_age = " << s.Sheep::m_age << endl;
	cout << "Tuo::m_age = " << s.Tuo::m_age << endl;

	SheepTuo1 s1;
	s1.Sheep1::m_age = 18;
	s1.Tuo1::m_age = 28;
	cout << "***********************  sizeof(s) = " << sizeof(s1) << endl;
	cout << "s1.m_age = " << s1.m_age << endl;
	cout << "s1.Sheep1::m_age = " << s1.Sheep1::m_age << endl;
	cout << "s1.Tuo1::m_age = " << s1.Tuo1::m_age << endl;
}