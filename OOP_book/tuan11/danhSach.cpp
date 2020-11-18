#include "danhSach.h"



danhSach::danhSach()
{
}


danhSach::~danhSach()
{
}

void danhSach::inputList() {
	cout << "Nhap so luong sach: ";
	cin >> quantity;
	cin.ignore(1);

	for (int i = 0; i < quantity; i++)
	{
		cout << "Nhap sach thu " << i + 1 << ": "<< endl;
		list[i].inputBookGeneral();
	}

	cout << endl;
}

void danhSach::outputList() {
	cout << "Danh sach sach: " << endl;

	for (int i = 0; i < quantity; i++)
	{
		if (list[i].getName() == "") continue;
		cout << "So thu tu: " << i + 1 << endl;
		list[i].outputBook();
	}

	cout << endl;
}

book* danhSach::findBook(string name) {
	string temp;

	for (int i = 0; i < quantity; i++)
	{
		temp = list[i].getName();
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		transform(name.begin(), name.end(), name.begin(), ::tolower);

		if (temp == name) {
			return &list[i];
		}
	}

	return NULL;
}

book* danhSach::getList() {
	return list;
}

void danhSach::addBook(book book)
{
	this->list[quantity++] = book;
}

int danhSach::getQuantity() 
{
	return quantity;
}

void danhSach::setQuantity(int q) 
{
	this ->quantity = q;
}