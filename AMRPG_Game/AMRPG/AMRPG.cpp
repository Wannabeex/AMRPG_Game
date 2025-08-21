#include <iostream>
#include "Game.h"

int main() {
	Game game;		//Create
	game.init();	//Setup
	game.run();		//Play
	game.cleanup();	//End
	return 0;
}