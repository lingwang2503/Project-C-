#include "bill.h"

struct login
{
	string username, password;
	int type; //1_guest 2_publisher 3_author
};

class User
{
public:
	vector<login> listUser;
	
	User();
	~User();
	void addUser(login newUser);
	void delUser();
	bool check(string name, string password, int type);
	vector<login> getAnUser(int type);

};

