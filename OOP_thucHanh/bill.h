#include"danhSach.h"

struct bookBuy
{
	string name;
	int soLuong;
	float Price, donGia;
};
class bill
{
private:
	bookBuy Book;
	vector<bookBuy> listBuy;
	float priceTotal;
public:
	bill();
	~bill();
	bookBuy setBookBuy(book finded, int sl);
	void setBill(bookBuy Book);
	float getPriceTotal();
	void printBill();
};
