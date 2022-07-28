#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FileName "db.txt"

class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();
	// 展示菜单
	void  showMenu();
	// 退出系统
	void exitSystem();

	// 添加职工
	void addEmp();
	void addEmpFun(int addNum);

	// 保存职工
	void save();

	// 统计人数
	int getEmpnum();
	// 初始化职工
	void initEmp();

	// 为空提醒
	void showWarnIsEmpty();
	// 显示员工
	void showEmp();

	// 职工编号，是否存在，不存在返回-1
	int isExit(int id);
	int isExit(string name);
	// 获取职工序号
	int getInInPut();
	// 删除员工
	void delEmp();

	// 修改员工
	void updateEmp();

	// 查找员工
	void findEmp();

	// 清空员工函数
	void clearEmpFun();
	// 清空员工
	void clearEmp();

	// 排序员工
	void sortEmp();
	
	//记录文件中的人数个数
	int m_empNum;
	//员工数组的指针
	Worker** m_empArray;
	// 标志文件是否为空
	bool m_fileIsEmpty;
};