#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs(FileName, ios::in);
	
	// 文件不存在
	if (!ifs.is_open()) {
		this->clearEmpFun();
		ifs.close();
		return;
	} else {
		// 文件存在 数据为空
		char ch;
		ifs >> ch;
		if (ifs.eof()) {
			this->clearEmpFun();
			ifs.close();
			return;
		}

		// 正常有数据
		this->m_empNum = this->getEmpnum();
		// 开辟空间
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

// 管理菜单
void WorkerManager::showMenu() {
	cout << "**********************************************************" << endl;
	cout << "****************  欢迎使用职工管理系统  ******************" << endl;
	cout << "********************  0.退出管理系统  ********************" << endl;
	cout << "********************  1.增加职工信息  ********************" << endl;
	cout << "********************  2.显示职工信息  ********************" << endl;
	cout << "********************  3.删除职工信息  ********************" << endl;
	cout << "********************  4.修改职工信息  ********************" << endl;
	cout << "********************  5.查找职工信息  ********************" << endl;
	cout << "********************  6.按照编号排序  ********************" << endl;
	cout << "********************  7.清空所有文档  ********************" << endl;
	cout << "**********************************************************" << endl;
	cout  << endl;
}

// 退出系统
void WorkerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

// 添加一名员工的对象
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

// 提示 并 添加一名员工对象。  -1: 表示更新
Worker* intWorker(int i) {
	int id, dId;
	string name;
	if (i > 0) cout << "请输入第 " << (i + 1) << " 个新职工编号：" << endl;
	else cout << "请输入新职工编号：" << endl;
	cin >> id;
	if (i > 0) cout << "请输入第 " << (i + 1) << " 个新职工姓名：" << endl;
	else cout << "请输入新职工姓名：" << endl;
	cin >> name;
	cout << "请选择该职工岗位： " << endl;
	cout << "1.普通职工" << endl;
	cout << "2.经理" << endl;
	cout << "3.老板" << endl;
	cin >> dId;
	
	return creatWorker(id, name, dId);
}

// 添加职工的方法
void WorkerManager::addEmpFun(int addNum) {
	// 计算添加新空间大小
	int newSize = this->m_empNum + addNum;
	// 开辟新空间
	Worker** newSpace = new Worker * [newSize];

	// 将原来空间下的数据，拷贝到新空间
	if (this->m_empArray != NULL) {
		for (int i = 0; i < this->m_empNum; i++) {
			newSpace[i] = this->m_empArray[i];
		}
	}

	// 批量添加新数据
	for (int i = 0; i < addNum; i++) {
		// 将创建职工，保存到数组中
		newSpace[this->m_empNum + i] = intWorker(i);
	}

	// 释放原有空间
	delete[] this->m_empArray;
	// 将职工数组的指向 新空间
	this->m_empArray = newSpace;
	// 更改职工数量
	this->m_empNum = newSize;
}

// 添加职工
void WorkerManager::addEmp() {
	int addNum = 0;
	cout << "请输入新职工的数量" << endl;
	cin >> addNum;

	// 如果不是证书，提示并退出
	if (addNum <= 0) {
		cout << "输入数据有误" << endl;
	} else {
		this->addEmpFun(addNum); // 添加
		// 提示添加成功
		cout << "成功添加 " << addNum << " 名新职工" << endl;
		this->save();
		this->m_fileIsEmpty = false;
	}

	system("pause");
	system("cls");
}

// 保存文件
void WorkerManager::save() {
	ofstream ofs(FileName, ios::out);

	// 将每个文件写入到数据中
	for (int i = 0; i < this->m_empNum; i++)
	{
		ofs << this->m_empArray[i]->m_id << " "
			<< this->m_empArray[i]->m_name << " "
			<< this->m_empArray[i]->m_deptId << endl;
	}
}

// 统计人数
int WorkerManager::getEmpnum() {
	ifstream ifs(FileName, ios::in);
	int id, dId, num = 0;
	string name;

	while (ifs >> id && ifs >> name && ifs >> dId){
		num++; // 记录人数
	}
	ifs.close();
	return num;
}

// 初始化职工
void WorkerManager::initEmp() {
	ifstream ifs(FileName, ios::in);
	int id, dId, index=0;
	string name;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		this->m_empArray[index++] = creatWorker(id, name, dId);
	}
	ifs.close();
}

