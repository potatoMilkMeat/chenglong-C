#include "boss.h"

Boss::Boss(int id, string name, int dId) {
	this->setInfo(id, name, dId);
}

string Boss::getDeptDes() {
	return string("����˾��������");
}

string Boss::getDeptName() {
	return string("�ϰ�");
}