#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <filesystem>
#include "Game.h"
#include "Input.h"
#include "Renderer.h"
#include "Wall.h"

Game::Game() : running(false) {}

void Game::init() {
	running = true;

	gfx.hideCursor();
	//Load level
	loadLevel("levels/level1.txt");

	//player.setPosition(5, 5);
	//walls.push_back({ 8, 5, '#' });

	gfx.clearScreen();
}

void Game::loadLevel(const std::string& filename) {
	std::ifstream file(filename);
	//Check if file corrupt
	if (!file) {
		std::cerr << "Failed to open level file: " << filename << "\n";
		return;
	}

	std::string line;

	int y = 0;
	while (std::getline(file, line)) {
		if (!line.empty() && line.back() == '\r')
			line.pop_back();

		for (int x = 0; x < line.size(); x++) {
			char tile = line[x];
			if (tile == '#') {
				walls.push_back({ x, y });
			}
			else if (tile == 'P') {
				player.setPosition(x, y);
			}
			//Room for more Symbols
		}
		y++;
	}
}

void Game::run() {
	while (running) {
		input.poll();
		if (input.quit) running = false;

		update();
		renderFrame();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void Game::update() {
	//Move Player
	int newX = player.getX();
	int newY = player.getY();
	if (input.up)		newY--;
	if (input.down)		newY++;
	if (input.left)		newX--;
	if (input.right)	newX++;

	//Check for Wall collision
	bool blocked = false;
	for (auto& w : walls) {
		if (w.x == newX && w.y == newY) {
			blocked = true;
			break;
		}
	}
	//Only move when no collision
	if (!blocked) {
		player.setPosition(newX, newY);
	}
}

void Game::renderFrame() {
	gfx.clearScreen();
	//Draw walls and player
	for (auto& w : walls) {
		gfx.drawAt(w.x, w.y, w.symbol);
	}
	player.draw(gfx);

	gfx.present();
}

void Game::cleanup() {
	gfx.showCursor();
}