// 显示员工
void WorkerManager::showEmp() {
	cout << "* id **** 姓名 ** 岗位 ** 职责\t\t\t\t   ** 共：" << this->m_empNum << "人" << endl;

	for (int i = 0; i < this->m_empNum; i++) {
		this->m_empArray[i]->showInfo();
	}
}


// 职工编号，是否存在
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
// 获取职工序号
int WorkerManager::getInInPut() {
	int select = 0, index = -2, id = -1;
	string name;
	cout << "1、按照职工编号" << endl;
	cout << "2、按照职工姓名" << endl;

	cin >> select;
	if (select == 1) {
		cout << "请输入职工编号：" << endl;
		cin >> id;
		index = this->isExit(id);
	}
	else if (select == 2) {
		cout << "请输入职工姓名：" << endl;
		cin >> name;
		index = this->isExit(name);
	}
	else {
		cout << "选择的方式错误。" << endl;
	}
	return index;
}
// 删除员工
void WorkerManager::delEmp() {
	cout << "请选择删除方式：" << endl;
	int index = this->getInInPut();
		
	if (index == -1) {
		cout << "未找到该职工" << endl;
	} else if (index > -1) {
		delete this->m_empArray[index]; // 删除该 index 对应堆数据

		// 数据前移动
		int len = this->m_empNum -1;
		for (int i = index; i < len; i++) {
			this->m_empArray[i] = *(this->m_empArray + i + 1);
		}

		// 修改人员数量 并标记空状态
		this->m_empNum--;
		if (this->m_empNum == 0) this->m_fileIsEmpty = true;

		cout << "职员删除成功" << endl;
		this->save();
	}
}

// 修改员工
void WorkerManager::updateEmp() {
	cout << "请选择修改方式：" << endl;
	int index = this->getInInPut();

	if (index == -1) {
		cout << "未找到该职工" << endl;
	}
	else if (index > -1) {
		this->m_empArray[index]->showInfo();
		delete this->m_empArray[index]; // 删除该 index 对应堆数据
		this->m_empArray[index] = intWorker(-1); // 更新数据

		cout << "职员信息更新成功" << endl;
		this->save();
	}
}

// 查找员工
void WorkerManager::findEmp() {
	int index = this->getInInPut();

	if (index == -1)  cout << "未找到该职工" << endl;
	else if (index > -1) {
		this->m_empArray[index]->showInfo();
	}
}

// 清空员工函数
void  WorkerManager::clearEmpFun() {
	this->m_fileIsEmpty = true;
	this->m_empNum = 0; //初始化 人数
	this->m_empArray = NULL; //初始化 职工数组指针
}
// 清空员工
void WorkerManager::clearEmp() {

	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 2;
	cin >> select;
	if (select == 2) return;

	delete[] this->m_empArray;
	this->clearEmpFun();
	this->save();
	cout << "数据清除完毕" << endl;
}

// 交换函数
void sortCHange(Worker**  arrPtr, int i, int j){
	Worker* temp = arrPtr[i];
	arrPtr[i] = arrPtr[j];
	arrPtr[j] = temp;
}
// 排序函数 - 选择排序，选出最大后再移动。
// 比较和冒泡一样。 减少移动的次数
void sortEmpFun(WorkerManager& wm, int sort) {
	Worker** arrPtr = wm.m_empArray;
	int len = wm.m_empNum;

	for (int i = 0; i < len; i++){
		int temp = i;
		for (int j = i+1; j < len; j++) {
			// 升序
			if (sort == 1 && arrPtr[i]->m_id > arrPtr[j]->m_id) temp = j;
			// 降序
			else if (sort == 2 && arrPtr[i]->m_id < arrPtr[j]->m_id) temp = j;
		}

		if (i != temp) sortCHange(arrPtr, i, temp);
	}
}
// 排序员工
void WorkerManager::sortEmp() {
	int select = 1;
	cout << "请选择排序方式" << endl;
	cout << "1、按照职工编号升序" << endl;
	cout << "2、按照职工编号降序" << endl;

	cin >> select;
	sortEmpFun(*this, select);
	this->save();
	cout << "按照编号排序完成" << endl;
	this->showEmp();
}