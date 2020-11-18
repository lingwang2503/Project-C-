#include "Ball.h"

Ball::Ball(int x, int y)
{
	original.X = current.X = x;
	original.Y = current.Y = y;
	speed = 1;
	direction = STOP;
}

Ball::~Ball()
{
}

COORD Ball::getPosition()
{
	return current;
}

void Ball::print()
{
	gotoXY(current.X, current.Y);
	cout << "o";	//in ra quả bóng
}

void Ball::reset()
{
	current = original;
	speed = 1;
	direction = STOP;
}

BallDirection Ball::getDirection()
{
	return direction;
}

void Ball::changeDirection(BallDirection dir)
{
	direction = dir;
}

void Ball::moveUpRight()
{
	//direction = UPRIGHT;
	clearObj(current.X, current.Y);
	current.X++;
	current.Y--;
	print();
	Sleep(100/speed);
}

void Ball::moveUpLeft()
{
	//direction = UPLEFT;
	clearObj(current.X, current.Y);
	current.X--;
	current.Y--;
	print();
	Sleep(100/speed);
}

void Ball::moveDownRight()
{
	//direction = DOWNRIGHT;
	clearObj(current.X, current.Y);
	current.X++;
	current.Y++;
	print();
	Sleep(100/speed);
}

void Ball::moveDownLeft()
{
	//direction = DOWNLEFT;
	clearObj(current.X, current.Y);
	current.X--;
	current.Y++;
	print();
	Sleep(100/speed);
}

void Ball::speedUp()
{
	speed = speed * 1.1;
}





