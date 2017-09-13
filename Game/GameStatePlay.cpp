#include "GameStatePlay.h"
#include "GameState.h"

GameStatePlay::GameStatePlay(Game * game)
{
	this->game = game;	

	createPlayers();
}

void GameStatePlay::draw()
{
	game->window.clear(Color::Grey);	
	game->window.draw(map);
	for (auto & player : players)
	{
		game->window.draw(player);
	}
	projectilesManager.draw(game->window);
	game->window.display();
}

void GameStatePlay::update()
{
	projectilesManager.updateMoving();
	projectilesManager.updateCollision(players);

	for (auto & player : players)
	{		
		player.updateMoving();
		player.updateCollision(map.getPlatforms());

		if (player.isShooting())
		{
			projectilesManager.addProjectile(player.getGun().createProjectile(player.getPlayer()));
		}
	}
}

void GameStatePlay::handleInput()
{
	sf::Event event;

	for (auto & player : players)
	{
		player.updateController(event);
	}	

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

void GameStatePlay::createPlayers()
{
	players.push_back(Character(0));
	players[0].setPosition(sf::Vector2f(100.0f, 50.0f));	
	players.push_back(Character(1));
	players[1].setPosition(sf::Vector2f(700.0f, 100.0f));
}
