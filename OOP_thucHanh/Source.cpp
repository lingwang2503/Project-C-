#include "Source.h"

void run(danhSach danhsach)
{
	bill HoaDon;
	book sach;
	User account;
	admin ad;
	guest cus;
	publisher pub;
	author au;

	int Type;

	string name, pass;
	string Name;
	fstream f;
	fstream l;
	f.open("guest.txt");
	//doc file
	if (!f)
		cout << "Failed to open file." << endl;
	else
	{
		while (!f.eof())
		{

			f >> Type;
			if (Type == 0)
			{

				f >> name;
				ad.setName(name);
				f >> pass;
				ad.setPass(pass);


			}
			if (Type == 1)
			{

				f >> name;
				cus.setUserName(name);
				f >> pass;
				cus.setPassword(pass);
				account.addGuest(cus);


			}
			if (Type == 2)
			{

				f >> name;
				pub.setName(name);
				f >> pass;
				pub.setPass(pass);
				getline(f, Name);
				pub.setPubName(Name);
				account.addPub(pub);


			}
			if (Type == 3)
			{

				f >> name;
				au.setName(name);
				f >> pass;
				au.setPass(pass);
				getline(f, Name);
				au.setAuName(Name);
				account.addAuthor(au);


			}

		}

	}



	//đăng ký hoặc đăng nhập
	cout << "=======================================" << endl;
	login Login;
	bool check = false;
	int choose;
	cout << "1. Dang ky" << endl;
	cout << "2. Dang nhap" << endl;
	cout << "Chon: ";
	cin >> choose;
	//đăng nhập
	if (choose == 2)
	{
		check = account.signin(Login, account); //thực hiện đăng nhập
		if (check) cout << "Dang nhap thanh cong" << endl;

		else cout << "Dang nhap that bai. Moi dang nhap lai hoac dang ky" << endl;
		cout << endl;
	}
	//đăng ký
	else if (choose == 1)
	{
		account.signup(Login);//thực hiện đăng ký 
		//ghi file tại đây
	}


	if ((check) && (Login.type == 0)) //admin -> xuất ra list các tài khoản
	{

		cout << "=============================================" << endl;
		cout << endl;
		/*int c;
		cout << "1. In ra danh sach cac tai khoan." << endl;
		cout << "2. In ra tat ca sach trong nha sach." << endl;
		cout << "3. Them sach." << endl;
		
		cin >> c;
		cout << endl;
		if (c == 1)
		{*/
			cout << "Danh sach cac tai khoan" << endl;
			ad.checkout(account);
		/*}
		else if (c == 2)
		{

		}
		else if (c == 3)
		{
			danhSach listBookInput;
			listBookInput.inputList();
			
			l.open("danhSach.txt");
			if (!l)
			{
				cout << "Can open file danhSach." << endl;
			}
			else
			{
				vector<book> data = listBookInput.getList();
				for (int i = 0; i < data.size(); i++)
				{
					l << data[i].getName();
					l << " ";
					l << data[i].getID();
					l << " ";
					l << data[i].getPrice();
					l << " ";
					l << data[i].getPublisher();
					l << " ";
					l << data[i].getAuthor();
					l << "\n";
				}
				l.close();
			}
		}*/



		
	}
	else if ((check) && (Login.type == 1)) // guest 
	{
	

		int choose;
		cout << "1. Tim mua sach" << endl;
		cout << "2. Xem hoa don cua ban" << endl;
		cout << "Ban muon: ";
		cin >> choose;
		if (choose == 1) 
		{
			cus.findBookbyGuest(danhsach); //thực hiện tìm sách
		}
		else if (choose == 2) // xuất ra hoá đơn
		{
			cus.getBill();
		}
	}

	f.close();
}