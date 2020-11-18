#include "User.h"



User::User()
{
}


User::~User()
{
}

void User::addUser(login newUser)
{
	this->listUser.resize(listUser.size() + 1);
	this->listUser.push_back(newUser);
}

bool User::check(string name, string password, int type)
{
	bool temp = false;
	for (int i = 0; i < listUser.size(); i++)
	{
		if ((listUser[i].username == name) && (listUser[i].password == password) && (listUser[i].type == type))
		{
			temp = true;
			break;
		}
	}
	return temp;
}


