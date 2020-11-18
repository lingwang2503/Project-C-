#include "bill.h"



bill::bill()
{
	id = "";
	Book = NULL;
	quantity = 0;
	price = 0;
}


bill::~bill()
{
}

int bill::setBill(string name, int qt, danhSach* list)
{
	for (int i = 0; i < list->getQuantity(); i++)
	{
		book *temp = &list->getList()[i];
		if (temp->getName() == name) {
			this->id = temp->getID();
			Book = temp;
			quantity = qt;
			price = qt * temp->getPrice();
			return 1;
		}
	}
	return 0;
}

void bill::setQuantity(int q)
{
	this->quantity = q;
}

void bill::setPrice(float price)
{
	this->price = price;
}

string bill::getId() 
{
	return id;
}

void bill::addQuantity(int a) {
	quantity += a;
}

void bill::pricePlus(float pr) {
	price += pr;
}

int bill::getQuantity() {
	return quantity;
}

float bill::getPrice() {
	return price;
}