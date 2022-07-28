#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs(FileName, ios::in);
	
	// �ļ�������
	if (!ifs.is_open()) {
		this->clearEmpFun();
		ifs.close();
		return;
	} else {
		// �ļ����� ����Ϊ��
		char ch;
		ifs >> ch;
		if (ifs.eof()) {
			this->clearEmpFun();
			ifs.close();
			return;
		}

		// ����������
		this->m_empNum = this->getEmpnum();
		// ���ٿռ�
		this->m_empArray = new Worker * [this->m_empNum];
		this->initEmp();
	}
}

WorkerManager::~WorkerManager()
{
	if (this->m_empArray != NULL) {
		delete[] this->m_empArray;
		this->m_empArray = NULL;
	}
}

// ����˵�
void WorkerManager::showMenu() {
	cout << "**********************************************************" << endl;
	cout << "****************  ��ӭʹ��ְ������ϵͳ  ******************" << endl;
	cout << "********************  0.�˳�����ϵͳ  ********************" << endl;
	cout << "********************  1.����ְ����Ϣ  ********************" << endl;
	cout << "********************  2.��ʾְ����Ϣ  ********************" << endl;
	cout << "********************  3.ɾ��ְ����Ϣ  ********************" << endl;
	cout << "********************  4.�޸�ְ����Ϣ  ********************" << endl;
	cout << "********************  5.����ְ����Ϣ  ********************" << endl;
	cout << "********************  6.���ձ������  ********************" << endl;
	cout << "********************  7.��������ĵ�  ********************" << endl;
	cout << "**********************************************************" << endl;
	cout  << endl;
}

// �˳�ϵͳ
void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

// ���һ��Ա���Ķ���
Worker* creatWorker(int id, string  name , int dId) {
	Worker* worker = NULL;
	switch (dId)
	{
	case 1:
		worker = new Employee(id, name, dId);
		break;
	case 2:
		worker = new Manager(id, name, dId);
		break;
	case 3:
		worker = new Boss(id, name, dId);
		break;
	}
	return worker;
}

// ��ʾ �� ���һ��Ա������  -1: ��ʾ����
Worker* intWorker(int i) {
	int id, dId;
	string name;
	if (i > 0) cout << "������� " << (i + 1) << " ����ְ����ţ�" << endl;
	else cout << "��������ְ����ţ�" << endl;
	cin >> id;
	if (i > 0) cout << "������� " << (i + 1) << " ����ְ��������" << endl;
	else cout << "��������ְ��������" << endl;
	cin >> name;
	cout << "��ѡ���ְ����λ�� " << endl;
	cout << "1.��ְͨ��" << endl;
	cout << "2.����" << endl;
	cout << "3.�ϰ�" << endl;
	cin >> dId;
	
	return creatWorker(id, name, dId);
}

// ���ְ���ķ���
void WorkerManager::addEmpFun(int addNum) {
	// ��������¿ռ��С
	int newSize = this->m_empNum + addNum;
	// �����¿ռ�
	Worker** newSpace = new Worker * [newSize];

	// ��ԭ���ռ��µ����ݣ��������¿ռ�
	if (this->m_empArray != NULL) {
		for (int i = 0; i < this->m_empNum; i++) {
			newSpace[i] = this->m_empArray[i];
		}
	}

	// �������������
	for (int i = 0; i < addNum; i++) {
		// ������ְ�������浽������
		newSpace[this->m_empNum + i] = intWorker(i);
	}

	// �ͷ�ԭ�пռ�
	delete[] this->m_empArray;
	// ��ְ�������ָ�� �¿ռ�
	this->m_empArray = newSpace;
	// ����ְ������
	this->m_empNum = newSize;
}

// ���ְ��
void WorkerManager::addEmp() {
	int addNum = 0;
	cout << "��������ְ��������" << endl;
	cin >> addNum;

	// �������֤�飬��ʾ���˳�
	if (addNum <= 0) {
		cout << "������������" << endl;
	} else {
		this->addEmpFun(addNum); // ���
		// ��ʾ��ӳɹ�
		cout << "�ɹ���� " << addNum << " ����ְ��" << endl;
		this->save();
		this->m_fileIsEmpty = false;
	}

	system("pause");
	system("cls");
}

// �����ļ�
void WorkerManager::save() {
	ofstream ofs(FileName, ios::out);

	// ��ÿ���ļ�д�뵽������
	for (int i = 0; i < this->m_empNum; i++)
	{
		ofs << this->m_empArray[i]->m_id << " "
			<< this->m_empArray[i]->m_name << " "
			<< this->m_empArray[i]->m_deptId << endl;
	}
}

// ͳ������
int WorkerManager::getEmpnum() {
	ifstream ifs(FileName, ios::in);
	int id, dId, num = 0;
	string name;

	while (ifs >> id && ifs >> name && ifs >> dId){
		num++; // ��¼����
	}
	ifs.close();
	return num;
}

