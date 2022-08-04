#include "public.h"
#include "MyArray.hpp"

class Person42 {
public:
	Person42(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void show() { cout << "姓名： " << this->name << "\t 年龄： " << this->age << endl; }
	string name;
		int age;
};

void printPerson(MyArray<Person42>& arr) {
	for (int i = 0; i < arr.size(); i++)
	{
		Person42 temp = arr.getItem(i);
		temp.show();
	}
}

void test42() {
	MyArray<int> arr(5);
	arr.push(3);
	arr.push(56);
	arr.push(16);
	arr.show();
	cout << "容量：" << arr.capcity() << "  大小：" << arr.size() <<  endl;
	arr.setItem(2, 25);

	cout << "删除最后一项： " << arr[arr.size() - 1] << endl;
	arr.pop();
	
	arr.show();

	MyArray<int> arr1(3);
	arr1.push(100);
	cout << "arr1 第一项 地址： " << arr1[0] << "  值： " << arr1.getItem(0) <<  endl;

	arr = arr1;
	cout << "arr = arr1; 的  arr " << endl;
	arr.show();


	cout << endl;
	cout << "========= 自己建立的类 " << endl;
	MyArray<Person42> arr2(3);
	Person42 p1("孙悟空", 5);
	Person42 p2("猪八戒", 6);
	Person42 p3("唐僧", 8);
	arr2.push(p1);
	arr2.push(p2);
	arr2.push(p3);
	printPerson(arr2);
}