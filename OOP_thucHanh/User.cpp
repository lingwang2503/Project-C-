#include "User.h"



User::User()
{
}


User::~User()
{
}


bool User::check(string name, string password, int type)
{
	if (type == 0)
	{
		if ((name == "admin") && (password == "admin123"))
		return true;
	}
	else if (type == 1)
	{
		for (int i = 0; i < guestList.size(); i++)
		{
			if ((name == guestList[i].getName()) && (password == guestList[i].getPass()))
				return true;
		}
	}
	else if (type == 2)
	{
		for (int i = 0; i < pubList.size(); i++)
		{
			if ((name == pubList[i].getName()) && (password == pubList[i].getPass()))
				return true;
		}
	}
	else if (type == 3)
	{
		for (int i = 0; i < auList.size(); i++)
		{
			if ((name == auList[i].getName()) && (password == auList[i].getPass()))
				return true;
		}
	}

}

void User::addGuest(guest g)
{
	guestList.push_back(g);
}

void User::addPub(publisher p)
{
	this->pubList.push_back(p);
}

void User::addAuthor(author a)
{
	this->auList.push_back(a);
}


//add publisher, author 

void User::signup(login& Login)
{
	cout << endl;
	cout << "		DANG KY NGUOI DUNG		" << endl;
	cout << "Ten dang nhap: ";
	cin >> Login.username;
	cout << "Mat khau: ";
	cin >> Login.password;
	cout << "Loai nguoi dung: ";
	cin >> Login.type;
	cout << "======================================" << endl;
	if (Login.type == 1)
	{
		guest Guest(Login.username, Login.password);
		guestList.push_back(Guest);
	}
	else if (Login.type == 2)
	{
		publisher pub(Login.username, Login.password);
		pubList.push_back(pub);
	}
	else if (Login.type == 3)
	{
		author au(Login.username, Login.password);
		auList.push_back(au);
	}
}

bool User::signin(login& Login, User &user)
{
	cout << "		DANG NHAP VAO HE THONG		" << endl;
	cout << "Ten dang nhap: ";
	cin >> Login.username;
	cout << "Mat khau: ";
	cin >> Login.password;
	cout << "Chon nguoi dung: ";
	cin >> Login.type;
	cout << "======================================" << endl;
	bool check = user.check(Login.username, Login.password, Login.type);
	return check;
}



