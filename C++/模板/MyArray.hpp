#pragma once
#include "public.h"

template<class T>
class MyArray {
public:
	// 普通构造
	MyArray(int capcity) { this->initMyArray(capcity); }
	// 类构造
	MyArray(const MyArray& arr) { this.deepCopy(arr); }
	~MyArray() { this->delMyArray(); }

	// =赋值 
	MyArray& operator=(MyArray& arr) {
		// 判断是否有属性在堆区，如果有先释放干净
		this->delMyArray();
		// 深拷贝出一个区域
		this->deepCopy(arr);
		return *this;
	}
	// 通过[]访问数据
	T* operator[](int index) {
		return this->pAddress[index];
	}

	// 尾添加
	void push(T item) {
		if (this->m_capcity <= this->m_size) return;
		this->setItem(this->m_size++, item);
	}

	// 尾删除
	void pop() {
		if (this->m_size <= 0) return;
		delete this->pAddress[--this->m_size];
	}

	// 展示内容
	void show() {
		for (int i = 0; i < this->m_size; i++)
		{
			cout << "第 " << i << " 项：" << this->getByIndex(i) << endl;
		}
	}
	int size() { return this->m_size; }
	int capcity() { return this->m_capcity; }
	
	// 设置值，用于替换  arr[index] = new T(item);
	void setItem(int index, T item) {
		this->pAddress[index] = new T(item);
	}
	// 用于获取值 。暂时无法使用 T& = T 的类型转换；
	T getItem(int index) {
		return this->getByIndex(index);
	}

private:
	T** pAddress; // 数组指针地址  存放在堆区
	int m_capcity; // 容量
	int m_size; // 大小

	// 销毁
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
	// 创建
	void initMyArray(int capcity) {
		this->pAddress = new T * [capcity];
		this->m_capcity = capcity;
		this->m_size = 0;
	}

	// 获取第 i 个数据
	T getByIndex(int i) { return *this->pAddress[i]; }

	//深拷贝
	void deepCopy(MyArray& arr) {
		this->initMyArray(arr.m_capcity);
		int len = this->m_size = arr.m_size;
		for (int i = 0; i < len; i++)
		{
			this->setItem(i, arr.getByIndex(i));
		}
	}
};