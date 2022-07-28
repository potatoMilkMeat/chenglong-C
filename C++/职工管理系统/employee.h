#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

// 员工类
class Employee:public Worker
{
public:
	Employee(int id, string name, int dId);
	virtual string getDeptName(); // 获取岗位名称
	virtual string getDeptDes(); // 获取岗位描述
};
