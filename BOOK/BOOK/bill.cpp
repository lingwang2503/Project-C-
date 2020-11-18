#include "bill.h"



bill::bill()
{
	listBuy.resize(0);
	priceTotal = 0;
}


bill::~bill()
{

}

bookBuy bill::setBookBuy(book finded, int sl)
{
	this->Book.name = finded.getName();
	this->Book.donGia = finded.getPrice();
	this->Book.soLuong = sl;
	this->Book.Price = this->Book.donGia * sl;
	return Book;
}


void bill::setBill(bookBuy Book)
{
	this->listBuy.resize(this->listBuy.size() + 1);
	this->listBuy.push_back(Book);
	this->priceTotal = this->priceTotal + Book.Price;
}

float bill::getPriceTotal()
{
	return this->priceTotal;
}

void bill::printBill()
{
	cout << endl;
	cout << "		HOA DON THANH TOAN		" << endl;
	cout << "Ten sach	So luong	Don gia" << endl;
	for (int i = 0; i < this->listBuy.size(); i++)
	{
		cout << this->listBuy[i].name << "	" << this->listBuy[i].soLuong << "			" << this->listBuy[i].donGia << endl;
	}
	cout << "====================================" << endl;
	cout << "Thanh tien	" << this->priceTotal << endl;
	
}

