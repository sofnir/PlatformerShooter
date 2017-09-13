#include "../Game.h"
#include "../GameStateMenu.h"
#include <iostream>

int main()
{
	std::cout << "1. Green screen = menu state\n2. Press Enter - go to the play state\n3. Red screen = play state\n";
	std::cout << "4. Press Esc - back to the menu state\n5. Green screen = menu state\n6. Press Esc - exit game";

	Game game;
	game.pushState<GameStateMenu>(& game);	
	game.gameLoop();

	return 0;
}