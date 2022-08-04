#pragma once
#include "public.h"

template<class T>
class MyArray {
public:
	// ��ͨ����
	MyArray(int capcity) { this->initMyArray(capcity); }
	// �๹��
	MyArray(const MyArray& arr) { this.deepCopy(arr); }
	~MyArray() { this->delMyArray(); }

	// =��ֵ 
	MyArray& operator=(MyArray& arr) {
		// �ж��Ƿ��������ڶ�������������ͷŸɾ�
		this->delMyArray();
		// �����һ������
		this->deepCopy(arr);
		return *this;
	}
	// ͨ��[]��������
	T* operator[](int index) {
		return this->pAddress[index];
	}

	// β���
	void push(T item) {
		if (this->m_capcity <= this->m_size) return;
		this->setItem(this->m_size++, item);
	}

	// βɾ��
	void pop() {
		if (this->m_size <= 0) return;
		delete this->pAddress[--this->m_size];
	}

	// չʾ����
	void show() {
		for (int i = 0; i < this->m_size; i++)
		{
			cout << "�� " << i << " �" << this->getByIndex(i) << endl;
		}
	}
	int size() { return this->m_size; }
	int capcity() { return this->m_capcity; }
	
	// ����ֵ�������滻  arr[index] = new T(item);
	void setItem(int index, T item) {
		this->pAddress[index] = new T(item);
	}
	// ���ڻ�ȡֵ ����ʱ�޷�ʹ�� T& = T ������ת����
	T getItem(int index) {
		return this->getByIndex(index);
	}

private:
	T** pAddress; // ����ָ���ַ  ����ڶ���
	int m_capcity; // ����
	int m_size; // ��С

	// ����
	void delMyArray() {
		if (this->pAddress != NULL) {
			for (int i = 0; i < this->m_size; i++)
			{
				delete this->pAddress[i];
			}
			delete this->pAddress;

			this->pAddress = NULL;
			this->m_capcity = this->m_size = 0;
		}
	}
	// ����
	void initMyArray(int capcity) {
		this->pAddress = new T * [capcity];
		this->m_capcity = capcity;
		this->m_size = 0;
	}

	// ��ȡ�� i ������
	T getByIndex(int i) { return *this->pAddress[i]; }

	//���
	void deepCopy(MyArray& arr) {
		this->initMyArray(arr.m_capcity);
		int len = this->m_size = arr.m_size;
		for (int i = 0; i < len; i++)
		{
			this->setItem(i, arr.getByIndex(i));
		}
	}
};