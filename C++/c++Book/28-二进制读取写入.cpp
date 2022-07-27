#include "00-main.h"
#include <fstream>

class Person28 {
public:
	char m_name[12];
	int age;
};

void test28() {
	string fileName = "person-binary.txt"; // 文件名
	Person28 cl = { "程龙", 34 };

	// 二进制写入文件
	ofstream ofs(fileName, ios::out | ios::binary);

	// 以字符串存储的数据 ，会没有格式，全部连到一起。
	// "程龙34EOF"   7字节
	//ofs << cl.m_name << cl.age << endl;

	//  16字节  有自己的格式，等读取后可以直接变成Person对象 
	ofs.write((const char*)&cl, sizeof(Person28));

	ofs.close();

	// 二进制取出文件，并cout
	ifstream ifs(fileName, ios::in | ios::binary);
	Person28 clRead;
	ifs.read((char*)&clRead, sizeof(Person28));
	if (!ifs.is_open()) {
		cout << "读取文件失败" << endl;
		return;
	}
	cout << "姓名：" << clRead.m_name << "  年龄：" << clRead.age << endl;
	ifs.close();
}