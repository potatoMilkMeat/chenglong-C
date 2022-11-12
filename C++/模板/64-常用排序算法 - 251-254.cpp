#include"public.h"
#include<algorithm>
#include<vector>
#include<ctime>


void printInt2(int v) { cout << v << "  "; }
void printV(const vector<int> &v) {
	for_each(v.begin(), v.end(), printInt2);
	cout << endl;
}
bool sort_2(int v1, int v2) {
	return v1 > v2;
}
// sort
void t_sort() {
	vector<int> v;
	for (int i = 10; i > 0; i--) { v.push_back(i); }
	printV(v);

	sort(v.begin(), v.end());
	printV(v);

	sort(v.begin(), v.end(), sort_2);
	printV(v);
}

// random_shuffle  洗牌
void t_random_shufle() {
	vector<int> v;
	for (int i = 10; i > 0; i--) { v.push_back(i); }
	printV(v);

	random_shuffle(v.begin(), v.end());
	printV(v);
}


// merge // 合并的对象必须是有序序列，顺序还得一致
void t_merge() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	
	vector<int> v2;
	v2.push_back(10); v2.push_back(4); v2.push_back(30); v2.push_back(20);
	sort(v2.begin(), v2.end()); // 转换成有序序列

	vector<int> v3;
	v3.resize(v.size() + v2.size());

	merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	printV(v3);
}


// reverse // 反转
void t_reverse() {
	vector<int> v;
	for (int i = 10; i > 0; i--) { v.push_back(i); }
	printV(v);

	vector<int>::iterator it = v.end();
	int i = 5;
	while (--i) { --it; }
	reverse(v.begin(), it);

	printV(v);
}


void test64() {
	srand((unsigned int)time(NULL));

	//t_sort();
	//t_random_shufle();
	//t_merge();
	t_reverse();
}