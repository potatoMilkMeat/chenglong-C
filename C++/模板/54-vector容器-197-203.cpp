#include"public.h"
#include <vector>

// ��̬��չ .back()
// ԭ�ռ䳬���󣬻��Ҹ�����ڴ�ռ䣬Ȼ��ԭ���ݿ����¿ռ䣬�ͷ�ԭ�ռ�

void printVector(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
		
	}
	cout << endl;
}

// vector ���캯��
void initVector() {
	vector<int> v1; // Ĭ�Ϲ��죬 �޲ι���
	for (int i = 0; i < 10; i++) { v1.push_back(i); }

	printVector(v1);

	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	vector<int> v3(10, 100); // ������Ԫ��
	printVector(v3);

	vector<int> v4(v3);
	printVector(v4);
}

// vector ��ֵ
void assignVector() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) { v1.push_back(i); }

	vector<int> v2;
	v2 = v1;
	printVector(v2);

	vector<int> v3;
	v3.assign(v1.begin(), v1.begin()+3);
	printVector(v3);

	vector<int> v4;
	v4.assign(10, 100);
	printVector(v4);
}

// vector �����ʹ�С empty, capacity, size, resize
void sizeVector() {
	vector<int> v;
	cout << v.empty() << "  " << v.capacity() << "  " << v.size() << endl;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	printVector(v);
	cout << v.empty() << "  " << v.capacity() << "  " << v.size() << endl;

	v.resize(20);
	printVector(v);
	cout << v.empty() << "  " << v.capacity() << "  " << v.size() << endl;

	v.resize(13);
	printVector(v);
	cout << v.empty() << "  " << v.capacity() << "  " << v.size() << endl;

	v.resize(20, 100);
	printVector(v);
	cout << v.empty() << "  " << v.capacity() << "  " << v.size() << endl;
}

// vector �����ɾ��
void insertVector() {
	vector<int> v;
	for (int i = 0; i < 4; i++) { v.push_back(i); }
	printVector(v);

	v.pop_back();
	printVector(v);

	v.insert(v.begin(), 100);
	printVector(v);

	v.insert(v.begin(),2, 1000);
	printVector(v);

	v.erase(v.begin()); // ɾ��
	printVector(v);

	v.erase(v.begin(), v.begin() + 2); // ɾ��
	printVector(v);
}

// vector ���ݴ�ȡ  at(int idx), front, back
void atVector() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	v[1] = 100;
	printVector(v);

	cout << "at(1): " << v.at(1) << endl;

	cout << "front(): " << v.front() << endl;
	cout << "back(): " << v.back() << endl;
}

// vector ��������
// ʵ����;������swap���������ڴ�ռ�
void swapVector() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	printVector(v);

	vector<int> v2;
	for (int i = 10; i > 0; i--) { v2.push_back(i); }
	printVector(v2);

	cout << "������" << endl;
	v.swap(v2);
	printVector(v);
	printVector(v2);

	cout << "v.resize(2)��" << endl;
	v.resize(2);
	printVector(v);
	cout << "v ��С/����: " << v.size() << " / " << v.capacity() <<endl;

	cout << "vector<int>(v).swap(v)��" << endl;
	vector<int>(v).swap(v);
	cout << "v ��С/����: " << v.size() << " / " << v.capacity() << endl;
}

// vector Ԥ���ռ�
void reserveVector() {
	vector<int> v;
	// ����reserveԤ���ռ�
	v.reserve(100000); // û����䣬num��30��������䣬num��1

	int num = 0; // ���ٿռ����
	int* p = NULL; // �ռ��׵�ַ

	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}

	cout << "�����ڴ�ռ������" << num << endl;
	
}


void test54() {
	//initVector();
	//assignVector();
	//sizeVector();
	//insertVector();
	//atVector();
	//swapVector();
	reserveVector();
}