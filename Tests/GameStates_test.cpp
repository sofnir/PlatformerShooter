#include "../Game.h"
#include "../GameStateMenu.h"
#include <iostream>

int main()
{	
	Game game;
	game.pushState<GameStateMenu>(& game);	
	game.gameLoop();

	return 0;
}