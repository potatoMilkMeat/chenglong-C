#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
using namespace std;

#define Cehua 0
#define Meishu 1
#define Yanfa 2

// 员工分组
// 员工
class Worker {
public:
	string m_name;
	int m_salary;
};

// 创造十名员工
void createWorker(vector<Worker> &v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_name = "员工";
		worker.m_name += nameSeed[i];

		worker.m_salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}

// 分组
void setGroup(vector<Worker>&v, multimap<int, Worker>&m) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		// 产生随机编号
		int detId = rand() % 3;

		// 将员工扎入到分组中
		m.insert(make_pair(detId, *it));
	}
}

// 按照部门显示员工
void ShowM(multimap<int, Worker>const &m) {

	cout << "策划部门:" << endl;
	multimap<int, Worker>::const_iterator pos = m.find(Cehua);
	int count = m.count(Cehua); int index = 0;

	for (; pos!= m.end() && index < count; pos++, index++) {
		cout << pos->second.m_name  << "   " << pos->second.m_salary << endl;
	}
	cout << "==========================" << endl;
	cout << "美术部门" << endl;
	
	for (pos = m.find(Yanfa), count = m.count(Yanfa), index = 0; pos != m.end() && index < count; pos++, index++) {
		cout << pos->second.m_name << "   " << pos->second.m_salary << endl;
	}

	cout << "==========================" << endl;
	cout << "研发部门" << endl;
	
	for (pos = m.find(Yanfa), count = m.count(Yanfa), index = 0; pos != m.end() && index < count; pos++, index++) {
		cout << pos->second.m_name << "   " << pos->second.m_salary << endl;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	// 创建
	vector<Worker> vWorker;
	createWorker(vWorker);

	//for (vector<Worker>::iterator it = vWorker.begin(); it!=vWorker.end(); it++) {
	//	cout << it->m_name << "   " << it->m_salary << endl;
	//}

	// 分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);
	ShowM(mWorker);

	system("pause");
	return 0;
}