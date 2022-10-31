#include"public.h"
#include <vector>

// 动态扩展 .back()
// 原空间超过后，会找更大的内存空间，然后将原数据拷贝新空间，释放原空间

void printVector(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
		
	}
	cout << endl;
}

// vector 构造函数
void initVector() {
	vector<int> v1; // 默认构造， 无参构造
	for (int i = 0; i < 10; i++) { v1.push_back(i); }

	printVector(v1);

	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	vector<int> v3(10, 100); // 个数，元素
	printVector(v3);

	vector<int> v4(v3);
	printVector(v4);
}

// vector 赋值
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

// vector 容量和大小 empty, capacity, size, resize
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

// vector 插入和删除
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

	v.erase(v.begin()); // 删除
	printVector(v);

	v.erase(v.begin(), v.begin() + 2); // 删除
	printVector(v);
}

// vector 数据存取  at(int idx), front, back
void atVector() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	v[1] = 100;
	printVector(v);

	cout << "at(1): " << v.at(1) << endl;

	cout << "front(): " << v.front() << endl;
	cout << "back(): " << v.back() << endl;
}

// vector 互换容器
// 实际用途，巧用swap可以搜索内存空间
void swapVector() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	printVector(v);

	vector<int> v2;
	for (int i = 10; i > 0; i--) { v2.push_back(i); }
	printVector(v2);

	cout << "交换后：" << endl;
	v.swap(v2);
	printVector(v);
	printVector(v2);

	cout << "v.resize(2)后：" << endl;
	v.resize(2);
	printVector(v);
	cout << "v 大小/容量: " << v.size() << " / " << v.capacity() <<endl;

	cout << "vector<int>(v).swap(v)后：" << endl;
	vector<int>(v).swap(v);
	cout << "v 大小/容量: " << v.size() << " / " << v.capacity() << endl;
}

// vector 预留空间
void reserveVector() {
	vector<int> v;
	// 利用reserve预留空间
	v.reserve(100000); // 没有这句，num是30，有了这句，num是1

	int num = 0; // 开辟空间次数
	int* p = NULL; // 空间首地址

	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}

	cout << "开辟内存空间次数：" << num << endl;
	
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