#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>

// ѧԱ����
class Person
{
public:
	Person(string name, int score) {
		this->m_name = name;
		this->m_sorce = score;
	};
	void setSorce(int score) {
		this->m_sorce = score;
	}
	void print() {
		cout << "������ " << this->m_name << "    ������ " << this->m_sorce << endl;
	}

private:
	string m_name;
	int m_sorce;
};

// ����ѧԱ
void createPerson(vector<Person> &v) {
	string preName = "ѧԱ";
	string arrName = "ABCDE";
	for (int i = 0; i < 5; i++)	{
		string name = preName + arrName[i];
		Person person(name, 0);
		v.push_back(person);
	}
}

// ��ӡ���з���
void pringVectorPerson(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		it->print();
	}
	cout << endl;
}

// ��� - 10����ȥ����ߣ���ͣ�Ȼ��ȡƽ������
void setScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end();it++) {
		// ��ί��10������
		deque<int> d;
		for (int i = 0; i < 10;i++) {
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		sort(d.begin(), d.end());
		d.pop_back(); d.pop_front();

		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += (*dit);
		}

		int avg = sum / d.size();
		it->setSorce(avg);
	}
}

int main() {
	// �ṩ���������
	srand((unsigned int)time(NULL));

	vector<Person> v;
	createPerson(v);
	setScore(v);
	pringVectorPerson(v);

	system("pause");
	return 1;
}