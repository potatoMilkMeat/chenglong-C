#include "public.h"

//堆中的指针数组
void test_P() {
	int* p = new int;
	//*p = 99;
	cout << " p 指针的内存地址： " << p << endl;
	cout << " *p 指针的值：" << *p << endl;

	int* pa = new int[5];
	pa[0] = 0;
	pa[1] = 1;
	pa[2] = 10;
	pa[3] = 11;
	pa[4] = 100;
	cout << " pa 指针的内存地址： " << pa << endl;
	cout << " pa + 1 指针的内存地址： " << pa + 1 << endl;
	cout << " pa + 3 指针的内存地址： " << pa + 3 << endl;
	cout << " *pa 指针的值：" << *pa << endl;
	cout << " *(pa + 1) 指针的值： " << *(pa + 1) << endl;
	cout << " *(pa + 3) 指针的值： " << *(pa + 3) << endl;
	cout << " pa[0] 数组0项的值：" << pa[0] << endl;
	cout << " pa[2] 数组2项的值： " << pa[2] << endl;
	cout << " pa[4] 数组4项的值： " << pa[4] << endl;

	int a = *(pa + 3);
	cout << " a 指针的内存地址： " << &a << endl;
	cout << " a 值： " << a << endl;

	cout << "============ T指针数组 ============== " << a << endl;

	int** arr = new int* [3];
	arr[0] = new int(8);
	arr[1] = new int(6);
	arr[2] = new int(4);
	cout << " arr 指针的内存地址： " << arr << endl;
	cout << " arr + 1 指针的内存地址： " << arr + 1 << endl;

	cout << " *arr 指针的地址：" << *arr << endl;
	cout << " *(arr + 1) 指针的地址： " << *(arr + 1) << endl;

	cout << " arr[0] 数组0项的地址：" << arr[0] << endl;
	cout << " arr[1] 数组1项的地址： " << arr[1] << endl;

	cout << " **arr 指针的地址的值：" << **arr << endl;
	cout << " **(arr + 1) 指针的地址的值： " << **(arr + 1) << endl;

	cout << " *arr[0] 数组0项的地址的值：" << *arr[0] << endl;
	cout << " *arr[1] 数组1项的地址的值： " << *arr[1] << endl;
}