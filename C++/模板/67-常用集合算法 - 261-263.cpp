#include"public.h"
#include<vector>
#include<set>
#include<algorithm>

void print_Int67(int v) { cout << v << "  "; }
void print_V67(const vector<int>& v) {
	for_each(v.begin(), v.end(), print_Int67);
	cout << endl;
}
// 常用集合算法  必须是有序序列

// set_intersection  集合交集 返回最后一个元素的位置
void t_set_intersection() {
	vector<int> v;
	vector<int> v2;
	for (int i = 0; i < 6; i++) { v.push_back(i); v2.push_back(i+4); }
	cout << "v ： " << endl;
	cout << "============================= " << endl;
	print_V67(v);
	cout << "v2： " << endl;
	cout << "============================= " << endl;
	print_V67(v2);
	

	vector<int> vT;
	vT.resize(min(v.size(), v2.size())); // 交集就是包含时，取最小的值

	vector<int>::iterator end = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), vT.begin());

	cout << "交集： " << endl;
	cout << "============================= " << endl;
	for_each(vT.begin(), end, print_Int67);
	cout << endl;
}

// set_union  集合并集
void t_set_union() {
	vector<int> v;
	vector<int> v2;
	for (int i = 0; i < 6; i++) { v.push_back(i); v2.push_back(i + 4); }
	cout << "v ： " << endl;
	cout << "============================= " << endl;
	print_V67(v);
	cout << "v2： " << endl;
	cout << "============================= " << endl;
	print_V67(v2);


	vector<int> vT;
	vT.resize(v.size() + v2.size()); // 并集就是没相同时，取和

	vector<int>::iterator end = set_union(v.begin(), v.end(), v2.begin(), v2.end(), vT.begin());
	cout << "并集： " << endl;
	cout << "============================= " << endl;
	for_each(vT.begin(), end, print_Int67);
	cout << endl;
}


// set_different 集合差级
void t_set_different() {
	vector<int> v;
	vector<int> v2;
	for (int i = 0; i < 6; i++) { v.push_back(i); v2.push_back(i + 4); }
	cout << "v ： " << endl;
	cout << "============================= " << endl;
	print_V67(v);
	cout << "v2： " << endl;
	cout << "============================= " << endl;
	print_V67(v2);


	vector<int> vT;
	vT.resize(v.size()); // 差集就是没相同时，取第一个的size

	vector<int>::iterator end =  set_difference(v.begin(), v.end(), v2.begin(), v2.end(), vT.begin());
	cout << "差集： " << endl;
	cout << "============================= " << endl;
	for_each(vT.begin(), end, print_Int67);
	cout << endl;

}



void test67() {
	//t_set_intersection();
	//t_set_union();
	t_set_different();
}