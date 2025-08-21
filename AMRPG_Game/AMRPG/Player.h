#pragma once
#include "Renderer.h"

class Player
{
public:
	Player() : x(0), y(0), symbol('@') {}
	void setPosition(int x, int y);
	void move(int dx, int dy);
	void draw(Renderer& r);
	int getX() const { return x; }
	int getY() const { return y; }

private:
	int x, y;
	char symbol;
};

