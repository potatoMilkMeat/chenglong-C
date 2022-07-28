#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FileName "db.txt"

class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();
	// չʾ�˵�
	void  showMenu();
	// �˳�ϵͳ
	void exitSystem();

	// ���ְ��
	void addEmp();
	void addEmpFun(int addNum);

	// ����ְ��
	void save();

	// ͳ������
	int getEmpnum();
	// ��ʼ��ְ��
	void initEmp();

	// Ϊ������
	void showWarnIsEmpty();
	// ��ʾԱ��
	void showEmp();

	// ְ����ţ��Ƿ���ڣ������ڷ���-1
	int isExit(int id);
	int isExit(string name);
	// ��ȡְ�����
	int getInInPut();
	// ɾ��Ա��
	void delEmp();

	// �޸�Ա��
	void updateEmp();

	// ����Ա��
	void findEmp();

	// ���Ա������
	void clearEmpFun();
	// ���Ա��
	void clearEmp();

	// ����Ա��
	void sortEmp();
	
	//��¼�ļ��е���������
	int m_empNum;
	//Ա�������ָ��
	Worker** m_empArray;
	// ��־�ļ��Ƿ�Ϊ��
	bool m_fileIsEmpty;
};