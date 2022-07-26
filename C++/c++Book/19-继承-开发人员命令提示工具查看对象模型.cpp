#include "00-main.h"

class Father {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Son : private Father {
public:
	int m_d;
};

class GrendSon : public Son {
public:
	int m_d;
};

void test19() {
	GrendSon gs;
	cout << "sizeof(gs) = " << sizeof(gs) << endl;
}

/*
第一、打开  vs 2017的开发人员命令提示符
第二、切换到cpp文件的路径
第三、输入以下内容
cl /d1 reportSingleClassLayout类名 文件.cpp
cl /d1 reportSingleClassLayoutFather "19-继承-开发人员命令提示工具查看对象模型.cpp"
cl /d1 reportSingleClassLayoutSon "19-继承-开发人员命令提示工具查看对象模型.cpp"
cl /d1 reportSingleClassLayoutGrendSon "19-继承-开发人员命令提示工具查看对象模型.cpp"
*/