// ��ʼ��ְ��
void WorkerManager::initEmp() {
	ifstream ifs(FileName, ios::in);
	int id, dId, index=0;
	string name;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		this->m_empArray[index++] = creatWorker(id, name, dId);
	}
	ifs.close();
}

// ��ʾԱ��
void WorkerManager::showEmp() {
	cout << "* id **** ���� ** ��λ ** ְ��\t\t\t\t   ** ����" << this->m_empNum << "��" << endl;

	for (int i = 0; i < this->m_empNum; i++) {
		this->m_empArray[i]->showInfo();
	}
}


// ְ����ţ��Ƿ����
int WorkerManager::isExit(int id) {
	int result = -1;

	for (int i = 0; i < this->m_empNum; i++)	{
		if (this->m_empArray[i]->m_id == id) {
			result = i;
			break;
		}
	}
	return result;
};
int WorkerManager::isExit(string name){
	int result = -1;

	for (int i = 0; i < this->m_empNum; i++)	{
		if (this->m_empArray[i]->m_name == name) {
			result = i;
			break;
		}
	}
	return result;
}
// ��ȡְ�����
int WorkerManager::getInInPut() {
	int select = 0, index = -2, id = -1;
	string name;
	cout << "1������ְ�����" << endl;
	cout << "2������ְ������" << endl;

	cin >> select;
	if (select == 1) {
		cout << "������ְ����ţ�" << endl;
		cin >> id;
		index = this->isExit(id);
	}
	else if (select == 2) {
		cout << "������ְ��������" << endl;
		cin >> name;
		index = this->isExit(name);
	}
	else {
		cout << "ѡ��ķ�ʽ����" << endl;
	}
	return index;
}
// ɾ��Ա��
void WorkerManager::delEmp() {
	cout << "��ѡ��ɾ����ʽ��" << endl;
	int index = this->getInInPut();
		
	if (index == -1) {
		cout << "δ�ҵ���ְ��" << endl;
	} else if (index > -1) {
		delete this->m_empArray[index]; // ɾ���� index ��Ӧ������

		// ����ǰ�ƶ�
		int len = this->m_empNum -1;
		for (int i = index; i < len; i++) {
			this->m_empArray[i] = *(this->m_empArray + i + 1);
		}

		// �޸���Ա���� ����ǿ�״̬
		this->m_empNum--;
		if (this->m_empNum == 0) this->m_fileIsEmpty = true;

		cout << "ְԱɾ���ɹ�" << endl;
		this->save();
	}
}

// �޸�Ա��
void WorkerManager::updateEmp() {
	cout << "��ѡ���޸ķ�ʽ��" << endl;
	int index = this->getInInPut();

	if (index == -1) {
		cout << "δ�ҵ���ְ��" << endl;
	}
	else if (index > -1) {
		this->m_empArray[index]->showInfo();
		delete this->m_empArray[index]; // ɾ���� index ��Ӧ������
		this->m_empArray[index] = intWorker(-1); // ��������

		cout << "ְԱ��Ϣ���³ɹ�" << endl;
		this->save();
	}
}

// ����Ա��
void WorkerManager::findEmp() {
	int index = this->getInInPut();

	if (index == -1)  cout << "δ�ҵ���ְ��" << endl;
	else if (index > -1) {
		this->m_empArray[index]->showInfo();
	}
}

// ���Ա������
void  WorkerManager::clearEmpFun() {
	this->m_fileIsEmpty = true;
	this->m_empNum = 0; //��ʼ�� ����
	this->m_empArray = NULL; //��ʼ�� ְ������ָ��
}
// ���Ա��
void WorkerManager::clearEmp() {

	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 2;
	cin >> select;
	if (select == 2) return;

	delete[] this->m_empArray;
	this->clearEmpFun();
	this->save();
	cout << "����������" << endl;
}

// ��������
void sortCHange(Worker**  arrPtr, int i, int j){
	Worker* temp = arrPtr[i];
	arrPtr[i] = arrPtr[j];
	arrPtr[j] = temp;
}
// ������ - ѡ������ѡ���������ƶ���
// �ȽϺ�ð��һ���� �����ƶ��Ĵ���
void sortEmpFun(WorkerManager& wm, int sort) {
	Worker** arrPtr = wm.m_empArray;
	int len = wm.m_empNum;

	for (int i = 0; i < len; i++){
		int temp = i;
		for (int j = i+1; j < len; j++) {
			// ����
			if (sort == 1 && arrPtr[i]->m_id > arrPtr[j]->m_id) temp = j;
			// ����
			else if (sort == 2 && arrPtr[i]->m_id < arrPtr[j]->m_id) temp = j;
		}

		if (i != temp) sortCHange(arrPtr, i, temp);
	}
}
// ����Ա��
void WorkerManager::sortEmp() {
	int select = 1;
	cout << "��ѡ������ʽ" << endl;
	cout << "1������ְ���������" << endl;
	cout << "2������ְ����Ž���" << endl;

	cin >> select;
	sortEmpFun(*this, select);
	this->save();
	cout << "���ձ���������" << endl;
	this->showEmp();
}