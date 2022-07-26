#include "00-main.h"

class BasePage {
public:
	void header() { cout << "这是头部（公共）" << endl; }
	void footer() { cout << "这是底部（公共）" << endl; }
	void left() { cout << "这是左边（公共）" << endl; }
};

class CPP :public BasePage {
public:
	void content() { cout << "这是C++" << endl; }
};

class Java :public BasePage {
public:
	void content() { cout << "这是Java" << endl; }
};
class Python :public BasePage {
public:
	void content() { cout << "这是Python" << endl; }
};

void test18() {
	CPP cpp;
	cpp.header(); cpp.footer(); cpp.left(); cpp.content();

	Java ja;
	ja.header(); ja.footer(); ja.left(); ja.content();

	Python py;
	py.header(); py.footer(); py.left(); py.content();
}