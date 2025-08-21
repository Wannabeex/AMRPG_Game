#include "Renderer.h"
#include <windows.h>
#include <iostream>
#include <cstring>

void Renderer::clearScreen() {
	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			buffer[y][x].Char.AsciiChar = ' ';
			buffer[y][x].Attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
		}
	}
}

void Renderer::drawAt(int x, int y, char c) {
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
		buffer[y][x].Char.AsciiChar = c;
		buffer[y][x].Attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	}
}

void Renderer::drawString(int x, int y, const char* str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		drawAt(x + i, y, str[i]);
	}
}

void Renderer::present() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	COORD bufferCoord = { 0, 0 };
	SMALL_RECT writeRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	WriteConsoleOutputA(
		hOut,
		(CHAR_INFO*)buffer,
		bufferSize,
		bufferCoord,
		&writeRegion
	);
}

void Renderer::hideCursor() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hOut, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cursorInfo);
}

void Renderer::showCursor() {
	std::cout << "\033[?25h";
}