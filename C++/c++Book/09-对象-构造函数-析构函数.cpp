#include <iostream>
using namespace std;

// 对象的初始化和清理

class Person
{
public:
	Person();
	~Person();

private:

};

// 有参数，可以重载
Person::Person() {
	cout << "Person 构造函数" << endl;
}
Person::~Person() {
	cout << "Person 析构函数" << endl;
}

void test0000() { Person p; }

int main09() {
	//test0000();
	Person p;
	
	system("pause");
	return 0;
}