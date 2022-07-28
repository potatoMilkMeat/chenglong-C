#include <iostream>
using namespace std;
#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define IfEmpty if (wm.m_fileIsEmpty) { cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;}else {
#define PauseAndCls }system("pause");system("cls");

//// ����ְ�����̬
//void test() {
//	Worker* worker = NULL;
//	worker = new Employee(1, "����", 1);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(2, "����", 2);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(3, "����", 3);
//	worker->showInfo();
//	delete worker;
//}

int main() {
	// ʵ���������߶���
	WorkerManager wm;
	//cout << "* id **** ���� ** ��λ ** ְ��" << endl;
	//test();
	//system("pause");

	int choice = 0;
	while (true)
	{
		wm.showMenu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: // �˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: // ����ְ����Ϣ
			wm.addEmp();
			break;
		case 2: // ��ʾְ����Ϣ
			IfEmpty wm.showEmp(); PauseAndCls
			break;
		case 3: // ɾ��ְ����Ϣ
			IfEmpty wm.delEmp(); PauseAndCls
			break;
		case 4: // �޸�ְ����Ϣ
			IfEmpty wm.updateEmp(); PauseAndCls
			break;
		case 5: // ����ְ����Ϣ
			IfEmpty wm.findEmp(); PauseAndCls
			break;
		case 6: // ���ձ������
			IfEmpty wm.sortEmp(); PauseAndCls
			break;
		case 7: // ��������ĵ�
			IfEmpty wm.clearEmp(); PauseAndCls
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}