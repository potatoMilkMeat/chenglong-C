#include <iostream>
using namespace std;

int main033() {
	//int arr[10];
	//// ����ռ�ݿռ�
	//cout << "��������ռ�ݿռ�Ϊ" << sizeof(arr) << endl;
	//cout << "����Ԫ��ռ�ݿռ�Ϊ" << sizeof(arr[0]) << endl;
	//cout << "���鳤��" << sizeof(arr) / sizeof(arr[0]) << endl;

	//// �鿴�����׵�ַ
	//cout << "�����׵�ַΪ��" << (int)arr << endl;
	//cout << "�����׵�ַΪ��" << (int)&arr[0] << endl;
	//cout << "����ڶ����׵�ַΪ��" << (int)&arr[1] << endl;

	// ��ά����ռ�ݿռ�
	int arr[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	cout << "��ά����ռ�õĿռ� " << sizeof(arr) << endl;
	cout << "��ά�����һ��ռ�õĿռ� " << sizeof(arr[0]) << endl;
	cout << "��ά�����һ�е�һ��ռ�õĿռ� " << sizeof(arr[0][0]) << endl;
	cout << "��ά�������� " << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "��ά�������� " << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	system("pause");
	return 0;
}