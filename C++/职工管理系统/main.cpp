#include <iostream>
using namespace std;
#include "workerManager.h"

int main() {
	// ʵ���������߶���
	WorkerManeger wm;

	int choice = 0;
	while (true)
	{
		system("cls");
		wm.showMenu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: // �˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: // ����ְ����Ϣ
			break;
		case 2: // ��ʾְ����Ϣ
			break;
		case 3: // ɾ��ְ����Ϣ 
			break;
		case 4: // �޸�ְ����Ϣ
			break;
		case 5: // ����ְ����Ϣ
			break;
		case 6: // ���ձ������
			break;
		case 7: // ��������ĵ�
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}