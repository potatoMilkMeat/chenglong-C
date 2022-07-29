#include "public.h"


// �������ν�������
void swapInt30(int &a, int &b) {
	int temp = a;
	a = b;	b = temp;
}
// �������㽻������
void swapDouble30(double& a, double& b) {
	double temp = a;
	a = b;	b = temp;
}

// ����ģ�� - ���ͳ���
template<typename T>
void mySwap30(T &a, T&b) {
	T temp = a;
	a = b;	b = temp;
}

void test30() {
	int a = 1, b = 2;
	double c = 0.1, d = 0.2;

	//swapInt30(a, b);
	//swapDouble30(c, d);
	
	// �Զ��Ƶ� �ǲ�����ʽ����ת��
	// 1�������Ƶ������� int������Ҫ��ͬ
	mySwap30(a, b);

	// ָ������ �ǻ���ʽ����ת��
	// 2����ʾָ������ double; ʹ��ǰ����ȷ������
	mySwap30<double>(c, d);

	cout << a << '\t' << b << endl;
	cout << c << '\t' << d << endl;
}