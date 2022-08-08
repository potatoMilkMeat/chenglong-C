#include "public.h"
#include <vector>
#include <algorithm>

// 内层循环
void printV_(int val) {
	cout << val << " " ;
}

// 外层循环
void printV(vector<int> v) {
	for_each(v.begin(), v.end(), printV_);
	cout << endl;
}
void test52() {
	vector<vector<int>> v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for_each(v.begin(), v.end(), printV);
}