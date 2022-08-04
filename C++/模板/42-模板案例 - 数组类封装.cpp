#include "public.h"
#include "MyArray.hpp"

class Person42 {
public:
	Person42(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void show() { cout << "������ " << this->name << "\t ���䣺 " << this->age << endl; }
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
	cout << "������" << arr.capcity() << "  ��С��" << arr.size() <<  endl;
	arr.setItem(2, 25);

	cout << "ɾ�����һ� " << arr[arr.size() - 1] << endl;
	arr.pop();
	
	arr.show();

	MyArray<int> arr1(3);
	arr1.push(100);
	cout << "arr1 ��һ�� ��ַ�� " << arr1[0] << "  ֵ�� " << arr1.getItem(0) <<  endl;

	arr = arr1;
	cout << "arr = arr1; ��  arr " << endl;
	arr.show();


	cout << endl;
	cout << "========= �Լ��������� " << endl;
	MyArray<Person42> arr2(3);
	Person42 p1("�����", 5);
	Person42 p2("��˽�", 6);
	Person42 p3("��ɮ", 8);
	arr2.push(p1);
	arr2.push(p2);
	arr2.push(p3);
	printPerson(arr2);
}