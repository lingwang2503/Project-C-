#include "OMG.h"


OMG::OMG(int w, int h)
{

	ball = new Ball(w / 2, h / 2);
	player1 = new Paddle(1, h / 2);
	player2 = new Paddle(w - 1, h / 2);
	score1 = score2 = 0;
	stop = false;
}

OMG::~OMG()
{
	delete ball;
	delete player1;
	delete player2;
}

void OMG::printMenu(int &choice)
{
	gotoXY(45, 12);
	cout << "------------------------------";
	//lựa chọn chơi lại hoặc thoát game - nhập 1 hoặc 2
	gotoXY(48, 14);
	cout << "Please choose an option: ";
	gotoXY(53, 16);
	cout << "1. PvP";
	gotoXY(53, 17);
	cout << "2. PvE";
	gotoXY(53, 18);
	cout << "3. Quit";
	gotoXY(73, 14);
	
	cin >> choice;
}

void OMG::reset()
{
	ball->reset();
	player1->reset();
	player2->reset();
	score1 = score2 = 0;
	stop = false;
}

void OMG::drawBorders()
{
	gotoXY(0, 0);
	cout << (char)201;	//vẽ góc trên trái
	gotoXY(right, 0);
	cout << (char)187;	//vẽ góc trên phải
	for (int i = 1; i < right; i++)
	{
		gotoXY(i, 0);
		cout << (char)205;	//vẽ cạnh trên
	}
	for (int i = 1; i < bottom; i++)
	{
		gotoXY(0, i);
		cout << (char)186;	//vẽ cạnh trái
		gotoXY(right, i);
		cout << (char)186;	//vẽ cạnh phải
	}
	gotoXY(0, bottom);
	cout << (char)200;	//vẽ góc dưới trái
	gotoXY(right, bottom);
	cout << (char)188;	//vẽ góc dưới phải
	for (int i = 1; i < right; i++)
	{
		gotoXY(i, bottom);
		cout << (char)205;	//vẽ cạnh dưới
	}
}

void OMG::printInstruction(int choice)
{
	gotoXY(81, 5);
	cout << "INSTRUCTION";
	gotoXY(74, 7);
	cout << "Press any key to start the game.";
	gotoXY(80, 10);
	cout << "Player 1: ";
	gotoXY(80, 11);
	cout << "W: UP; S: DOWN.";
	gotoXY(80, 13);
	if (choice == 2)
	{
		cout << "Player 2: ";
		gotoXY(80, 14);
		cout << "I: UP; K: DOWN.";
	}
	gotoXY(72, 17);
	cout << "-----------------------------------";
	
}

void OMG::printScores()
{
	gotoXY(81, 20);
	cout << "Score 1: " << score1;
	gotoXY(81, 21);
	cout << "Score 2: " << score2;
}

void OMG::movePaddles()
{
	if (_kbhit())
	{
		char c = _getch();
		//quả bóng chạy về phía paddle nào thì paddle đó mới có thể di chuyển
		if (ball->getDirection() == UPLEFT || ball->getDirection() == DOWNLEFT)
		{
			if (c == UP1 && player1->getPosition().Y > 4)	//nhấn key up và paddle 1 chưa chạm khung
			{
				player1->moveUp();
			}
			if (c == DOWN1 && player1->getPosition().Y < bottom - 4)	//key xuống và paddle 1 chưa chạm khung
			{
				player1->moveDown();
			}
		}
		else
		{
			if (c == UP2 && player2->getPosition().Y > 4)	//nhấn key up và paddle 2 chưa chạm khung
			{
				player2->moveUp();
			}

			if (c == DOWN2 && player2->getPosition().Y < bottom - 4)	//key xuống và paddle 2 chưa chạm khung
			{
				player2->moveDown();
			}
		}
	
		if (c == ESC)
		{
			stop = true;
		}
	}
}

