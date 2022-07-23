#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#define fileName "data.db"
#define MAX 100

// 显示菜单
void showMenu() {
	cout << "****************************" << endl;
	cout << "*****   1.添加联系人   *****" << endl;
	cout << "*****   2.显示联系人   *****" << endl;
	cout << "*****   3.删除联系人   *****" << endl;
	cout << "*****   4.查找联系人   *****" << endl;
	cout << "*****   5.修改联系人   *****" << endl;
	cout << "*****   6.清空联系人   *****" << endl;
	cout << "*****   0.退出通讯录   *****" << endl;
	cout << "****************************" << endl;
}

// 联系人结构体
struct Person{
	string m_Name; // 姓名
	short m_Sex; // 性别 0男 1女
	short m_Age; // 年龄
	string m_Phone; // 电话
	string m_Addr; // 住址
};

// 通讯录结构体
struct Addressbooks {
	struct Person personArry[MAX]; // 通讯录数组
	short m_size; // 人员个数
};


// 提示信息并且暂停
void showMsgPause(string msg) {
	cout << msg << endl;
	system("pause");
}

// 展示个人结构体信息
void showPersonItem(struct Person* item) {
	cout << " 姓名：" << item->m_Name
		<< "\t性别：" << (item->m_Sex == 1 ? "男" : "女")
		<< "\t年龄：" << item->m_Age
		<< "\t电话：" << item->m_Phone
		<< "\t地址：" << item->m_Addr
		<< endl;
}

// 修改联系人
void changePerson(struct Addressbooks* abs, int i) {
	struct Person* _temp = &abs->personArry[i];
	cout << "请输入姓名：" << endl;
	cin >> _temp->m_Name;
	cout << "请输入性别（1男 2女）：" << endl;
	cin >> _temp->m_Sex;
	while (_temp->m_Sex != 1 && _temp->m_Sex != 2) {
		cout << "输入性别错误，仅支持（1男 2女）：" << endl;
		cout << "请重新输入：" << endl;
		cin >> _temp->m_Sex;
	};
	cout << "请输入年龄：" << endl;
	cin >> _temp->m_Age;
	cout << "请输入电话：" << endl;
	cin >> _temp->m_Phone;
	cout << "请输入地址：" << endl;
	cin >> _temp->m_Addr;
}

// 添加联系人
void addPerson(struct Addressbooks * abs) {
	if (abs->m_size == MAX){
		showMsgPause("通讯录已满， 无法添加");
		return;
	}
	changePerson(abs, abs->m_size);
	abs->m_size++;
	showMsgPause("添加成功");
}

// 显示联系人
void showPerson(struct Addressbooks* abs) {
	int len = abs->m_size;
	if (len == 0) {
		showMsgPause("*****   通讯录为空   *****");
		return;
	}
	struct Person* arr = abs->personArry;
	for (int i = 0; i < len; i++){	
		struct Person item = arr[i];
		showPersonItem(&item);
	}
	showMsgPause("*****   显示结束   *****");
}

// 查找联系人 通过姓名
int findIndexByName(struct Addressbooks* abs, string name) {
	int len = abs->m_size;
	struct Person* arr = abs->personArry;
	for (int i = 0; i < len; i++){
		struct Person item = arr[i];
		if (item.m_Name == name) return i;
	}
	return -1;
}

// 删除联系人
void delPerson(struct Addressbooks* abs) {
	cout << "请输入删除人的姓名" << endl;
	string name;
	cin >> name;
	int index = findIndexByName(abs, name);
	if (index == -1) { showMsgPause("未找到此联系人, 删除失败"); return; }
	// 删除操作
	struct Person* arr = abs->personArry;
	for (int i = index; i < abs->m_size; i++){arr[i] = arr[i = 1];}// 数据前移
	abs->m_size--; // 删除后长度减一
	showMsgPause("删除成功");
}
// 查找联系人
void findPerson(struct Addressbooks* abs) {
	cout << "请输入查找人的姓名" << endl;
	string name;
	cin >> name;
	int index = findIndexByName(abs, name);
	if (index == -1) {showMsgPause("未找到此联系人"); return;}
	
	struct Person item = abs->personArry[index];
	showPersonItem(&item); // 输出人信息
	system("pause");
}
// 修改联系人
void updataPerson(struct Addressbooks* abs) {
	cout << "请输入修改联系人的姓名" << endl;
	string name;
	cin >> name;
	int index = findIndexByName(abs, name);
	if (index == -1) {showMsgPause("未找到此联系人"); return;	}
	
	changePerson(abs, index); // 修改并输出信息
	struct Person item = abs->personArry[index];
	cout << "修改后的联系人" << endl;
	showPersonItem(&item);
	system("pause");
}
// 清空通讯录 - 假清空，数据仍然在
void clearAddressbooks(struct Addressbooks* abs) {
	abs->m_size = 0;
	showMsgPause("已清空数据");
}


// 保存数据 - 二进制
void saveOfs_binary(const char* _Str, int len) {
	ofstream ofs(fileName, ios::out | ios::binary);
	ofs.write(_Str, len);
	ofs.close();
}
// 读取数据 - 二进制 返回成功/失败
bool getIfs_binary(char* _Str, int len) {
	ifstream ifs(fileName, ios::binary | ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return false;
	}
	ifs.read(_Str, len);
	ifs.close();
	return true;
}
// 保存数据
void save_abs(struct Addressbooks* abs) {
	saveOfs_binary((const char*)abs, sizeof(*abs));
	cout << "*****   保存成功   *****" << endl;
}
// 读取数据
bool read_abs(struct Addressbooks* abs) {
	bool result = getIfs_binary((char*)abs, sizeof(*abs));
	return result;
}


// 显示功能 - 递归
void reduMenu(struct Addressbooks* abs, int* select) {
	system("cls");
	showMenu();
	cin >> *select;

	switch (*select)
	{
	case 1: // 1.添加联系人
		addPerson(abs); // 利用指针传递修改通讯录
		save_abs(abs);
		break;
	case 2: // 2.显示联系人
		showPerson(abs);
		break;
	case 3: // 3.删除联系人
		delPerson(abs);
		save_abs(abs);
		break;
	case 4: //  4.查找联系人
		findPerson(abs);
		break;
	case 5: // 5.修改联系人
		updataPerson(abs);
		save_abs(abs);
		break;
	case 6: // 6.清空联系人
		clearAddressbooks(abs);
		save_abs(abs);
		break;
	case 0: // 0.退出通讯录
		cout << "欢迎下次使用" << endl;
		system("pause");
		return;
	default:
		break;
	}
	reduMenu(abs, select); // 递归调用
}
int main() {
	struct Addressbooks  abs; // 创建通讯录变量
	bool read_result = read_abs(&abs); // 读取上次存储数据
	if (!read_result) {
		abs.m_size = 0; // 初始化通讯录中的人数
	}

	int select = 0; // 用户选择的菜单
	reduMenu(&abs, &select);
	system("pause");
	return 0;
}