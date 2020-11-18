#include <iostream>
#include <string>
using namespace std;
class Sach
{
private:

	string tensach;
	string tacgia;
	string masach;
	int giasach;

public:
	Sach();
	Sach(string& tensach, string& tacgia, string& masach, int& giasach);
	Sach(const Sach&);
	~Sach();
	void input();
	void output();
	string ten();
	string ma();
};
class node
{
public:
	Sach sach;
	node* next;
};
class danhSach
{
private:
	node *head, *tail;
public:
	danhSach();
	void themSach(Sach sach);
	Sach* timSach(string& tensach, string& masach);
};
