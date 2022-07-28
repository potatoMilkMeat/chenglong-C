#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

// 经理类
class Manager :public Worker
{
public:
	Manager(int id, string name, int dId);
	virtual string getDeptName(); // 获取岗位名称
	virtual string getDeptDes(); // 获取岗位描述
};
