#include "danhSach.h"
#include "bill.h"
class guest
{
private:
	string name, pass;
	int age;
	bool sex;
	bill listBill;
public:
	guest();
	~guest();
	guest(string name, string pass, int age, bool sex);
	int getAge();
	bool getSex();
	void findBook(danhSach* list);
	void addBill(bill b);
	bill getListBill();
	void buyBook(danhSach* list);
};

