#pragma once
#include <iostream>
#include <string>
using namespace std;

// ְ��������
class Worker {
public:
	// ���ø�����Ϣ
	void setInfo(int id, string name, int dId);
	// ��ʾ������Ϣ
	void showInfo();
	// ��ȡ��λ����
	virtual string getDeptName() = 0;
	// ��ȡ��λ����
	virtual string getDeptDes() = 0;

	// ְ�����
	int m_id;
	// ְ������
	string m_name;
	// ְ�����ڲ��ű��
	int m_deptId;
};
