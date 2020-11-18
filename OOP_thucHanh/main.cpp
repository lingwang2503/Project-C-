#include "Source.h"

//admin: username admin
//		 password admin123

int main(int argc, const char* argv[])
{
	/*mở và đọc file sách vào danh sách kiểu danhSach*/
	danhSach listBook;
	/*fstream l;
	l.open("danhSach.txt");
	if (!l)
	{
		cout << "Can open file danhSach." << endl;
		return 0;
	}
	else
	{
		vector<book> data = listBook.getList();
		
		l.close();
	}
	*/
	run(listBook);


	
	system("pause");
	return 0;
}