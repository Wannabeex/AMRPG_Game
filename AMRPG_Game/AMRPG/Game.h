#pragma once
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include "Input.h"
#include "Player.h"
#include "Renderer.h"
#include "Wall.h"

class Game
{
public:
	Game();
	void init();
	void run();
	void cleanup();

private:
	bool running;
	Input input;
	Player player;
	Renderer gfx;

	std::vector<Wall> walls;

	void update();
	void renderFrame();

	void loadLevel(const std::string& filename);
};

