#include "employee.h"

Employee::Employee(int id, string name, int dId){
	this->setInfo(id, name, dId);
}

string Employee::getDeptDes() {
	return string("��ɾ�����������");
}

string Employee::getDeptName() {
	return string("Ա��");
}