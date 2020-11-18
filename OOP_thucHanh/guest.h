#include "bill.h"
class guest : public danhSach
{
private:
	string name, pass;
	bill DonHang;
	//list bill của khách hàng
public:
	guest();
	~guest();
	guest(string name, string pass);
	string getName();
	string getPass();
	void findBookbyGuest(danhSach l);
	void getBill();
	
	void setUserName(string s);
	void setPassword(string s);
	void printGuest(guest i);
};

