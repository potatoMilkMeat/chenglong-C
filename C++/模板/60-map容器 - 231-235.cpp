#include"public.h"
#include<map>


void printMap(map<int, int> &m) {
	for (map<int, int>::iterator it= m.begin(); it!= m.end();it++)
	{
		cout << "key = " << (*it).first << "  value = " << it->second << endl;
	}
	cout << endl;
}

// ������飬Ч�ʸߣ� �������֤������Ϣ
// �������ṹ�洢
// �ṹ�͸�ֵ
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

// ��С�ͽ���
void sizeMap() {
	map<int, int> m;
	cout << " ��С�� " << m.size() << "    Ϊ�գ� " << m.empty() << endl;
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	printMap(m);

	cout << " ��С�� " << m.size() << "    Ϊ�գ� " << m.empty() << endl;

	map<int, int> m2;
	m2.insert(pair<int, int>(3, 30));
	m2.insert(pair<int, int>(1, 10));

	m.swap(m2);
	printMap(m);
}

// �����ɾ�� erase clear
void insertMap() {
	map<int, int> m;
	m.insert(make_pair(5, 50));

	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	m.insert(map<int, int>::value_type(6, 60));
	m[7] = 70; // ���ʵ�ʱ�����û�У������Ĭ�ϵ�ֵ int��Ӧ�� 0

	printMap(m);

	m.erase(m.begin());
	m.erase(3); // ɾ�� key==3 �Ķ���
	m.erase(m.begin(), --m.end());
	printMap(m);
}


// ���Һ�ͳ�� count
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
		cout << " findû�ҵ�" << endl;
	}
	cout << " count: " << m.count(2) <<  endl;

}

// ���� ��key ����Ĭ������
class MyCompareDef {
public:
	// vs2019 ��C3848������Ҫ�Ѳ����ĳ� const����, ����()������� const ����
	bool operator() (const int& v1, const int& v2) const // �˴����const����
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