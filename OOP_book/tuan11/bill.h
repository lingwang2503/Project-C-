#include "book.h"
#include"danhSach.h"

class bill
{
private:
	string id;
	book* Book;
	int quantity;
	float price;
public:
	bill();
	~bill();
	string getId();
	void addQuantity(int a);
	void pricePlus(float pr);
	int getQuantity();
	float getPrice();
	book* getBook();
	int setBill(string name, int qt, danhSach* list);
	void setQuantity(int q);
	void setPrice(float price);
	void print();
};

