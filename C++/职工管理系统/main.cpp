#include <iostream>
using namespace std;
#include "workerManager.h"

int main() {
	// 实例化管理者对象
	WorkerManeger wm;

	int choice = 0;
	while (true)
	{
		system("cls");
		wm.showMenu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: // 退出系统
			wm.exitSystem();
			break;
		case 1: // 增加职工信息
			break;
		case 2: // 显示职工信息
			break;
		case 3: // 删除职工信息 
			break;
		case 4: // 修改职工信息
			break;
		case 5: // 查找职工信息
			break;
		case 6: // 按照编号排序
			break;
		case 7: // 清空所有文档
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}