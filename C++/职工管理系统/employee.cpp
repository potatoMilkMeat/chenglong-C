#include "employee.h"

Employee::Employee(int id, string name, int dId){
	this->setInfo(id, name, dId);
}

string Employee::getDeptDes() {
	return string("完成经理交给的任务");
}

string Employee::getDeptName() {
	return string("员工");
}