#include "public.h"

// ����
template<class T>
void swap31(T &a, T&b) {
	T temp = a;
	a = b; b = temp;
}

// ����
template<class T>
void sort31(T arr[], int len) {
	for (int i = 0; i < len; i++)	{
		int min = i;
		for (int j = i+1; j < len; j++) {
			if (arr[min] > arr[j]) min = j;
		}

		if(i!= min) swap31(arr[i], arr[min]);
	}
}

// ��ӡ
template<class T>
void showArr(T* arr, int len) {
	for (int i = 0; i < len; i++)	{
		cout <<  arr[i] << ", ";
	}
	cout << endl;
}

void test31() {
	// ���Բ�������
	char charArr[] = "chenglong";
	int len = sizeof(charArr)/sizeof(char);
	sort31<char>(charArr, len);
	showArr<char>(charArr, len);

	// ������������
	int intArr[] = { 1,6,2,4,8,3 };
	int len1 = sizeof(intArr) / sizeof(int);
	sort31<int>(intArr, len1);
	showArr<int>(intArr, len1);
}