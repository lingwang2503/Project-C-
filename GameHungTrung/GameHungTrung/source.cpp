#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

char map[25][70];

//Hàm resize cửa sổ console
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, 

		height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle

		(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle

		(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , 

		Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle

		(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm in giao diện game.
void GiaoDien()
{
	textcolor(12);
	gotoxy(77,4); cout<<"anhhuu ^_^";
	textcolor(7);
	// Hướng dẫn sử dụng.
	textcolor(11);
	gotoxy(77,6); cout<<"Phim mui ten LEN: di len.";
	gotoxy(77,7); cout<<"Phim mui ten XUONG: di xuong.";
	gotoxy(77,8); cout<<"Phim mui ten TRAI: sang trai.";
	gotoxy(77,9); cout<<"Phim mui ten PHAI: sang phai.";
	gotoxy(77,10); cout<<"P: tam dung.";
	gotoxy(77,11); cout<<"Enter: tiep tuc.";
	gotoxy(77,12); cout<<"Q: thoat.";
	textcolor(7);
}

// Hàm vẽ khung game.
void VeKhung()
{
	//Tạo khung
	for (int i = 0; i < 25; i++)
	{
		//Tạo lề trái khung.
		map[i][0]=' ';
		map[i][1]=' ';
		//Tạo lề phải khung.
		map[i][69]=' ';
		map[i][68]=' ';
	}
	for (int j = 0; j < 70; j++)
	{
		//Tạo lề trên khung.
		map[0][j]=' ';
		//Tạo lề dưới khung.
		map[24][j]=' ';
		//Tạo gạch ngăn cách, vị trí trứng bắt đầu rơi.
		map[3][j]='-';
	}
}

// Hàm vẽ trứng.
void VeTrung(int x, int y)
{
	map[x][y]='o';//Vẽ trứng hình dạng 'o'.
}

// Hàm xoá trứng.
void XoaTrung(int x, int y)
{
	map[x][y]=' ';//Xoá trứng đi.
}

//Hàm in giao diện game.
void InGiaoDien()
{
	cout<<"\n\n";
	for (int i = 0; i < 25; i++)
	{
		cout<<"   ";
		for (int j = 0; j < 70; j++)
		{
			if (i==0||i==24 ||j==0||j==1 || j==68 || j==69 )//In khung ra màn hình
			{
				textcolor(119);//Màu trắng xám cho khung.
				cout<<map[i][j];
				textcolor(7);//Trở về màu text trắng.
			}else if (map[i][j]==':')//In cái khay hứng ra màn hình.
			{
				textcolor(85);//Màu tím cho khay.
				cout << map[i][j];
				textcolor(7);
			}else if (map[i][j]=='-')//In đường phân cách, vị trí trứng rơi.
			{
				textcolor(14);//Màu vàng cho đường phân cách.
				cout << map[i][j];
				textcolor(7);
			}else if (map[i][j]=='o')//In trứng.
			{
				textcolor(12);//Màu đỏ cho trứng.
				cout << map[i][j];
				textcolor(7);
			}else
			{
				//textcolor(240);
				cout<<map[i][j];
				//textcolor(7);
			}
		}
		cout<<endl;
	}
}

// Hàm vẽ khay hứng trứng.
void VeKhay(int x, int y)
{
	map[x][y]= ':';//Trung tâm khay.
	map[x][y-1]= ':';
	map[x][y+1]= ':';
	map[x][y-2]= ':';
	map[x][y+2]= ':';
	map[x][y-3]= ':';
	map[x][y+3]= ':';
	map[x][y-4]= ':';
	map[x][y+4]= ':';
}

// Hàm xoá khay hứng trứng.
void XoaKhay(int x, int y)
{
	map[x][y]= ' ';//Xoá trung tâm khay.
	map[x][y-1]= ' ';
	map[x][y+1]= ' ';
	map[x][y-2]= ' ';
	map[x][y+2]= ' ';
	map[x][y-3]= ' ';
	map[x][y+3]= ' ';
	map[x][y-4]= ' ';
	map[x][y+4]= ' ';
}

void XuLyTrungVaoKhay(int &x, int &y, int &diem)
{
	XoaTrung(x, y);//Xoá trứng cũ đi
	x=0;//Khởi tạo lại hoành độ trứng xuất hiện
	y = (rand()%64+4);
	diem++;//Tăng điểm lên.
	gotoxy(77,17); cout<< "Diem: "<<diem;//In điểm.
}

//Hàm di chuyển khay.
void DiChuyenKhay(int &x, int &y,int &x1, int &y1, int &diem, int &x2, int &y2)
{
	if (GetAsyncKeyState(VK_LEFT))//Get phím mũi tên trái.
	{
		if (y>7)
		{
			//Kiểm tra trứng có rơi vào khay không.
			/*if (map[x][y] == 'o' || map[x][y-1]== 'o' || map[x][y+1]== 'o'|| map[x][y-2] == 'o' || map[x][y+2]== 'o'|| map[x][y-3]== 'o' || map[x][y+3]== 'o'|| map[x][y-4]== 'o' || map[x][y+4]== 'o')
			{
				XoaTrung(x1, y1);//Xoá trứng cũ đi
				XoaTrung(x2, y2);
				x1=0;//Khởi tạo lại hoành độ trứng xuất hiện
				x2=5;
				y1 = (rand()%64+4);
				y2 = (rand()%64+4);
				diem++;//Tăng điểm lên.
				gotoxy(77,17); cout<< "Diem: "<<diem;//In điểm.
			}*/
			
			
			//Kiểm tra trứng thứ 1 có rơi vào khay hay không.
			if (map[x1][y1]==':')
			{
				XuLyTrungVaoKhay(x1,y1,diem);
			}
			
			//Kiểm tra trứng thứ 2 có rơi vào khay hay không.
			if (map[x2][y2]==':')
			{
				XuLyTrungVaoKhay(x2,y2,diem);
			}
			
			XoaKhay(x,y);//Xoá khay cũ đi.
			y-=4;//Tốc độ di chuyển của khay khi sang trái là 4 đơn vị tung độ.
			VeKhay(x, y);//Vẽ lại khay.
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))//Get phím mũi tên phải.
	{
		if (y<62)
		{
			/*if (map[x][y] == 'o' || map[x][y-1]== 'o' || map[x][y+1]== 'o'|| map[x][y-2] == 'o' || map[x][y+2]== 'o'|| map[x][y-3]== 'o' || map[x][y+3]== 'o'|| map[x][y-4]== 'o' || map[x][y+4]== 'o')
			{
				XoaTrung(x1, y1);//Xoá trứng cũ đi
				XoaTrung(x2, y2);
				x1=0;//Khởi tạo lại hoành độ trứng xuất hiện
				x2=5;
				y1 = (rand()%64+4);
				y2 = (rand()%64+4);
				diem++;//Tăng điểm lên.
				gotoxy(77,17); cout<< "Diem: "<<diem;//In điểm.
			}*/

			if (map[x1][y1]==':')
			{
				XuLyTrungVaoKhay(x1,y1,diem);
			}

			//Kiểm tra trứng thứ 2 có rơi vào khay hay không.
			if (map[x2][y2]==':')
			{
				XuLyTrungVaoKhay(x2,y2,diem);
			}
			XoaKhay(x, y);
			y+=4;
			VeKhay(x, y);
		}
	}
	if (GetAsyncKeyState(VK_UP))//Get phím mũi tên lên.
	{
		if (x>4)
		{
			/*if (map[x][y] == 'o' || map[x][y-1]== 'o' || map[x][y+1]== 'o'|| map[x][y-2] == 'o' || map[x][y+2]== 'o'|| map[x][y-3]== 'o' || map[x][y+3]== 'o'|| map[x][y-4]== 'o' || map[x][y+4]== 'o')
			{
				XoaTrung(x1, y1);//Xoá trứng cũ đi
				XoaTrung(x2, y2);
				x1=0;//Khởi tạo lại hoành độ trứng xuất hiện
				x2=5;
				y1 = (rand()%64+4);
				y2 = (rand()%64+4);
				diem++;//Tăng điểm lên.
				gotoxy(77,17); cout<< "Diem: "<<diem;//In điểm.
			}*/


			if (map[x1][y1]==':')
			{
				XuLyTrungVaoKhay(x1,y1,diem);
			}

			//Kiểm tra trứng thứ 2 có rơi vào khay hay không.
			if (map[x2][y2]==':')
			{
				XuLyTrungVaoKhay(x2,y2,diem);
			}
			XoaKhay(x, y);
			x--;
			VeKhay(x, y);
		}
	}
	if (GetAsyncKeyState(VK_DOWN))//Get phím mũi tên xuống.
	{
		if (x<23)
		{
			/*if (map[x][y] == 'o' || map[x][y-1]== 'o' || map[x][y+1]== 'o'|| map[x][y-2] == 'o' || map[x][y+2]== 'o'|| map[x][y-3]== 'o' || map[x][y+3]== 'o'|| map[x][y-4]== 'o' || map[x][y+4]== 'o')
			{
				XoaTrung(x1, y1);//Xoá trứng cũ đi
				XoaTrung(x2, y2);
				x1=0;//Khởi tạo lại hoành độ trứng xuất hiện
				x2=5;
				y1 = (rand()%64+4);
				y2 = (rand()%64+4);
				diem++;//Tăng điểm lên.
				gotoxy(77,17); cout<< "Diem: "<<diem;//In điểm.
			}*/


			if (map[x1][y1]==':')
			{
				XuLyTrungVaoKhay(x1,y1,diem);
			}

			//Kiểm tra trứng thứ 2 có rơi vào khay hay không.
			if (map[x2][y2]==':')
			{
				XuLyTrungVaoKhay(x2,y2,diem);
			}
			XoaKhay(x, y);
			x++;
			VeKhay(x, y);
		}
	}
}



int main()
{
	resizeConsole(1000,500);//resize màn hình console.
	int x=22, y=35;//Toạ độ gốc của khay hứng.
	int x1=0, y1=38;//Toạ độ gốc của trứng.
	int x2=5, y2=13;
	int diem=0;
	GiaoDien();//In giao diện
	
	while(true)
	{
	lenday: 
		VeKhung();
		VeTrung(x1, y1);
		VeTrung(x2, y2);
		VeKhay(x,y);
		XoaManHinh();
		InGiaoDien();
		DiChuyenKhay(x,y,x1,y1, diem,x2,y2);
		srand(time(0));
		
		//Kiểm tra trứng thứ 1 có rơi vào khay hay không.
		if (map[x1][y1]==':')
		{
			XuLyTrungVaoKhay(x1,y1,diem);
		}
		else
		{
			XoaTrung(x1, y1);
			//XoaTrung(x2, y2);
			x1++;//Tăng x lên làm trứng di chuyển xuống dưới.
			//x2++;
		}
		//Kiểm tra trứng thứ 2 có rơi vào khay hay không.
		if (map[x2][y2]==':')
		{
			XuLyTrungVaoKhay(x2,y2,diem);
		}
		else
		{
			XoaTrung(x2, y2);
			//XoaTrung(x2, y2);
			x2++;//Tăng x lên làm trứng di chuyển xuống dưới.
			//x2++;
		}
		
		if (x1> 25||x2>25)//Điều kiện thua.
		{
			char tiep;
			textcolor(10);
			gotoxy(77, 23); cout<<"Rat tiec, ban da thua...\n";
			gotoxy(77, 24); cout<<"Diem cua ban la: "<< diem<< endl;
			gotoxy(77, 25); cout<<"Ban muon choi tiep? [y/n]: ";
			textcolor(7);
			cin >> tiep;
			if (tiep == 'y'||tiep=='Y')//Nếu chọn 'y' thì tiếp tục.
			{
				diem=0;//Khởi tạo lại điểm
				x1=0;//Khởi tạo lại hoành độ trứng xuất hiện
				x2=5;
				y1 = (rand()%64+4);
				y2 = (rand()%64+4);
				system("cls");//Xoá màn hình đi.
				GiaoDien();//In giao diện hướng dẫn.
				goto lenday;//Nhảy về đầu vòng lặp while(true).
			}else
			{
				break;//Thoát game.
			}
		}
		Sleep(0);
		
		if (_kbhit())
		{
			char key = getch();
			if (key == 'p'|| key =='P')//Ấn 'P' thì dừng màn hình.
			{
				getch();
			}
			if (key == 'q'|| key =='Q')//Ấn 'Q' thì thoát.
			{
				break;//Thoát.
			}
		}
	}
	return 0;
}