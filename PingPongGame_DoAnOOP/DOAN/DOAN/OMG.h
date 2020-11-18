#pragma once
#include <conio.h>
#include <thread>

#include "Console.h"
#include "Ball.h"
#include "Paddle.h"


enum move	//các phím nhận di chuyển của paddle và thoát game
{
	UP1 = 'w',
	DOWN1 = 's',
	UP2 = 72,
	DOWN2 = 80,
	ESC = 27,
};
#define right 58	//vị trí border phải
#define bottom 28	//border duối

class OMG
{
private:
	
	Ball* ball;	//quả bóng
	Paddle* player1, * player2;	//hai paddle chơi
	int score1, score2;	//điểm
	bool stop;	//biến quản lí dừng chơi
public:

	OMG(int w, int h);
	~OMG();
	//in menu chơi
	void printMenu(int &choice);
	//reset game
	void reset();
	//vẽ khung
	void drawBorders();
	//viết hướng dẫn
	void printInstruction(int choice);
	//in điểm
	void printScores();
	//xử lí di chuyển cho thanh trượt
	void movePaddles();
	//xử lí di chuyển ball
	void moveBall();
	//celebrateeeeeee
	void run(int choice);
	//in người thắng
	void printGameOver();
	//tự động di chuyển thanh trượt 2
	void autoMovePaddle();
};

