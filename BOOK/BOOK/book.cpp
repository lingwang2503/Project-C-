#include "book.h"



book::book() 
{
	this->name = "";
	this->id = "";
	this->author = "";
	this->publisher = "";
	this->price = 0;
}

book:: book(string name, string id, string author,
	string publisher, float price)
{
	this->name = name;
	this->id = id;
	this->author = author;
	this->publisher = publisher;
	this->price = price;
}
book::~book()
{
	this->name = "";
	this->id = "";
	this->price = 0;
}

string book::getName() {
	return this->name;
}


string book::getAuthor()
{
	return this->author;
}

string book::getPublisher()
{
	return this->publisher;
}

string book::getID() {
	return this->id;
}

void book::setName(string name) {
	this->name = name;
}

void book::setAuthor(string author)
{
	this->author = author;
}

void book::setPublisher(string publisher)
{
	this->publisher = publisher;
}

void book::setId(string id) {
	this->id = id;
}

float book::getPrice() {
	return this->price;
}
void book::setPrice(float price) {
	this->price = price;
}

void book::inputBookUser()
{
	string temp;
	float price;

	cout << "Nhap ten sach: ";
	getline(cin, temp);
	this->setName(temp);

	cout << "Nhap id: ";
	cin >> temp;
	this->setId(temp);

	cout << "Nhap gia sach: ";
	cin >> price;
	this->setPrice(price);

	cout << "Nhap tac gia: ";
	getline(cin, temp);
	this->setAuthor(temp);

	cout << "Nhap nxb: ";
	getline(cin, temp);
	this->setPublisher(temp);
	cin.ignore(1);
}

void book ::outputBook()
{
	cout << "Ten sach: " << this->getName() << endl;
	cout << "Tac Gia: " << this->getAuthor() << endl;
	cout << "NXB: " << this->getPublisher() << endl;
	cout << "Id: " << this->getID() << endl;
	cout << "Gia sach: " << this->getPrice() << endl;
}

