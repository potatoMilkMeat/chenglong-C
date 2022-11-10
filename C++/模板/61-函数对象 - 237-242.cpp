#include"public.h"
#include<vector>
#include<algorithm>
#include<functional>

// �������� -����
// ���غ������ò��������࣬����󳣱���Ϊ��������
// ��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ�зº���

//  ��ͨ����һ��ʹ�ã��в������з���ֵ
//  ����,�������Լ���״̬
//  �������������Ϊ��������

// ʹ��
class MyAdd {
public:
	int operator() (int x, int y){
		return x + y;
	};
};

// ����״̬
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

// ��������
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

	doPrint(log, "���ǵ�����������,����� ʹ������");
}

// ν��
// ����bool���͵ķº���
// operator ������һ����һԪν��
// operator �����Ƕ�������Ԫν��

// һԪν��
class GreateFive {
public:
	bool operator()(int val) {
		return val > 5;
	};
};

// ��Ԫν��
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

	// GreateFive() ������������
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreateFive());
	// ִ������һ�У��ҵ���һ������5����������7
	//it = find_if(++it, v.end(), GreateFive());
	if (it == v.end()) { cout << "û���ҵ�����5������" << endl;	}
	else { cout << "����5������" << *it << endl; }

	vector<int> v1;
	v1.push_back(10); v1.push_back(40); v1.push_back(30); v1.push_back(50); v1.push_back(20);
	sort(v1.begin(), v1.end());

	printV(v1);
	sort(v1.begin(), v1.end(), MyCompare());
	printV(v1);
}


// �ڽ���������
// STL �ڽ���һЩ��������
// �����º��� ��������
// ȡ�� negate  �� plus    �� minus     �� multiplies    �� divides     ȡģ modulus
void SsFn() {
	negate<int> n;
	plus<int> add;
	plus<string> addStr;
	cout << "ȡ�� negate:  " <<  n(10) << endl;

	cout << "�� plus:  " << add(10, 5) << endl;
	cout << "�� plus:  " << addStr("����", "�й��ˡ�") << endl;
}


// ��ϵ�º��� ��ϵ�Ա�
// ���� equal_to     ������ not_equal_to     ���� greater     ���ڵ��� greater_equal    С�� less    С�ڵ��� less_equal
void GxFn() {
	equal_to<int> a;
	greater<char> b;
	cout << "���ڣ� " << a(5, 5) <<endl;

	cout << "���ڣ� " << b('a', 'b') << endl;
}


// �߼��º���


void test61() {
	//initFn();
	//WeiciFn();
	//SsFn();
	GxFn();
}