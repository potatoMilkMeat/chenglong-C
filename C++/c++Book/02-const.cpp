#include <iostream>
#include <string>
using namespace std;
#define Day 7

int main222()
{
	cout << "一周共有：" << Day << " 天" << endl;
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
		if (total == num) cout << num << "是水仙数" << endl;
		num++;
	} while (num<1000);

	// 敲桌子 7的倍数，个位7，十位7
	int arr[100];
	int index = 0;
	for (int i = 0; i < 10; i++)
	{
		arr[index++] = 7 + i * 10; // 个位7    包含 7, 14
		if(i != 7) arr[index++] = 70 + i; // 十位7  // 排除 77
	}
	for (int i = 2; i <= 100/7; i++)
	{
		if (i == 10) i = 12;  // 排除 70 77
		arr[index++] = i * 7; // 7的倍数
	}
	// 打印值
	for (int i = 0; i < index; i++)
	{
		cout << "敲桌子\t" << arr[i] << endl;

	}

	// 乘法口诀
	for (int i = 1; i < 10; i++) // 行
	{
		for (int j = 1; j <= i; j++) // 行内的列
		{
			cout << j << 'x' << i << '=' << i * j <<  "\t";

		}
		cout << endl;
	}

	system("pause");
	return 0;
}