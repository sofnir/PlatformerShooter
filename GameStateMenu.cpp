#include "GameStateMenu.h"
#include "GameStatePlay.h"
#include "GameState.h"

GameStateMenu::GameStateMenu(Game* game)
{
	this->game = game;
}

void GameStateMenu::playGame()
{
	game->pushState<GameStatePlay>(game);
}

void GameStateMenu::draw()
{
	game->window.clear(sf::Color::Green);
	game->window.display();
}

void GameStateMenu::update()
{
	;
}

void GameStateMenu::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				game->window.close();
			}
			else if (event.key.code == sf::Keyboard::Return)
			{
				playGame();
			}
			break;		
		default:
			break;
		}
	}

	return;
}
