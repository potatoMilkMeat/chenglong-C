#include <iostream>
using namespace std;

void msg(int* p);
// ������������������
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main66() {
	int a = 10;

	int& b = a;
	// ���� - �����ʼ���������ٸı䡣
	// ָ������ĸ����Ǳ����� ���Դ洢��ָ���ַ��ֵ���ǿ�����ʱ�ı�ġ�

	msg(&a);
	msg(&b);

	a = 100;
	msg(&a);
	msg(&b);

	b = 200; // ��ʵ�Ǹ�ֵ�����������Ǹı�����  int c = 200;b = c;
	msg(&a);
	msg(&b);

	// ������������������
	cout << "������������������" << endl;
	int d = 99;
	mySwap03(a, d);
	msg(&a);
	msg(&d);


	system("pause");
	return 0;
}