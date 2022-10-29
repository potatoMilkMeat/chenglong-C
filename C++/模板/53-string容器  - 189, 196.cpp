#include "public.h"

// string的构造函数
void newString() {
	string s1;
	const char* str = "hello world!";
	string s2(str);

	cout << "s2 = " << s2 << endl;

	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(10, 'a');
	cout << "s4 = " << s4 << endl;
}

// string的赋值操作
void assignString() {
	string str1;
	str1 = "hello world!";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'c';
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello world! 444");
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("hello C++!", 7);
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(10, 'w');
	cout << "str7 = " << str7 << endl;
}

// string的拼接
void appendString() {
	string str1 = "我";
	str1 += "爱读书";
	cout << "str1 = " << str1 << endl;

	str1 += ',';
	cout << "str1 = " << str1 << endl;

	str1 += str1;
	cout << "str1 = " << str1 << endl;

	string str2 = "你";
	str2.append("是工人");
	cout << "str2 = " << str2 << endl;

	str2.append(":12345. 9123456", 8);
	cout << "str2 = " << str2 << endl;

	str2.append(str2);
	cout << "str2 = " << str2 << endl;

	str2.append(str2, 0, 2); // 开始位置，截取长度，中文占2个字符
	cout << "str2 = " << str2 << endl;
}

// string的查找和替换
void findString() {
	string str1 = "abcdefgde";
	int pos = str1.find("de"); // -1 未找到字符串或字符
	cout << "pos: " << pos << endl;

	// rfind 是从右往左查，find 是从左到右
	pos = str1.rfind("de"); // -1 未找到字符串或字符
	cout << "pos: " << pos << endl;
}
void replaceString() {
	string str1 = "abcdefgde";
	str1.replace(1, 3, "1111"); // 位置，长度，替换的内容
	// 先删除，后全部添加进去
	cout << "str1: " << str1 << endl;
}

// string的字符串比较 [-1, 0, 1]  <, =, >
void compareString() {
	string str1 = "abcdefg";
	int cop = str1.compare("abcdefg");
	cout << "cop: " << cop << endl;

	string str2 = "abcdeff";
	cop = str1.compare(str2);
	cout << "cop: " << cop << endl;
}

// string的存取 []  at(int)
void atString() {
	string str1 = "abcdefg";
	cout << "str1[2] " << str1[2] << endl;
	str1[2] = 'x';
	cout << "str1[2] " << str1.at(2) << endl;
}

// string的插入和删除 erase
void insertString() {
	string str = "abcdefg";
	str.insert(0, "xxxx");
	cout << "str:  " << str << endl;

	str.erase(0, 4);
	cout << "str:  " << str << endl;
}

// 子串获取
void substrString() {
	string str = "abcdefg";

	string str1 = str.substr(1, 3);
	cout << "str1:  " << str1 << endl;
}

void test53() {
	// newString();
	// assignString();
	// appendString();

	//findString();
	//replaceString();

	//compareString();

	//atString();
	//insertString();
	substrString();
}