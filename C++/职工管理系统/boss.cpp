#include "boss.h"

Boss::Boss(int id, string name, int dId) {
	this->setInfo(id, name, dId);
}

string Boss::getDeptDes() {
	return string("管理公司所有事务");
}

string Boss::getDeptName() {
	return string("老板");
}