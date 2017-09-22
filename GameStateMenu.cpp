#include "GameStateMenu.h"
#include "GameStatePlay.h"
#include "GameState.h"

GameStateMenu::GameStateMenu(Game* game)
{
	this->game = game;
	createTitle();	
	createButtons();
}

void GameStateMenu::createTitle()
{
	title.setFont(Data::font);
	title.setString("Platformer Shooter");
	title.setCharacterSize(60);
	title.setFillColor(Color::Blue);
	title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	title.setPosition(Config::windowSize.x / 2.0f, 100.0f);
}

void GameStateMenu::createButtons()
{
	buttons[0] = TextButton("PLAY", Data::font, 50);
	buttons[1] = TextButton("EXIT", Data::font, 50);

	for (int i = 0; i < 2; i++)
	{		
		buttons[i].setPosition(sf::Vector2f(Config::windowSize.x / 2.0f, 250.0f + i * 150.0f));
		buttons[i].setFillColor(Color::White);
		buttons[i].setHoverColor(Color::Green);
	}
}

void GameStateMenu::playGame()
{
	game->pushState<GameStatePlay>(game);
}

void GameStateMenu::draw()
{
	game->window.clear(Color::Grey);	
	game->window.draw(title);
	for (auto & button : buttons)
	{
		game->window.draw(button);
	}
	game->window.display();
}

void GameStateMenu::update(float dt)
{
	for (auto & button : buttons)
	{
		button.update(game->mousePosition);
	}
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
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (buttons[0].isHover(game->mousePosition))
				{
					playGame();
				}
				else if (buttons[1].isHover(game->mousePosition))
				{
					game->window.close();
				}
			}
			break;
		default:
			break;
		}
	}

	return;
}