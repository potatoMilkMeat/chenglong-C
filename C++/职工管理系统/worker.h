#pragma once
#include <iostream>
#include <string>
using namespace std;

// 职工抽象类
class Worker {
public:
	// 设置个人信息
	void setInfo(int id, string name, int dId);
	// 显示个人信息
	void showInfo();
	// 获取岗位名称
	virtual string getDeptName() = 0;
	// 获取岗位描述
	virtual string getDeptDes() = 0;

	// 职工编号
	int m_id;
	// 职工姓名
	string m_name;
	// 职工所在部门编号
	int m_deptId;
};
