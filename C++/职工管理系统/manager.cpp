#include "manager.h"

Manager::Manager(int id, string name, int dId) {
	this->setInfo(id, name, dId);
}

string Manager::getDeptDes() {
	return string("����ϰ彻�������񣬲��·���Ա��");
}

string Manager::getDeptName() {
	return string("����");
}