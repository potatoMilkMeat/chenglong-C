#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define fileName "data.db"



// 保存数据
void saveOfs(char data[]) {
	ofstream ofs(fileName, ios::trunc | ios::binary);
	ofs << data << endl;
	ofs.close();
}

// 读取数据
string getOfs() {
	ifstream ifs(fileName, ios::binary | ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return "";
	}

	// 字符数组
	// char buf[1024] = { 0 };
	// while (ifs.getline(buf, sizeof(buf))){ cout << buf << endl; }
	string buf;
	while (getline(ifs, buf)) {}

	ifs.close();
	return buf;
}

// 保存数据 - 二进制
void saveOfs_binary(const char* _Str, int len) {
	ofstream ofs(fileName, ios::out | ios::binary);
	ofs.write(_Str, len);
	ofs.close();
}
// 读取数据 - 二进制 返回成功/失败
bool getIfs_binary(char* _Str, int len) {
	ifstream ifs(fileName, ios::binary | ios:: in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return false;
	}
	ifs.read(_Str, len);
	ifs.close();
	return true;
}

struct Person {
	string m_Name; // 姓名
	int m_Sex; // 性别 1男 2女
};
struct Teacher {
	string t_name;
	struct Person arr[50];
};


int main() {
	//cout << "开始写入" << endl;
	// char data[] = "chenglong2563-程龙-256333";
	//saveOfs(data);


	//Person p = {"chenglong", 1};
	//saveOfs_binary((const char *)&p, sizeof(p));

	/* Person p1;
	getIfs_binary((char *)&p1, sizeof(p1));
	cout << p1.m_Name << p1.m_Sex << "   写入 end" << endl;
	*/

	/*Teacher t;
	t.t_name = "程老师";
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