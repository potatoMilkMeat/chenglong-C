#include "worker.h"

void Worker::showInfo() {
	//cout << "ְ����ţ�" << this->m_id
	//	<< "\tְ��������" << this->m_name
	//	<< "\t��λ��" << this->getDeptName()
	//	<< "\t��λְ��" << this->getDeptDes() << endl;

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