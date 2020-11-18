#include "guest.h"


class publisher : public danhSach
{
private:
	string name, pass;
	string namePub;
	vector <book> listBook;
	bool checkLogin;
public:
	publisher();
	publisher(string name, string pass);
	~publisher();
	bool isLogin(bool check, int type);
	void IlistBook();
	vector<book> getListBook();
	void printListBook();
	string getPubname();
	void edit(string name);
	vector<book> addBook(book b);
	void setUserName(string s);
	void setPassword(string s);
};

