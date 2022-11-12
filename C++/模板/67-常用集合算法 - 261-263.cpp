#include"public.h"
#include<vector>
#include<set>
#include<algorithm>

void print_Int67(int v) { cout << v << "  "; }
void print_V67(const vector<int>& v) {
	for_each(v.begin(), v.end(), print_Int67);
	cout << endl;
}
// ���ü����㷨  ��������������

// set_intersection  ���Ͻ��� �������һ��Ԫ�ص�λ��
void t_set_intersection() {
	vector<int> v;
	vector<int> v2;
	for (int i = 0; i < 6; i++) { v.push_back(i); v2.push_back(i+4); }
	cout << "v �� " << endl;
	cout << "============================= " << endl;
	print_V67(v);
	cout << "v2�� " << endl;
	cout << "============================= " << endl;
	print_V67(v2);
	

	vector<int> vT;
	vT.resize(min(v.size(), v2.size())); // �������ǰ���ʱ��ȡ��С��ֵ

	vector<int>::iterator end = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), vT.begin());

	cout << "������ " << endl;
	cout << "============================= " << endl;
	for_each(vT.begin(), end, print_Int67);
	cout << endl;
}

// set_union  ���ϲ���
void t_set_union() {
	vector<int> v;
	vector<int> v2;
	for (int i = 0; i < 6; i++) { v.push_back(i); v2.push_back(i + 4); }
	cout << "v �� " << endl;
	cout << "============================= " << endl;
	print_V67(v);
	cout << "v2�� " << endl;
	cout << "============================= " << endl;
	print_V67(v2);


	vector<int> vT;
	vT.resize(v.size() + v2.size()); // ��������û��ͬʱ��ȡ��

	vector<int>::iterator end = set_union(v.begin(), v.end(), v2.begin(), v2.end(), vT.begin());
	cout << "������ " << endl;
	cout << "============================= " << endl;
	for_each(vT.begin(), end, print_Int67);
	cout << endl;
}


// set_different ���ϲ
void t_set_different() {
	vector<int> v;
	vector<int> v2;
	for (int i = 0; i < 6; i++) { v.push_back(i); v2.push_back(i + 4); }
	cout << "v �� " << endl;
	cout << "============================= " << endl;
	print_V67(v);
	cout << "v2�� " << endl;
	cout << "============================= " << endl;
	print_V67(v2);


	vector<int> vT;
	vT.resize(v.size()); // �����û��ͬʱ��ȡ��һ����size

	vector<int>::iterator end =  set_difference(v.begin(), v.end(), v2.begin(), v2.end(), vT.begin());
	cout << "��� " << endl;
	cout << "============================= " << endl;
	for_each(vT.begin(), end, print_Int67);
	cout << endl;

}



void test67() {
	//t_set_intersection();
	//t_set_union();
	t_set_different();
}