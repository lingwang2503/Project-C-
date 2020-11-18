#include "book.h"
#include <algorithm> 

class danhSach
{
private:
	book list[100];
	int quantity;
public:
	danhSach();
	~danhSach();
	void inputList();
	void outputList();
	book* findBook(const string name);
	book* getList();
	void addBook(book book);
	int getQuantity();
	void setQuantity(int q);
};

