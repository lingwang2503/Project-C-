
#include "User.h"
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
	
	void findBookbyGuest(danhSach l);
	void getBill();
	bool isLogin(bool check, int type);
	void setUserName(string s);
	void setPassword(string s);
};

