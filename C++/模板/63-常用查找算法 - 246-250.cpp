#include"public.h"
#include<vector>
#include<algorithm>

// find
// �ˣ����� == �ж�
class Person {
public:
	bool operator==(const Person& p) {
		return this->m_age == p.m_age && this->m_name == p.m_name;
	};
	Person(string name, int age) {
		this->m_age = age;
		this->m_name = name;
	};
	string m_name;
	int m_age;

};
void t_find() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }

	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end()) { cout << "û�ҵ���" << endl; }
	else { cout << "�ҵ���" << *it << endl; }

	vector<Person> v1;
	Person p1("aaa", 10); v1.push_back(p1);
	Person p2("bbb", 20); v1.push_back(p2);
	Person p3("ccc", 30); v1.push_back(p3);
	Person p4("ddd", 40); v1.push_back(p4);

	Person pp("bbb", 20);
	vector<Person>::iterator it2 = find(v1.begin(), v1.end(), pp);
	if (it2 == v1.end()) { cout << "û�ҵ���" << endl; }
	else { cout << "�ҵ��� ���� " << it2->m_name << "   ���� " << it2->m_age << endl; }
	
}

// find_if
// �������º�����һԪν��
bool greater_5(int val) {
	return val > 5;
}
// �������20�����
class Greater20 {
public:
	bool operator()(const Person &p) {
		return p.m_age > 20;
	}
};
void t_find_if() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }

	vector<int>::iterator it = find_if(v.begin(), v.end(), greater_5);
	if (it == v.end()) { cout << "û�ҵ���" << endl; }
	else { cout << "�ҵ���" << *it << endl; }

	vector<Person> v1;
	Person p1("aaa", 10); v1.push_back(p1);
	Person p2("bbb", 20); v1.push_back(p2);
	Person p3("ccc", 30); v1.push_back(p3);
	Person p4("ddd", 40); v1.push_back(p4);

	vector<Person>::iterator it2 = find_if(v1.begin(), v1.end(), Greater20());
	if (it2 == v1.end()) { cout << "û�ҵ���" << endl; }
	else { cout << "�ҵ��� ���� " << it2->m_name << "   ���� " << it2->m_age << endl; }
}


// adjacent_find ���������ظ�Ԫ��
void t_adjacent_find() {
	vector<int> v;
	v.push_back(0); v.push_back(2);
	v.push_back(0); v.push_back(3);
	v.push_back(1); v.push_back(4);
	v.push_back(3); v.push_back(3);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) { cout << "û�ҵ������ظ�Ԫ�أ�" << endl; }
	else { cout << "�ҵ���" << *it << "   " <<  *(++it) << endl; }
}

// binary_search  ���ֲ���  ����ṹ
// ���ʹ��set,����Ͷ�������
// ���� true  false
void t_binary_search() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	v.push_back(2); // �������У������������ ������Ҳ���9
	sort(v.begin(), v.end()); // ��������󣬽�����ҵ�9

	bool result = binary_search(v.begin(), v.end(), 9);
	cout << "�ҵ���" << result  << endl;
}

// count ��������
void t_count() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	v.push_back(2);
	cout << "�ҵ�������" << count(v.begin(), v.end(), 2) << endl;


	vector<Person> v1;
	Person p1("aaa", 10); v1.push_back(p1);
	Person p2("bbb", 20); v1.push_back(p2);
	Person p3("ccc", 30); v1.push_back(p3);
	Person p4("ddd", 40); v1.push_back(p4);

	Person pp("bbb", 20); v1.push_back(pp);

	cout << "�ҵ�������" << count(v1.begin(), v1.end(), p2) << endl;

}

// count_if ��������
void t_count_if() {
	vector<int> v;
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	cout << "�ҵ�������" << count_if(v.begin(), v.end(), greater_5) << endl;
}

void test63() {
	//t_find();
	//t_find_if();
	//t_adjacent_find();
	//t_binary_search();
	//t_count();
	t_count_if();
}