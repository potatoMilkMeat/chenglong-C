#include "public.h"

//���е�ָ������
void test_P() {
	int* p = new int;
	//*p = 99;
	cout << " p ָ����ڴ��ַ�� " << p << endl;
	cout << " *p ָ���ֵ��" << *p << endl;

	int* pa = new int[5];
	pa[0] = 0;
	pa[1] = 1;
	pa[2] = 10;
	pa[3] = 11;
	pa[4] = 100;
	cout << " pa ָ����ڴ��ַ�� " << pa << endl;
	cout << " pa + 1 ָ����ڴ��ַ�� " << pa + 1 << endl;
	cout << " pa + 3 ָ����ڴ��ַ�� " << pa + 3 << endl;
	cout << " *pa ָ���ֵ��" << *pa << endl;
	cout << " *(pa + 1) ָ���ֵ�� " << *(pa + 1) << endl;
	cout << " *(pa + 3) ָ���ֵ�� " << *(pa + 3) << endl;
	cout << " pa[0] ����0���ֵ��" << pa[0] << endl;
	cout << " pa[2] ����2���ֵ�� " << pa[2] << endl;
	cout << " pa[4] ����4���ֵ�� " << pa[4] << endl;

	int a = *(pa + 3);
	cout << " a ָ����ڴ��ַ�� " << &a << endl;
	cout << " a ֵ�� " << a << endl;

	cout << "============ Tָ������ ============== " << a << endl;

	int** arr = new int* [3];
	arr[0] = new int(8);
	arr[1] = new int(6);
	arr[2] = new int(4);
	cout << " arr ָ����ڴ��ַ�� " << arr << endl;
	cout << " arr + 1 ָ����ڴ��ַ�� " << arr + 1 << endl;

	cout << " *arr ָ��ĵ�ַ��" << *arr << endl;
	cout << " *(arr + 1) ָ��ĵ�ַ�� " << *(arr + 1) << endl;

	cout << " arr[0] ����0��ĵ�ַ��" << arr[0] << endl;
	cout << " arr[1] ����1��ĵ�ַ�� " << arr[1] << endl;

	cout << " **arr ָ��ĵ�ַ��ֵ��" << **arr << endl;
	cout << " **(arr + 1) ָ��ĵ�ַ��ֵ�� " << **(arr + 1) << endl;

	cout << " *arr[0] ����0��ĵ�ַ��ֵ��" << *arr[0] << endl;
	cout << " *arr[1] ����1��ĵ�ַ��ֵ�� " << *arr[1] << endl;
}