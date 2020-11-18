#include "author.h"


int main(int argc, const char* argv[])
{
	danhSach danhsach;
	bill HoaDon;
	vector<guest> GuestList;
	vector<publisher> pubList;
	vector<author> auList;
	book sach;
	User account;

	danhsach.inputList();
	cout << "-----------------------------" << endl;
	danhsach.outputList();
	
	cout << "=======================================" << endl;
	login Login;
	User user;
	cout << "		DANG NHAP VAO HE THONG		" << endl;
	cout << "Ten dang nhap: ";
	cin >> Login.username;
	cout << "Mat khau: ";
	cin >> Login.password;
	cout << "Chon nguoi dung: ";
	cin >> Login.type;
	cout << "======================================" << endl;
	bool check = user.check(Login.username, Login.password, Login.type);

	cout << endl;
	cout << "		DANG KY NGUOI DUNG		" << endl;
	cout << "Ten dang nhap: ";
	cin >> Login.username;
	cout << "Mat khau: ";
	cin >> Login.password;
	cout << "Loai nguoi dung: ";
	cin >> Login.type;
	cout << "======================================" << endl;
	account.addUser(Login);
	if (Login.type == 1)
	{
		guest Guest(Login.username, Login.password);
		GuestList.resize(GuestList.size() + 1);
		GuestList.push_back(Guest);
	}
	else if (Login.type == 2)
	{
		publisher pub(Login.username, Login.password);
		pubList.resize(pubList.size() + 1);
		pubList.push_back(pub);
	}
	else if (Login.type == 3)
	{
		author au(Login.username, Login.password);
		auList.resize(auList.size() + 1);
		auList.push_back(au);
	}

	
	system("pause");
	return 0;
}