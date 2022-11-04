#include"public.h"
#include<list>

// list ���� - �������Ĵ洢�ṹ�������нṹ˳����ͨ�������е�ָ������ʵ�ֵ�
// ������λ�ý��п��ٲ����ɾ������̬�洢���䣬��������ڴ��˷Ѻ����
// ȱ�㣺
// �����ı����ٶȣ�û������졣
// ռ�ÿռ�������

void printList(const list<int>&l) {
	for (list<int>::const_iterator it =l.begin(); it != l.end(); it++) {
		cout << " " << (*it);
	}
	cout << endl;
}

// list ����
void initList() {
	list<int> l;
	for (int i = 0; i < 10; i++) { l.push_back(i);	}
	printList(l);

	// ֧��it--, ���ǲ�֧�� it = it - 4;
	list<int>::iterator it = l.end();
	for (int i = 0; i < 4; i++)
	{
		it = --it;
	}
	list<int> l2(l.begin(), it);
	printList(l2);

	list<int> l3(4, 100);
	printList(l3);

	list<int> l4(l3);
	printList(l4);
}

// list ��ֵ�ͽ��� swap
void assignList() {
	list<int> l(4, 100);

	list<int> l2 = l;
	printList(l2);

	cout << "����ǰ�� " << endl;
	list<int> l3;
	l3.assign(l.begin(), --l.end());
	printList(l3);

	list<int> l4;
	for (int i = 0; i < 10; i++) { l4.push_back(i); }
	printList(l4);

	cout << "������ " << endl;
	l3.swap(l4);
	printList(l3);
	printList(l4);
}

// list ��С���� size empty resize
void sizeList() {
	list<int> l;
	cout << "��С: " << l.size() << "Ϊ��: " << l.empty() << endl;
	for (int i = 0; i < 10; i++) { l.push_back(i); }
	printList(l);
	cout << "��С: " << l.size() << "Ϊ��: " << l.empty() << endl;

	l.resize(13);

	l.resize(20, -100);
	printList(l);
	cout << "��С: " << l.size() << "Ϊ��: " << l.empty() << endl;
}

// list �����ɾ��
void insertList() {
	list<int> l;
	l.push_back(10); l.push_back(20); l.push_back(30);
	l.push_front(-10); l.push_front(-20);
	printList(l);

	l.pop_back(); l.pop_front();
	printList(l);

	l.insert(++l.begin(), 50);
	l.insert(++l.begin(), 3, 99);
	printList(l);

	list<int> l4;
	for (int i = 0; i < 10; i++) { l4.push_back(i); }

	l.insert(++l.begin(), l4.begin(), l4.end());
	printList(l);

	l.remove(99);
	printList(l);

	list<int>::iterator p = l.erase(++l.begin());
	printList(l);
	cout << "erase ɾ����ָ�룺 " << *p << endl;

	l.erase(l.begin(), l.end());
	cout << "erase(l.begin(), l.end()) ɾ���� ";
	cout << "Ϊ�գ�" << l.empty() << endl;
}

// list ���ݴ�ȡ ֧��˫�򣬲�֧���������
void seeList() {
	list<int> l;
	for (int i = 0; i < 10; i++) { l.push_back(i); }
	printList(l);
	cout << "ͷ��Ԫ�أ�" << l.front() << "   β��Ԫ�أ�" << l.back() << endl;

	list<int>::iterator it = l.begin();

	// ֧��˫��
	int i = 3;
	while (--i)	{ it++;	}
	cout << "�� 3 + beginԪ�أ�" << *it << endl;
}

// list �����  ���� 
// ��Ϊ��֧���������, ����ʹ��ͨ�õ�sort(begin, end)
// �Դ�sort����
bool myCompare(int v1, int v2) {
	return v1 > v2;
}
void sortList() {
	list<int> l;
	for (int i = 0; i < 10; i++) { l.push_back(i); }
	printList(l);
	l.reverse();
	printList(l);

	l.sort();
	printList(l);

	// �����ṩ����- ���߱ȽϽṹ��Ķ���
	l.sort(myCompare);
	printList(l);
}

// ѧ��
class Student {
public:
	Student(string name, int age, int height) {
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}
	string m_name;
	int m_age;
	int m_height;
};

// ��ӡѧ��
void printList(const list<Student>& l) {
	for (list<Student>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << "������ " << (*it).m_name << "  ���䣺 " << it->m_age << "  ��ߣ� " << it->m_height << endl;
	}
	cout << endl;
}

bool sortAge(Student s1, Student s2) {
	return s1.m_age < s2.m_age;
}

// ����С����߸�
bool sortAgeHeight(Student s1, Student s2) {
	return s1.m_age < s2.m_age ||  (s1.m_age == s2.m_age && s1.m_height > s2.m_height);
}

// list ������
void sortEg() {
	list<Student> l;
	Student s1("��ɮ", 20, 175);
	Student s2("�����", 50, 165);
	Student s3("��˽�", 30, 155);
	Student s4("ɳ����", 15, 195);
	Student s5("��С��", 15, 225);
	Student s6("�Ͼ�", 15, 135);

	l.push_back(s1);
	l.push_back(s2);
	l.push_back(s3);
	l.push_back(s4);
	l.push_back(s5);
	l.push_back(s6);

	printList(l);
	cout << "--------------����� ����С----------------" << endl;
	l.sort(sortAge);
	printList(l);
	cout << "--------------����� ����С����߸�----------------" << endl;
	l.sort(sortAgeHeight);
	printList(l);
}

void test58() {
	//initList();
	//assignList();
	//sizeList();
	//insertList();
	//seeList();
	//sortList();
	sortEg();
}