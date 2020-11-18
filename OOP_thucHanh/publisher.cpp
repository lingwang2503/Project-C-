#include "publisher.h"



publisher::publisher() 
{
	this->namePub = "";
	this->listBook.resize(0);
	this->checkLogin = false;
}

publisher::publisher(string name, string pass)
{
	this->name = name;
	this->pass = pass;
}

publisher::~publisher()
{

}




vector<book> publisher::getListBook()
{
	return this->listBook;
}

void publisher ::printListBook()
{
	for (int i = 0; i < listBook.size(); i++)
	{
		listBook[i].outputBook();
		cout << endl;
	}
}

string publisher::getPubname()
{
	return this->namePub;
}

void publisher::edit(string name)
{
	bool check = false;
	for (int i = 0; i <listBook.size(); i++)
	{
		if (listBook[i].getName() == name)
		{
			check = true;
			editBook(this->listBook[i]);
			break;
		}
	}
	if (!check) cout << "Khong co sach can tim." << endl;
}

void publisher::addBook()
{
	inputList();

}

string publisher::getName()
{
	return this->name;
}

string publisher::getPass()
{
	return this->pass;
}

void publisher::setPubName(string name)
{
	this->namePub = name;
}

void publisher::setName(string name)
{
	this->name = name;
}

void publisher::setPass(string pass)
{
	this->pass = pass;
}

void publisher::printPub(publisher i)
{
	cout << "Nha xuat ban " << i.getPubname() << endl;
	cout << "Ten dang nhap " << i.getName() << endl;
	cout << "Mat khau " << i.getPass() << endl;
}