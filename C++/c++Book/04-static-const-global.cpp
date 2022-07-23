#include <iostream>
using namespace std;
#include <string>

int g_a = 10;
int g_b = 10;
const int c_g_a = 10;
const int c_g_b = 10;
void msg(string msg, int* p) {
	cout << msg << "的地址： \t" << (int)p << endl;
}
void msg(string msg, const int* p) {
	cout << msg << "的地址： \t" << (int)p << endl;
}

void main04() {
	msg("g_a", &g_a);
	msg("g_b", &g_b);

	static int s_a = 10;
	static int s_b = 10;
	msg("s_a", &s_a);
	msg("s_b", &s_b);

	msg("c_g_a", &c_g_a);
	msg("c_g_b", &c_g_b);

	const int c_l_a = 10;
	const int c_l_b = 10;
	msg("c_l_a", &c_l_a);
	msg("c_l_b", &c_l_b);

	system("pause");
}