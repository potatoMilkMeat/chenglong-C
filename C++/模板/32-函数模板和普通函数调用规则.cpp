#include "public.h"

// 32-ģ�庯������ͨ�������ù���
// 1�����ɵ��ã�������ͨ����
// 2����ģ������б� ǿ�Ƶ��ú���ģ��
// 3������ģ����Է�����������
// 4���������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��

// ��ͨ-1
void myPrient32(int a, int b)
{
	cout << "��ͨ" << endl;
}

// ģ��-2
template<class T>
void myPrient32(T a, T b) {
	cout << "ģ��" << endl;
}

// ģ��-3
template<class T>
void myPrient32(T a, T b, T c) {
	cout << "����ģ��" << endl;
}

// ģ��-4
template<class T>
void myPrient32(T a, char b) {
	cout << "ģ�� ��ƥ�䣬������ʽ����ת��" << endl;
}

void test32() {
	int a = 10, b = 20;
	// Ĭ���Ǻ��������û��ʵ�֣��ᱨ��
	myPrient32(a, b);

	// ��ģ������б� ǿ�Ƶ��ú���ģ��
	myPrient32<>(a, b);

	// ���ظ��ݲ���ƥ��
	myPrient32<>(a, b, 100);

	// ������ƥ��
	myPrient32(a, 'c');
}