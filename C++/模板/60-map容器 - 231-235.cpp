#include"public.h"
#include<map>


void printMap(map<int, int> &m) {
	for (map<int, int>::iterator it= m.begin(); it!= m.end();it++)
	{
		cout << "key = " << (*it).first << "  value = " << it->second << endl;
	}
	cout << endl;
}

// 插入对组，效率高， 比如身份证访问信息
// 二叉树结构存储
// 结构和赋值
void initMap() {
	map<int, int> m;
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));

	printMap(m);

	map<int, int> m2(m);
	printMap(m2);

	map<int, int> m3;
	m3 = m2;
	printMap(m2);
}

// 大小和交换
void sizeMap() {
	map<int, int> m;
	cout << " 大小： " << m.size() << "    为空： " << m.empty() << endl;
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	printMap(m);

	cout << " 大小： " << m.size() << "    为空： " << m.empty() << endl;

	map<int, int> m2;
	m2.insert(pair<int, int>(3, 30));
	m2.insert(pair<int, int>(1, 10));

	m.swap(m2);
	printMap(m);
}

// 插入和删除 erase clear
void insertMap() {
	map<int, int> m;
	m.insert(make_pair(5, 50));

	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	m.insert(map<int, int>::value_type(6, 60));
	m[7] = 70; // 访问的时候，如果没有，会添加默认的值 int对应是 0

	printMap(m);

	m.erase(m.begin());
	m.erase(3); // 删除 key==3 的对组
	m.erase(m.begin(), --m.end());
	printMap(m);
}


// 查找和统计 count
void findMap(){
	map<int, int> m;
	m.insert(make_pair(5, 50));

	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(22, 20));
	m.insert(pair<int, int>(4, 40));

	map<int, int>::iterator it = m.find(2);
	if (it != m.end()) {
		cout << " find: " << it->first << "  : " << it->second << endl;
	}
	else {
		cout << " find没找到" << endl;
	}
	cout << " count: " << m.count(2) <<  endl;

}

// 排序 对key 排序，默认升序
class MyCompareDef {
public:
	// vs2019 报C3848错误，需要把参数改成 const引用, 参数()后面添加 const 修饰
	bool operator() (const int& v1, const int& v2) const // 此处添加const修饰
	{
		return v1 > v2;
	}
};
void printSetDef(map<int,int, MyCompareDef>& s) {
	for (map<int,int, MyCompareDef>::iterator it = s.begin(); it != s.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}
	cout << endl;
}
void sortMap() {
	map<int, int, MyCompareDef> m;
	m.insert(make_pair(5, 50));

	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(22, 20));
	m.insert(pair<int, int>(4, 40));

	printSetDef(m);
}



void test60() {
	//initMap();
	//sizeMap();
	//insertMap();
	//findMap();
	sortMap();
}