#pragma once
#include "Console.h"


enum BallDirection
{
	STOP, 
	UPLEFT, 
	UPRIGHT,
	DOWNLEFT,
	DOWNRIGHT,
};
class Ball
{
private:
	COORD current;	//vị trí hiện tại
	COORD original;	//vị trí gốc
	float speed;	//tốc độ
	BallDirection direction;
public:
	Ball(int x, int y);
	~Ball();
	//trả về vị trí hiện tại
	COORD getPosition();
	//in quả bóng ra màn hình
	void print();
	//đưa về vị trí gốc
	void reset();
	BallDirection getDirection();
	void changeDirection(BallDirection dir);
	void moveUpRight();
	void moveUpLeft();
	void moveDownRight();
	void moveDownLeft();
	void speedUp();
};

