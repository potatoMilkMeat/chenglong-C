#include "00-main.h"

class BasePage {
public:
	void header() { cout << "����ͷ����������" << endl; }
	void footer() { cout << "���ǵײ���������" << endl; }
	void left() { cout << "������ߣ�������" << endl; }
};

class CPP :public BasePage {
public:
	void content() { cout << "����C++" << endl; }
};

class Java :public BasePage {
public:
	void content() { cout << "����Java" << endl; }
};
class Python :public BasePage {
public:
	void content() { cout << "����Python" << endl; }
};

void test18() {
	CPP cpp;
	cpp.header(); cpp.footer(); cpp.left(); cpp.content();

	Java ja;
	ja.header(); ja.footer(); ja.left(); ja.content();

	Python py;
	py.header(); py.footer(); py.left(); py.content();
}