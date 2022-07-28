#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

// 老板类
class Boss :public Worker
{
public:
	Boss(int id, string name, int dId);
	virtual string getDeptName(); // 获取岗位名称
	virtual string getDeptDes(); // 获取岗位描述
};
