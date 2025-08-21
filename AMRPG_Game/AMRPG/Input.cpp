#include "Input.h"
#include <conio.h>

void Input::poll() {
	up = down = left = right = quit = false;

	if (_kbhit()) {
		char ch = _getch();
		if (ch == 'w') up = true;
		if (ch == 's') down = true;
		if (ch == 'a') left = true;
		if (ch == 'd') right = true;
		if (ch == 'q') quit = true;
	}
}