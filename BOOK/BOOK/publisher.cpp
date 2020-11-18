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

bool publisher::isLogin(bool check, int type)
{
	if ((check) && (type == 2))  
		this->checkLogin = true;
	else this->checkLogin = false;
	return this->checkLogin;
}

void publisher::IlistBook()
{
	for (int i = 0; i < list.size(); i++)
	{
	if (this->list[i].getPublisher() == this->namePub)
		{
		this->listBook.resize(listBook.size() + 1);
		this->listBook.push_back(list[i]);
		}
	}
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
	for (int i = 0; i < listBook.size(); i++)
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

vector<book> publisher::addBook(book b)
{
	this->listBook.resize(listBook.size() + 1);
	this->listBook.push_back(b);
	return listBook;
}

void publisher::setUserName(string s)
{
	this->name = s;
}

void publisher::setPassword(string s)
{
	this->pass = s;
}