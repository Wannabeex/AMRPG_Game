#pragma once
#include <iostream>

class Renderer
{
public:
	void clearScreen();
	void drawAt(int x, int y, char c);
	void present();
	void hideCursor();
	void showCursor();
};

