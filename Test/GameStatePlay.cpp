#include "GameStatePlay.h"
#include "GameState.h"

GameStatePlay::GameStatePlay(Game * game)
{
	this->game = game;	
}

void GameStatePlay::draw()
{
	game->window.clear(sf::Color::Red);	
	game->window.display();
}

void GameStatePlay::update()
{
	;
}

void GameStatePlay::handleInput()
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
				game->popState();
				return;
			}
			break;		
		default: break;
		}
	}

	return;
}