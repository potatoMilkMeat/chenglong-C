#include"public.h"
#include<algorithm> // ���ң�����
#include<functional> // ���÷º���
#include<vector>

// �����㷨 for_each  transform
void printInt(int val){
	cout << val << "  ";
}

void for_each_1(){
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), printInt);
	cout << endl;
}

class TransformClass {
public:
	int operator()(int v) {
		return v * 10;
	}
};

void transform_2() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), printInt);
	cout << endl;

	vector<int> v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), TransformClass());
	for_each(v2.begin(), v2.end(), printInt);
	cout << endl;
}

void test62() {
	//for_each_1();
	transform_2();
}
