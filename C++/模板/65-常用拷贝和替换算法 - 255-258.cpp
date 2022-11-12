#include"public.h"
#include<vector>
#include<algorithm>

// copy
void print_Int(int v) { cout << v << "  "; }
void print_V(const vector<int>& v) {
	for_each(v.begin(), v.end(), print_Int);
	cout << endl;
}
void t_copy() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	
	vector<int> v2;
	v2.resize(v.size());
	copy(v.begin(),v.end(), v2.begin());
	print_V(v2);
}

// replace 替换全部
void t_replace() {
	vector<int> v;
	for (int i = 0; i < 5; i++) { v.push_back(i); v.push_back(i+2);}
	sort(v.begin(), v.end());
	print_V(v);

	replace(v.begin(), v.end(), 3, 300);
	print_V(v);
}

bool greate_equal_4(int val) {
	return val >= 4;
}
// replace_if
void t_replace_if() {
	vector<int> v;
	for (int i = 0; i < 5; i++) { v.push_back(i); v.push_back(i + 2); }
	sort(v.begin(), v.end());
	print_V(v);

	replace_if(v.begin(), v.end(), greate_equal_4, 3000);
	print_V(v);
}

// swap 互换两个容器的元素，需要容器类型相同
void t_swap() {
	vector<int> v;
	vector<int> v2;
	for (int i = 0; i < 5; i++) { v.push_back(i); v2.push_back(i * 100); }
	swap(v, v2);
	print_V(v);
	print_V(v2);
}


void test65() {
	//t_copy();
	//t_replace();
	//t_replace_if();
	t_swap();
}