#include "author.h"

class admin : public User
{
private:
	vector <User> accList;
	int type;

public:
	admin();
	~admin();
	bool isLogin(bool check, int type);
	vector <User> checkout(int type);
};