void OMG::moveBall()
{

	switch (ball->getDirection())
	{
	case STOP:
		if (_kbhit())
		{
			ball->changeDirection((BallDirection)((rand() % 4) + 1));
		}
		break;
	case UPLEFT:
		ball->moveUpLeft();
		break;
	case UPRIGHT:
		ball->moveUpRight();
		break;
	case DOWNLEFT:
		ball->moveDownLeft();
		break;
	case DOWNRIGHT:
		ball->moveDownRight();
	default:
		break;
	}
	if (ball->getPosition().Y == 1)
	{
		BallDirection d = ball->getDirection();
		if (d == UPRIGHT)
		{
			ball->changeDirection(DOWNRIGHT);
		}
		if (d == UPLEFT)
		{
			ball->changeDirection(DOWNLEFT);
		}
	}
	if (ball->getPosition().Y == bottom - 1)
	{
		if (ball->getDirection() == DOWNRIGHT)
		{
			ball->changeDirection(UPRIGHT);
		}
		if (ball->getDirection() == DOWNLEFT)
		{
			ball->changeDirection(UPLEFT);
		}
	}
	if (ball->getPosition().X == player1->getPosition().X + 1)
	{
		if (ball->getPosition().Y <= player1->getPosition().Y + 3 && ball->getPosition().Y >= player1->getPosition().Y - 3)
		{
			score1++;
			ball->speedUp();
			
			if (ball->getDirection() == DOWNLEFT)
			{
				ball->changeDirection(DOWNRIGHT);
			}
			if (ball->getDirection() == UPLEFT)
			{
				ball->changeDirection(UPRIGHT);
			}
		}
		else
		{
			stop = true;
		}
	}
	//
	if (ball->getPosition().X == player2->getPosition().X - 1)
	{
		if (ball->getPosition().Y <= player2->getPosition().Y + 3 && ball->getPosition().Y >= player2->getPosition().Y - 3)
		{
			score2++;
			ball->speedUp();
			if (ball->getDirection() == DOWNRIGHT)
			{
				ball->changeDirection(DOWNLEFT);
			}
			if (ball->getDirection() == UPRIGHT)
			{
				ball->changeDirection(UPLEFT);
			}
		}
		else
		{
			stop = true;
		}
	}
}
void OMG::run(int choice)
{
	system("cls");
	drawBorders();
	player1->print();
	player2->print();
	ball->print();
	printInstruction(choice);
	if (choice == 1)
	{
		while (!stop)
		{
			movePaddles();
			moveBall();
			printScores();
		}
	}
	else if (choice == 2)
	{
		while (!stop)
		{

			autoMovePaddle();
			moveBall();
			printScores();
		}
	}
	reset();
}

//xử lý game over
void OMG::printGameOver()
{
	//GAME OVER 
	system("cls");
	gotoXY(52, 10);
	cout << "CONGRATULATIONS!";
	if (score1 > score2) //nếu điểm 1 lớn hơn điểm 2 thì người chơi 1 chiến thắng
	{
		gotoXY(49, 11);
		cout << "The winner is Player 1.";
	}
	else if (score1 < score2) //mếu điểm 2 lớn hơn điểm 1 thì người chơi 2 chiến thắng
	{
		gotoXY(49, 11);
		cout << "The winner is Player 2.";
	}
	else //điểm bằng nhau thì 2 bên hoà
	{
		gotoXY(53, 11);
		cout << "Both Win!";

	}
	
}

void OMG::autoMovePaddle()
{
	if (_kbhit())
	{
		//xử lí thao tác paddle 1
		if (ball->getDirection() == UPLEFT || ball->getDirection() == DOWNLEFT)
		{
			char c = _getch();
			if (c == UP1 && player1->getPosition().Y > 4)	//nhấn key up và paddle 1 chưa chạm khung
			{
				player1->moveUp();
			}
			if (c == DOWN1 && player1->getPosition().Y < bottom - 4)	//key xuống và paddle 1 chưa chạm khung
			{
				player1->moveDown();
			}
			if (c == ESC)
			{
				stop = true;
			}
		}
	}
	//xử lí thao tác tự động di chuyển paddle 2
	//khi tung độ ball và paddle 2 trùng nhau
	if (ball->getPosition().Y == player2->getPosition().Y)
	{
		switch (ball->getDirection())
		{
		case UPRIGHT:
			if (player2->getPosition().Y > 4)
			{
				player2->moveUp();
			}
			
			break;

		case DOWNRIGHT:
			if (player2->getPosition().Y < bottom - 4)
			{
				player2->moveDown();
			}
			
			break;
		default:
			break;
		}
	}
}
