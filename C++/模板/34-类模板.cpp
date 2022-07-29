#include "public.h"

// ÀàÄ£°å
template<class nameT, class ageT>
class Person34 {
public:
	Person34(nameT name, ageT age) {
		this->name = name;
		this->age = age;
	}
	void showPerson() {
		cout << "name: " << name << " age: " << age << endl;
	}
	nameT name;
	ageT age;
};

void test34() {
	Person34<string, int> cl("³ÌÁú", 34);
	cl.showPerson();
}