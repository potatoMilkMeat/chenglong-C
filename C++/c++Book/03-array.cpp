#include <iostream>
using namespace std;

int main033() {
	//int arr[10];
	//// 数组占据空间
	//cout << "整个数组占据空间为" << sizeof(arr) << endl;
	//cout << "数组元素占据空间为" << sizeof(arr[0]) << endl;
	//cout << "数组长度" << sizeof(arr) / sizeof(arr[0]) << endl;

	//// 查看数据首地址
	//cout << "数组首地址为：" << (int)arr << endl;
	//cout << "数组首地址为：" << (int)&arr[0] << endl;
	//cout << "数组第二个首地址为：" << (int)&arr[1] << endl;

	// 二维数组占据空间
	int arr[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	cout << "二维数组占用的空间 " << sizeof(arr) << endl;
	cout << "二维数组第一行占用的空间 " << sizeof(arr[0]) << endl;
	cout << "二维数组第一行第一列占用的空间 " << sizeof(arr[0][0]) << endl;
	cout << "二维数组行数 " << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组列数 " << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	system("pause");
	return 0;
}