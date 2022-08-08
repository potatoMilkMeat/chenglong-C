#include "public.h"
#include <vector>
#include <algorithm>

void print50(int val) { cout << val << endl; }

void test50() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	// while ѭ��
	//vector<int>::iterator itBegin = v.begin();
	//vector<int>::iterator itEnd = v.end();
	//while (itBegin!=itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//forѭ��
	/*for (vector<int>::iterator p = v.begin(); p < v.end(); p++)
	{
		cout << *p << endl;
	}*/

	//algorithm ʹ�õ� for_each
	for_each(v.begin(), v.end(), print50);
}