#include "book.h"
#include <vector>


class danhSach
{

	
	
public:
	vector<book> list;
	danhSach();
	~danhSach();
	void inputList();
	void outputList();
	bool findBook(const string name, string id, book );
	vector<book> getList();
	//void addBook(book book);
	int getQuantity();
	book setBookFinded(book b);
	book editBook(book b);
};

