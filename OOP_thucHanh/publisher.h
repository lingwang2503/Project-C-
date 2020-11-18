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
	
	
	vector <book> getListBook();
	void printListBook();
	string getPubname();
	string getName();
	string getPass();
	void setPubName(string name);
	void setName(string name);
	void setPass(string pass);
	void edit(string name);
	void addBook();
	void printPub(publisher i);
};

