#include <iostream>
using namespace std;
#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define IfEmpty if (wm.m_fileIsEmpty) { cout << "文件不存在或者记录为空" << endl;}else {
#define PauseAndCls }system("pause");system("cls");

//// 测试职工类多态
//void test() {
//	Worker* worker = NULL;
//	worker = new Employee(1, "张三", 1);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(2, "李四", 2);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(3, "王五", 3);
//	worker->showInfo();
//	delete worker;
//}

int main() {
	// 实例化管理者对象
	WorkerManager wm;
	//cout << "* id **** 姓名 ** 岗位 ** 职责" << endl;
	//test();
	//system("pause");

	int choice = 0;
	while (true)
	{
		wm.showMenu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: // 退出系统
			wm.exitSystem();
			break;
		case 1: // 增加职工信息
			wm.addEmp();
			break;
		case 2: // 显示职工信息
			IfEmpty wm.showEmp(); PauseAndCls
			break;
		case 3: // 删除职工信息
			IfEmpty wm.delEmp(); PauseAndCls
			break;
		case 4: // 修改职工信息
			IfEmpty wm.updateEmp(); PauseAndCls
			break;
		case 5: // 查找职工信息
			IfEmpty wm.findEmp(); PauseAndCls
			break;
		case 6: // 按照编号排序
			IfEmpty wm.sortEmp(); PauseAndCls
			break;
		case 7: // 清空所有文档
			IfEmpty wm.clearEmp(); PauseAndCls
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}