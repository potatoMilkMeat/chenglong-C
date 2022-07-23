#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#define fileName "data.db"
#define MAX 100

// ��ʾ�˵�
void showMenu() {
	cout << "****************************" << endl;
	cout << "*****   1.�����ϵ��   *****" << endl;
	cout << "*****   2.��ʾ��ϵ��   *****" << endl;
	cout << "*****   3.ɾ����ϵ��   *****" << endl;
	cout << "*****   4.������ϵ��   *****" << endl;
	cout << "*****   5.�޸���ϵ��   *****" << endl;
	cout << "*****   6.�����ϵ��   *****" << endl;
	cout << "*****   0.�˳�ͨѶ¼   *****" << endl;
	cout << "****************************" << endl;
}

// ��ϵ�˽ṹ��
struct Person{
	string m_Name; // ����
	short m_Sex; // �Ա� 0�� 1Ů
	short m_Age; // ����
	string m_Phone; // �绰
	string m_Addr; // סַ
};

// ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArry[MAX]; // ͨѶ¼����
	short m_size; // ��Ա����
};


// ��ʾ��Ϣ������ͣ
void showMsgPause(string msg) {
	cout << msg << endl;
	system("pause");
}

// չʾ���˽ṹ����Ϣ
void showPersonItem(struct Person* item) {
	cout << " ������" << item->m_Name
		<< "\t�Ա�" << (item->m_Sex == 1 ? "��" : "Ů")
		<< "\t���䣺" << item->m_Age
		<< "\t�绰��" << item->m_Phone
		<< "\t��ַ��" << item->m_Addr
		<< endl;
}

// �޸���ϵ��
void changePerson(struct Addressbooks* abs, int i) {
	struct Person* _temp = &abs->personArry[i];
	cout << "������������" << endl;
	cin >> _temp->m_Name;
	cout << "�������Ա�1�� 2Ů����" << endl;
	cin >> _temp->m_Sex;
	while (_temp->m_Sex != 1 && _temp->m_Sex != 2) {
		cout << "�����Ա���󣬽�֧�֣�1�� 2Ů����" << endl;
		cout << "���������룺" << endl;
		cin >> _temp->m_Sex;
	};
	cout << "���������䣺" << endl;
	cin >> _temp->m_Age;
	cout << "������绰��" << endl;
	cin >> _temp->m_Phone;
	cout << "�������ַ��" << endl;
	cin >> _temp->m_Addr;
}

// �����ϵ��
void addPerson(struct Addressbooks * abs) {
	if (abs->m_size == MAX){
		showMsgPause("ͨѶ¼������ �޷����");
		return;
	}
	changePerson(abs, abs->m_size);
	abs->m_size++;
	showMsgPause("��ӳɹ�");
}

// ��ʾ��ϵ��
void showPerson(struct Addressbooks* abs) {
	int len = abs->m_size;
	if (len == 0) {
		showMsgPause("*****   ͨѶ¼Ϊ��   *****");
		return;
	}
	struct Person* arr = abs->personArry;
	for (int i = 0; i < len; i++){	
		struct Person item = arr[i];
		showPersonItem(&item);
	}
	showMsgPause("*****   ��ʾ����   *****");
}

// ������ϵ�� ͨ������
int findIndexByName(struct Addressbooks* abs, string name) {
	int len = abs->m_size;
	struct Person* arr = abs->personArry;
	for (int i = 0; i < len; i++){
		struct Person item = arr[i];
		if (item.m_Name == name) return i;
	}
	return -1;
}

// ɾ����ϵ��
void delPerson(struct Addressbooks* abs) {
	cout << "������ɾ���˵�����" << endl;
	string name;
	cin >> name;
	int index = findIndexByName(abs, name);
	if (index == -1) { showMsgPause("δ�ҵ�����ϵ��, ɾ��ʧ��"); return; }
	// ɾ������
	struct Person* arr = abs->personArry;
	for (int i = index; i < abs->m_size; i++){arr[i] = arr[i = 1];}// ����ǰ��
	abs->m_size--; // ɾ���󳤶ȼ�һ
	showMsgPause("ɾ���ɹ�");
}
// ������ϵ��
void findPerson(struct Addressbooks* abs) {
	cout << "����������˵�����" << endl;
	string name;
	cin >> name;
	int index = findIndexByName(abs, name);
	if (index == -1) {showMsgPause("δ�ҵ�����ϵ��"); return;}
	
	struct Person item = abs->personArry[index];
	showPersonItem(&item); // �������Ϣ
	system("pause");
}
// �޸���ϵ��
void updataPerson(struct Addressbooks* abs) {
	cout << "�������޸���ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int index = findIndexByName(abs, name);
	if (index == -1) {showMsgPause("δ�ҵ�����ϵ��"); return;	}
	
	changePerson(abs, index); // �޸Ĳ������Ϣ
	struct Person item = abs->personArry[index];
	cout << "�޸ĺ����ϵ��" << endl;
	showPersonItem(&item);
	system("pause");
}
// ���ͨѶ¼ - ����գ�������Ȼ��
void clearAddressbooks(struct Addressbooks* abs) {
	abs->m_size = 0;
	showMsgPause("���������");
}


// �������� - ������
void saveOfs_binary(const char* _Str, int len) {
	ofstream ofs(fileName, ios::out | ios::binary);
	ofs.write(_Str, len);
	ofs.close();
}
// ��ȡ���� - ������ ���سɹ�/ʧ��
bool getIfs_binary(char* _Str, int len) {
	ifstream ifs(fileName, ios::binary | ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return false;
	}
	ifs.read(_Str, len);
	ifs.close();
	return true;
}
// ��������
void save_abs(struct Addressbooks* abs) {
	saveOfs_binary((const char*)abs, sizeof(*abs));
	cout << "*****   ����ɹ�   *****" << endl;
}
// ��ȡ����
bool read_abs(struct Addressbooks* abs) {
	bool result = getIfs_binary((char*)abs, sizeof(*abs));
	return result;
}


// ��ʾ���� - �ݹ�
void reduMenu(struct Addressbooks* abs, int* select) {
	system("cls");
	showMenu();
	cin >> *select;

	switch (*select)
	{
	case 1: // 1.�����ϵ��
		addPerson(abs); // ����ָ�봫���޸�ͨѶ¼
		save_abs(abs);
		break;
	case 2: // 2.��ʾ��ϵ��
		showPerson(abs);
		break;
	case 3: // 3.ɾ����ϵ��
		delPerson(abs);
		save_abs(abs);
		break;
	case 4: //  4.������ϵ��
		findPerson(abs);
		break;
	case 5: // 5.�޸���ϵ��
		updataPerson(abs);
		save_abs(abs);
		break;
	case 6: // 6.�����ϵ��
		clearAddressbooks(abs);
		save_abs(abs);
		break;
	case 0: // 0.�˳�ͨѶ¼
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		return;
	default:
		break;
	}
	reduMenu(abs, select); // �ݹ����
}
int main() {
	struct Addressbooks  abs; // ����ͨѶ¼����
	bool read_result = read_abs(&abs); // ��ȡ�ϴδ洢����
	if (!read_result) {
		abs.m_size = 0; // ��ʼ��ͨѶ¼�е�����
	}

	int select = 0; // �û�ѡ��Ĳ˵�
	reduMenu(&abs, &select);
	system("pause");
	return 0;
}