#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

// Ա����
class Employee:public Worker
{
public:
	Employee(int id, string name, int dId);
	virtual string getDeptName(); // ��ȡ��λ����
	virtual string getDeptDes(); // ��ȡ��λ����
};
