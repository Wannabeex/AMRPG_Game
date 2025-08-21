#pragma once
#include <iostream>
#include <windows.h>

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

class Renderer
{
public:
	void clearScreen();
	void drawAt(int x, int y, char c);
	void drawString(int x, int y, const char* str);
	void present();
	void hideCursor();
	void showCursor();

private:
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
};

