#include "Renderer.h"
#include <windows.h>
#include <iostream>

void Renderer::clearScreen() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hOut, &csbi);
	DWORD cells = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD written;
	FillConsoleOutputCharacter(hOut, ' ', cells, { 0, 0 }, &written);
	SetConsoleCursorPosition(hOut, { 0, 0 });
}

void Renderer::drawAt(int x, int y, char c) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { (SHORT)(x - 1), (SHORT)(y - 1) };
	SetConsoleCursorPosition(hOut, pos);
	std::cout << c;
}

void Renderer::present() {
	std::cout.flush();
}

void Renderer::hideCursor() {
	std::cout << "\033[?25l";
}

void Renderer::showCursor() {
	std::cout << "\033[?25h";
}