#include "00-main.h"

class MyPrint
{
public:
	// ��������� �������� - �ֽзº���
	// ��ӡ�����
	void operator() (string text){
		cout << text << endl;
	}
};

// ��ӡ����
void MyPrit02(string text) {
	cout << text << endl;
}

// 
class MyAdd {
public:
	int operator() (int m, int n) {
		return m + n;
	}
};

void test17() {
	MyPrint myPrint;
	myPrint("Hello world! - �º���");
	MyPrit02("Hello world! - MyPrit0202");

	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret = " << ret << endl;
	
	// ������������
	cout << "MyAdd()(10,100) : " << MyAdd()(10,100) << endl;
}