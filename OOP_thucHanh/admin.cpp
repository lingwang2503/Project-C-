#include "admin.h"



admin::admin()
{

}

admin::admin(string name, string pass, int type)
{
	this->setName(name);
	this->setPass(pass);
	this->type = type;
}

admin::~admin()
{
}

void admin::setName(string name)
{
	this->name = name;
}

void admin::setPass(string pass)
{
	this->pass = pass;
}

bool admin::isLogin(bool check, int type)
{
	if ((check) && (type == 0))
		return true;
	else return false;
}

string admin::getName()
{
	return this->name;
}

string admin::getPass()
{
	return this->pass;
}



//cau 1
void admin::checkout(User acc)
{
	cout << "ADMIN" << endl;
	cout << "Ten dang nhap: " << this->getName() << endl;
	cout << "Mat khau: " << this->getPass() << endl;
	cout << "------------------------------------------" << endl;
	cout << "KHACH HANG " << endl;
	cout << endl;
	for (int i = 0; i < acc.guestList.size(); i++)
	{
		acc.guestList[i].printGuest(acc.guestList[i]);
		cout << endl;
	}
	cout << "------------------------------------------" << endl;
	cout << "NHA XUAT BAN" << endl;
	cout << endl;
	for (int i = 0; i < acc.pubList.size(); i++)
	{
		acc.pubList[i].printPub(acc.pubList[i]);
		cout << endl;
	}
	cout << "------------------------------------------" << endl;
	cout << "TAC GIA" << endl;
	cout << endl;
	for (int i = 0; i < acc.auList.size(); i++)
	{
		acc.auList[i].printAu(acc.auList[i]);
		cout << endl;
	}
	cout << "------------------------------------------" << endl;
}