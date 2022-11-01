#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>

// 学员类型
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
		cout << "姓名： " << this->m_name << "    分数： " << this->m_sorce << endl;
	}

private:
	string m_name;
	int m_sorce;
};

// 创建学员
void createPerson(vector<Person> &v) {
	string preName = "学员";
	string arrName = "ABCDE";
	for (int i = 0; i < 5; i++)	{
		string name = preName + arrName[i];
		Person person(name, 0);
		v.push_back(person);
	}
}

// 打印所有分数
void pringVectorPerson(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		it->print();
	}
	cout << endl;
}

// 打分 - 10个，去掉最高，最低，然后取平均分数
void setScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end();it++) {
		// 评委的10个分数
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
	// 提供随机数种子
	srand((unsigned int)time(NULL));

	vector<Person> v;
	createPerson(v);
	setScore(v);
	pringVectorPerson(v);

	system("pause");
	return 1;
}