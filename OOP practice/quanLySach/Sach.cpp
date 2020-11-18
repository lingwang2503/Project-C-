#include "Header.h"

Sach::Sach()
{
	masach = ' ';
	giasach = 0;
	tensach = ' ';
	tacgia = ' ';
}

Sach::Sach(string& tensach, string& tacgia, string& masach, int& giasach)
{
	this->tensach = tensach;
	this->tacgia = tacgia;
	this->masach = masach;
	this->giasach = giasach;
}

Sach::Sach(const Sach&sach)
{
	tensach = sach.tensach;
	tacgia = sach.tacgia;
	masach = sach.masach;
	giasach = sach.giasach;
}

Sach::~Sach()
{

}

void Sach::input()
{
	cout << "Nhap ten sach: ";
	getline(cin, tensach);
	cout << "Nhap tac gia: ";
	getline(cin, tacgia);
	cout << "Nhap ma sach: ";
	getline(cin, masach);
	cout << "Nhap gia sach: ";
	cin >> giasach;
}

void Sach::output()
{
	cout << "Sach : " << tensach << endl;
	cout << "Tac gia: " << tacgia << endl;
	cout << "Ma sach: " << masach << endl;
	cout << "Gia sach: " << giasach << endl;
}

string Sach::ten()
{
	string Ten = tensach;
	return Ten;
}

string Sach::ma()
{
	string Ma = masach;
	return Ma;
}