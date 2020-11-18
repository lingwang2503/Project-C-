#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

//hàm lấy kích thước console
void getConsoleSize(int& width, int& height);
//hàm trỏ đến vị trí x y
void gotoXY(int x, int y);
//hàm xoá đối tượng tại vị trí x y
void clearObj(int x, int y);
//hàm ẩn con trỏ nhấp nháy
void hideCursor();	//tham khảo