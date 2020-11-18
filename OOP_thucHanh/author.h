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
	
	void IlistBook();
	vector<book> getListBook();
	void printListBook();
	string getAuname();
	string getName();
	string getPass();
	void setAuName(string name);
	void setName(string name);
	void setPass(string pass);
	void edit(string name);
	vector<book> addBook(book b);
	void printAu(author i);
};

