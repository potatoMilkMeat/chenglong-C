#include "00-main.h"
#include <fstream>

class Person28 {
public:
	char m_name[12];
	int age;
};

void test28() {
	string fileName = "person-binary.txt"; // �ļ���
	Person28 cl = { "����", 34 };

	// ������д���ļ�
	ofstream ofs(fileName, ios::out | ios::binary);

	// ���ַ����洢������ ����û�и�ʽ��ȫ������һ��
	// "����34EOF"   7�ֽ�
	//ofs << cl.m_name << cl.age << endl;

	//  16�ֽ�  ���Լ��ĸ�ʽ���ȶ�ȡ�����ֱ�ӱ��Person���� 
	ofs.write((const char*)&cl, sizeof(Person28));

	ofs.close();

	// ������ȡ���ļ�����cout
	ifstream ifs(fileName, ios::in | ios::binary);
	Person28 clRead;
	ifs.read((char*)&clRead, sizeof(Person28));
	if (!ifs.is_open()) {
		cout << "��ȡ�ļ�ʧ��" << endl;
		return;
	}
	cout << "������" << clRead.m_name << "  ���䣺" << clRead.age << endl;
	ifs.close();
}