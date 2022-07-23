#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define fileName "data.db"



// ��������
void saveOfs(char data[]) {
	ofstream ofs(fileName, ios::trunc | ios::binary);
	ofs << data << endl;
	ofs.close();
}

// ��ȡ����
string getOfs() {
	ifstream ifs(fileName, ios::binary | ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return "";
	}

	// �ַ�����
	// char buf[1024] = { 0 };
	// while (ifs.getline(buf, sizeof(buf))){ cout << buf << endl; }
	string buf;
	while (getline(ifs, buf)) {}

	ifs.close();
	return buf;
}

// �������� - ������
void saveOfs_binary(const char* _Str, int len) {
	ofstream ofs(fileName, ios::out | ios::binary);
	ofs.write(_Str, len);
	ofs.close();
}
// ��ȡ���� - ������ ���سɹ�/ʧ��
bool getIfs_binary(char* _Str, int len) {
	ifstream ifs(fileName, ios::binary | ios:: in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return false;
	}
	ifs.read(_Str, len);
	ifs.close();
	return true;
}

struct Person {
	string m_Name; // ����
	int m_Sex; // �Ա� 1�� 2Ů
};
struct Teacher {
	string t_name;
	struct Person arr[50];
};


int main() {
	//cout << "��ʼд��" << endl;
	// char data[] = "chenglong2563-����-256333";
	//saveOfs(data);


	//Person p = {"chenglong", 1};
	//saveOfs_binary((const char *)&p, sizeof(p));

	/* Person p1;
	getIfs_binary((char *)&p1, sizeof(p1));
	cout << p1.m_Name << p1.m_Sex << "   д�� end" << endl;
	*/

	/*Teacher t;
	t.t_name = "����ʦ";
	t.arr[0] = { "chenglong", 1 };
	t.arr[1] = { "cl", 1 };
	t.arr[2] = { "chengyuxun", 1 };
	for (int i = 3; i < 50; i++){
		t.arr[i] = { "", -1 };
	}
	cout << t.t_name << sizeof(t) << endl;
	saveOfs_binary((const char *)&t, sizeof(t));*/

	Teacher t1;
	getIfs_binary((char *)&t1, sizeof(Teacher));
	cout << sizeof(Teacher) << endl;
	cout << t1.t_name << t1.arr[2].m_Name << t1.arr[2].m_Sex << endl;

	system("pause");
	return 0;
}