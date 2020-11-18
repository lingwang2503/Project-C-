#include "guest.h"



guest::guest()
{
	name = "";
	pass = "";
	age = 0;
	sex = true;
}


guest::~guest()
{
}

guest::guest(string name, string pass, int age, bool sex) //: User(name, pass)
{
	this->name = name;
	this->pass = pass;
	this->age = age;
	this->sex = sex;
}

int guest::getAge() {
	return age;
}

bool guest::getSex() {
	return sex;
}

void guest::findBook(danhSach* list)
{
	string name;
	cout << "Nhap ten sach: ";
	cin >> name;

	book* Book = list->findBook(name);
	if (Book) {
		cout << "Da tim thay sach. " << endl;
		Book->outputBook();
		return;
	}
	cout << "Ko tim thay sach." << endl;
}

