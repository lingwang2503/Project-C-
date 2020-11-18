#include "author.h"
#include <vector>
#include <iostream>

using namespace std;
struct login
{
	string username, password;
	int type; //1_guest 2_publisher 3_author
};

class User
{
public:
	vector <guest> guestList;
	vector <publisher> pubList;
	vector <author> auList;
	
	User();
	~User();
	void signup(login& Login);
	bool signin(login& Login, User & user);
	void setUserList();
	//void delUser();
	bool check(string name, string password, int type);

	void addGuest(guest g);
	void addPub(publisher p);
	void addAuthor(author a);
};

