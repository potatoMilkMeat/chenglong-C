#include <iostream>
#include <string>
using namespace std;
#define Day 7

int main222()
{
	cout << "һ�ܹ��У�" << Day << " ��" << endl;
//	string str;
//	cin >> str;
//	cout << "str = " << str << endl;

	int num = 100;
	do
	{
		int z = num % 10;
		int y = num / 10 % 10;
		int x = num / 100;
		int total = x * x * x + y * y * y + z * z * z;
		if (total == num) cout << num << "��ˮ����" << endl;
		num++;
	} while (num<1000);

	// ������ 7�ı�������λ7��ʮλ7
	int arr[100];
	int index = 0;
	for (int i = 0; i < 10; i++)
	{
		arr[index++] = 7 + i * 10; // ��λ7    ���� 7, 14
		if(i != 7) arr[index++] = 70 + i; // ʮλ7  // �ų� 77
	}
	for (int i = 2; i <= 100/7; i++)
	{
		if (i == 10) i = 12;  // �ų� 70 77
		arr[index++] = i * 7; // 7�ı���
	}
	// ��ӡֵ
	for (int i = 0; i < index; i++)
	{
		cout << "������\t" << arr[i] << endl;

	}

	// �˷��ھ�
	for (int i = 1; i < 10; i++) // ��
	{
		for (int j = 1; j <= i; j++) // ���ڵ���
		{
			cout << j << 'x' << i << '=' << i * j <<  "\t";

		}
		cout << endl;
	}

	system("pause");
	return 0;
}