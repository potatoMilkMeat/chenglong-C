#include"public.h"
#include<vector>
#include<algorithm>
#include<functional>

// 函数对象 -概念
// 重载函数调用操作符的类，其对象常被称为函数对象
// 函数对象使用重载的()时，行为类似函数调用，也叫仿函数

//  普通函数一样使用，有参数，有返回值
//  是类,可以有自己的状态
//  函数对象可以作为参数传递

// 使用
class MyAdd {
public:
	int operator() (int x, int y){
		return x + y;
	};
};

// 带有状态
class MyPrint {
public:
	MyPrint() {
		this->count = 0;
	};
	void operator()(string str) {
		this->count++;
		cout << str << endl;
	}
	void logCount() {
		cout << this->count << endl;
	}
	int count;
};

// 当作参数
void doPrint(MyPrint &mp, string str) {
	mp(str);
	mp.logCount();
}

void initFn() {
	MyAdd add;
	cout << "5 + 10 = " << add(5, 10) << endl;

	MyPrint log;
	log("hello world !");
	log("hello world !");
	log("hello world !");
	log.logCount();

	doPrint(log, "这是当做参数传递,并输出 使用总量");
}

// 谓词
// 返回bool类型的仿函数
// operator 参数是一个，一元谓词
// operator 参数是二个，二元谓词

// 一元谓词
class GreateFive {
public:
	bool operator()(int val) {
		return val > 5;
	};
};

// 二元谓词
class MyCompare {
public:
	bool operator()(int v1,int v2) {
		return v1 > v2;
	}
};

void printV(vector<int>&v1) {
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}
void WeiciFn() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }

	// GreateFive() 匿名函数对象
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreateFive());
	// 执行下面一行，找到下一个大于5的数，就是7
	//it = find_if(++it, v.end(), GreateFive());
	if (it == v.end()) { cout << "没有找到大于5的数。" << endl;	}
	else { cout << "大于5的数：" << *it << endl; }

	vector<int> v1;
	v1.push_back(10); v1.push_back(40); v1.push_back(30); v1.push_back(50); v1.push_back(20);
	sort(v1.begin(), v1.end());

	printV(v1);
	sort(v1.begin(), v1.end(), MyCompare());
	printV(v1);
}


// 内建函数对象
// STL 内建了一些函数对象
// 算术仿函数 四则运算
// 取反 negate  加 plus    减 minus     乘 multiplies    除 divides     取模 modulus
void SsFn() {
	negate<int> n;
	plus<int> add;
	plus<string> addStr;
	cout << "取反 negate:  " <<  n(10) << endl;

	cout << "加 plus:  " << add(10, 5) << endl;
	cout << "加 plus:  " << addStr("我是", "中国人。") << endl;
}


// 关系仿函数 关系对比
// 等于 equal_to     不等于 not_equal_to     大于 greater     大于等于 greater_equal    小于 less    小于等于 less_equal
void GxFn() {
	equal_to<int> a;
	greater<char> b;
	cout << "等于： " << a(5, 5) <<endl;

	cout << "大于： " << b('a', 'b') << endl;
}


// 逻辑仿函数


void test61() {
	//initFn();
	//WeiciFn();
	//SsFn();
	GxFn();
}