#include "User.h"

class admin : public User
{
private:
	string name, pass;
	int type;
	User account;

public:
	admin();
	admin(string name, string pass, int type);
	~admin();
	void setName(string name);
	void setPass(string pass);
	string getName();
	string getPass();
	bool isLogin(bool check, int type);
	void checkout(User acc); //cau 1
};

