#include"public.h"
#include<set>


// set multiset���� ����
// ����ʱ���Զ�������  ����ʽ�������ײ�ṹ�Ƕ�����ʵ��
// set ���������ظ�Ԫ��
// multiset �������ظ�Ԫ��

// ��ӡ
void printSet(set<int> &s) {
	for (set<int>::iterator it = s.begin(); it != s.end();it++) {
		cout << "  " << *it;
	}
	cout << endl;
}

// ��ӡ
void printMultiSet(multiset<int>&s) {
	for (multiset<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "  " << *it;
	}
	cout << endl;
}


// set���� ����͸�ֵ
void initSet() {
	set<int> s;
	s.insert(5); s.insert(10); s.insert(2); s.insert(1); s.insert(1);
	printSet(s);

	set<int> s2(s);
	printSet(s2);

	set<int>s3;
	s3 = s2;
	printSet(s3);
}

// set���� ��С�ͽ���
void  sizeSet() {
	set<int> s;
	cout << " ��С�� " << s.size() << "    Ϊ�գ� " << s.empty() << endl;
	s.insert(5); s.insert(10); s.insert(2); s.insert(1);

	printSet(s);
	cout << " ��С�� " << s.size() << "    Ϊ�գ� " << s.empty() << endl;

	set<int> s2;
	s2.insert(50); s2.insert(100);
	s.swap(s2);
	printSet(s);
}


// set���� �����ɾ��  clear
void insertSet() {
	set<int> s;
	s.insert(5); s.insert(10); s.insert(2); s.insert(1); s.insert(1);
	printSet(s);

	s.erase(s.begin());
	printSet(s);

	s.erase(10);
	printSet(s);

	s.erase(s.begin(), --s.end());
	printSet(s);
}

// set���� ���Һ�ͳ�� find    count
// find �ҵ� ��������������������ĵ����� end()
// count ���� 0, 1
void findSet() {
	set<int> s;
	s.insert(5); s.insert(10); s.insert(2); s.insert(1); s.insert(1);
	printSet(s);

	set<int>::iterator it;
	it = s.find(5);
	if (it != s.end()) {
		cout << " 5 �ҵ���: " << *it << endl;
	}else cout << " 5 û�ҵ� " << endl;
	
	int num = s.count(5);
	cout << " 5 ͳ�ƴ����� " << num << endl;
}


// ��ӡ pair
void printPair(pair<set<int>::iterator, bool> &ret) {
	if (ret.second) {
		cout << "��һ�β���ɹ� " << endl;
	}
	else {
		cout << "����ʧ�� " << endl;
	}
}

// set���� set �� multiset����
void difSet() {
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	cout << " ������ֵĵ�������" << *(ret.first) << endl;
	printPair(ret);

	ret = s.insert(10);
	printPair(ret);


	multiset<int> ms;
	ms.insert(10); ms.insert(10);
	printMultiSet(ms);
}

// pair���鴴��
// �ɶԳ��ֵ����ݣ����ö�����Է�����������
void initPair() {
	pair<string, int> p("chengl", 20);
	cout << p.first << "  " << p.second << endl;

	pair<string, int> p2 = make_pair("chenglong", 34);
	cout << p2.first << "  " << p2.second << endl;
}


// set�������� - ��������
class MyCompareDef {
public:
	// vs2019 ��C3848������Ҫ�Ѳ����ĳ� const����, ����()������� const ����
	bool operator() (const int& v1, const int& v2) const // �˴����const����
	{
		return v1 > v2;
	}
};
void printSetDef(set<int, MyCompareDef>& s) {
	for (set<int, MyCompareDef>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "  " << *it;
	}
	cout << endl;
}

void sortSet_default() {
	set<int> s1;
	s1.insert(10); s1.insert(20); s1.insert(40); s1.insert(30);
	printSet(s1);

	// ָ���������Ӵ�С
	set<int, MyCompareDef> s2;
	s2.insert(10); s2.insert(20); s2.insert(40); s2.insert(30);
	printSetDef(s2);

}


// set�������� - �Զ�������
// �Զ������ͣ�ָ���������

class Student_d
{
public:
	Student_d(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	};
	string m_name;
	int m_age;
};
class MyCompareStud {
public:
	// vs2019 ��C3848������Ҫ�Ѳ����ĳ� const����, ����()������� const ����
	bool operator() (const Student_d & v1, const Student_d & v2) const // �˴����const����
	{
		return v1.m_age < v2.m_age;
	}
};
void printSetStud(set<Student_d, MyCompareStud>& s) {
	for (set<Student_d, MyCompareStud>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "������" << it->m_name << "     ���䣺" << it->m_age << endl;
	}
}
void sortSet_conf() {
	Student_d p1("����", 24);
	Student_d p2("����", 14);
	Student_d p3("����", 34);
	Student_d p4("����", 54);

	set<Student_d, MyCompareStud> s;
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	printSetStud(s);
}

void test59() {
	//initSet();
	//sizeSet();
	//insertSet();
	//findSet();
	//difSet();
	//initPair();
	//sortSet_default();
	sortSet_conf();
}