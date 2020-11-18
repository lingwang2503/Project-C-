#include "Paddle.h"



Paddle::Paddle(int x, int y)
{
	original.X = current.X = x;
	original.Y = current.Y = y;
}

Paddle::~Paddle()
{

}

COORD Paddle::getPosition()
{
	return current;
}

void Paddle::print()
{
	int x = current.X;
	int y;
	for (int i = -3; i <= 3; i++)	//paddle chiếm 7 cells trên console
	{
		y = current.Y + i;
		gotoXY(x, y);	//đưa con trỏ đến vị trí cần in
		cout << "\xDB";
	}
}

void Paddle::reset()
{
	current = original;
}

void Paddle::moveUp()
{
	int x = current.X;
	int y;
	for (int i = -3; i <= 3; i++)	//xoá paddle vị trí hiện tại
	{
		y = current.Y + i;
		clearObj(x, y);
	}
	current.Y--;	//đưa vị trí hiện tại của paddle lên
	print();	//in lại paddle
	Sleep(25);	//sleep để thấy di chuyển
}

void Paddle::moveDown()
{
	int x = current.X;
	int y;
	for (int i = -3; i <= 3; i++)	//xoá paddle vị trí hiện tại
	{
		y = current.Y + i;
		clearObj(x, y);
	}
	current.Y++;	//đưa vị trí paddle xuống
	print();	//in lại paddle
	Sleep(25);	//sleep để thấy di chuyển
}
