#include "publisher.h"

class author : public danhSach
{
private:
	string name, pass;
	string nameAu;
	vector <book> listBookAu;
	bool checkLogin;
public:
	author();
	author(string name, string pass);
	~author();
	bool isLogin(bool check, int type);
	void IlistBook();
	vector<book> getListBook();
	void printListBook();
	string getAuname();
	void edit(string name);
	vector<book> addBook(book b);
};

