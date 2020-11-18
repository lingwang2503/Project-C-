#include "guest.h"



guest::guest()
{
	name = "";
	pass = "";

}


guest::~guest()
{
}

guest::guest(string name, string pass) 
{
	this->name = name;
	this->pass = pass;
	
	
}


/*void guest::addListBill(bill b)
{
	this->listBill.resize(listBill.size() + 1);
	this->listBill.push_back(b);
}*/

void guest::findBookbyGuest(danhSach l)
{
	bool continueBuy = true;
	book finded;
	bool check = false;
	string name, id;
	int mua = 0;
	while (continueBuy)
	{
		cin.ignore();
		cout << "Nhap ten sach can tim: ";
		getline(cin, name);
		cout << "Nhap id sach can tim: ";
		getline(cin, id);
		for (int i = 0; i < l.list.size(); i++)
		{
			check = findBook(name, id, l.list[i]);

			if (check == true)
			{
				finded = setBookFinded(l.list[i]);
				cout << endl;
				finded.outputBook();
				cout << endl;
				cout << "Ban co muon mua sach khong? ";
				cin >> mua;
				if (mua == 1)
				{
					int sl;
					cout << "Nhap so luong sach can mua: ";
					cin >> sl;

					DonHang.setBill(DonHang.setBookBuy(finded, sl));

				}
				break;
			}
			
		}
		if (check == false) cout << "Khong co sach can tim." << endl;
		mua = 0;
		cout << "Ban co muon tiep tuc mua sach?";
		cin >> mua;
		if (mua == 1)
			continueBuy = true;
		else
		{
				continueBuy = false;
				break;
		}
	}

}

void guest::getBill()
{
	this->DonHang.printBill();
}

bool guest::isLogin(bool check, int type)
{
	if ((check) && (type == 1))
		return true;
	else return false;
}

void guest::setUserName(string s)
{
	this->name = s;
}

void guest::setPassword(string s)
{
	this->pass = s;
}