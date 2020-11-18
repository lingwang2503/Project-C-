#include "danhSach.h"



danhSach::danhSach()
{
	//this->quantity = 0;
	list.resize(0);
}


danhSach::~danhSach()
{

}

void danhSach::inputList() 
{
	int quantity;
	cout << "Nhap so luong sach: ";
	cin >> quantity;
	cout << endl;
	book temp;
	cin.ignore();
	for (int i = 0; i < quantity; i++)
	{
		cout << "Nhap thong tin sach thu " << i + 1 << ": "<< endl;
		cout << endl;
		temp.inputBookUser();
		list.push_back(temp);
		cout << endl;
	}

	cout << endl;
}

void danhSach::outputList() 
{
	cout << "Danh sach sach: " << endl;
	cout << endl;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getName() == "") continue;
		cout << "So thu tu: " << i + 1 << endl;
		list[i].outputBook();
		cout << "===============================" << endl;
	}

	cout << endl;
}

bool danhSach::findBook(string name, string id, book b) 
{
	if ((b.getName() == name) && (b.getID() == id))
	{
		return true;
	}
	else return false;
	
}

vector<book> danhSach::getList() 
{
	return this->list;
}

/*void danhSach::addBook(book book)
{
	this->list[quantity++] = book;
}*/

int danhSach::getQuantity() //số lượng sách
{
	return list.size();
}

/*void danhSach::setQuantity(int q) 
{
	this ->quantity = q;
}*/

book danhSach::setBookFinded(book b)
{
	return b;
}

book danhSach::editBook(book b)
{
	b.inputBookUser();
	return b;
}