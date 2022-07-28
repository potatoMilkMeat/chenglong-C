#include "manager.h"

Manager::Manager(int id, string name, int dId) {
	this->setInfo(id, name, dId);
}

string Manager::getDeptDes() {
	return string("完成老板交给的任务，并下发给员工");
}

string Manager::getDeptName() {
	return string("经理");
}