#include "author.h"



author::author()
{
	this->nameAu = "";
	this->listBookAu.resize(0);
	this->checkLogin = false;
}

author::author(string name, string pass)
{
	this->name = name;
	this->pass = pass;
}

author::~author()
{
}



void author::IlistBook()
{
	for (int i = 0; i < list.size(); i++)
	{
		if (this->list[i].getAuthor() == this->nameAu)
		{
			this->listBookAu.resize(listBookAu.size() + 1);
			this->listBookAu.push_back(list[i]);
		}
	}
}

vector<book> author::getListBook()
{
	return this->listBookAu;
}

void author::printListBook()
{
	for (int i = 0; i < listBookAu.size(); i++)
	{
		listBookAu[i].outputBook();
		cout << endl;
	}
}

string author::getAuname()
{
	return this->nameAu;
}

void author::edit(string name)
{
	bool check = false;
	for (int i = 0; i < listBookAu.size(); i++)
	{
		if (listBookAu[i].getName() == name)
		{
			check = true;
			editBook(this->listBookAu[i]);
			break;
		}
	}
	if (!check) cout << "Khong co sach can tim." << endl;
}

vector<book> author::addBook(book b)
{
	this->listBookAu.resize(listBookAu.size() + 1);
	this->listBookAu.push_back(b);
	return listBookAu;
}

string author::getName()
{
	return this->name;
}

string author::getPass()
{
	return this->pass;
}

void author::setAuName(string name)
{
	this->nameAu = name;
}

void author::setName(string name)
{
	this->name = name;
}

void author::setPass(string pass)
{
	this->pass = pass;
}

void author::printAu(author i)
{
	cout << "Tac gia " << i.getAuname() << endl;
	cout << "Ten dang nhap " << i.getName() << endl;
	cout << "Mat khau " << i.getPass() << endl;
}