#include "worker.h"

void Worker::showInfo() {
	//cout << "职工编号：" << this->m_id
	//	<< "\t职工姓名：" << this->m_name
	//	<< "\t岗位：" << this->getDeptName()
	//	<< "\t岗位职责：" << this->getDeptDes() << endl;

	cout << "  " << this->m_id
		<< "\t  " << this->m_name
		<< "\t  " << this->getDeptName()
		<< "\t  " << this->getDeptDes() << endl;
}

void Worker::setInfo(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = dId;
}