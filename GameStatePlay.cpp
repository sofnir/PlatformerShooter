#include "GameStatePlay.h"
#include "GameState.h"

GameStatePlay::GameStatePlay(Game * game)
{
	this->game = game;	

	createPlayers();	
	createGui();
}

void GameStatePlay::draw()
{
	game->window.clear(Color::Grey);	
	game->window.draw(map);

	if (logic.getCurrentState() == Logic::LogicState::PLAYING)
	{
		for (auto & projectile : projectiles)
		{
			game->window.draw(projectile);
		}

		for (int i = 0; i < 2; i++)
		{
			game->window.draw(players[i]);
			game->window.draw(playersGUI[i]);
		}
	}

	if (dialog)
	{
		game->window.draw(*dialog);
	}

	if (timer)
	{
		game->window.draw(*timer);
	}

	game->window.display();
}

void GameStatePlay::update(float dt)
{	
	collision.playersWithPlatforms(players, map.getPlatforms());
	collision.playersWithProjectiles(players, projectiles);

	for (auto & projectile : projectiles)
	{
		projectile.updateMoving();
	}
	
	for (int i = 0; i < 2; i++)
	{
		players[i].update(dt);
		players[i].shoot(projectiles);
		playersGUI[i].setHp(players[i].getLifes());
	}

	updateGameLogic(dt);
				
	if (logic.getCurrentState() != Logic::LogicState::PLAYING && !dialog)
	{
		createDialog();
	}
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
			else if (event.key.code == sf::Keyboard::Space &&
				logic.getCurrentState() != Logic::LogicState::PLAYING)
			{
				logic.reset();				
				players[0].reset();				
				players[1].reset();
				dialog = nullptr;
			}				
			break;		
		default: break;
		}

		for (auto & player : players)
		{
			player.updateController(event);
		}
	}
	
	return;
}

void GameStatePlay::createPlayers()
{
	players.push_back(Character(Team::FIRST, new KeyboardController(KeyboardController::Keys::WSAD), 
		{sf::Vector2f(100.0f, 50.0f), true}));
	players.push_back(Character(Team::SECOND, new KeyboardController(KeyboardController::Keys::ARROWS), 
	{ sf::Vector2f(700.0f, 100.0f), false }));

}

void GameStatePlay::createGui()
{
	playersGUI.push_back(CharacterGUI("First player"));
	playersGUI[0].setPosition(sf::Vector2f(Config::windowSize.x / 6, Config::windowSize.y - 50.0f));
	playersGUI[0].setHp(players[0].getLifes());
	playersGUI.push_back(CharacterGUI("Second player"));
	playersGUI[1].setPosition(sf::Vector2f(Config::windowSize.x * 5 / 6, Config::windowSize.y - 50.0f));
	playersGUI[1].setHp(players[1].getLifes());
}

void GameStatePlay::createDialog()
{
	std::string text;

	switch (logic.getCurrentState())
	{
	case Logic::LogicState::FIRST_TEAM_WIN:
		text = "FIRST TEAM WIN";
		break;
	case Logic::LogicState::SECOND_TEAM_WIN:
		text = "SECOND TEAM WIN";
		break;
	case Logic::LogicState::DRAW:
		text = "DRAW";
		break;
	default:
		break;
	}

	dialog = std::make_unique<Dialog>(text);
}

void GameStatePlay::updateGameLogic(float dt)
{
	/* when anyone dead, count down the time, when time is over check if anyone is alive,
	if allive is anyone he is a winner if noone it is draw */
	if (timer)
	{
		timer->update(dt);

		if (timer->getCurrentTime() <= 0)
		{
			logic.update(players);
			timer = nullptr;
		}
	}
	else if (logic.getCurrentState() == Logic::LogicState::PLAYING && logic.isAnyPlayerDead(players))
	{
		timer = std::make_unique<Timer>();
	}
}
