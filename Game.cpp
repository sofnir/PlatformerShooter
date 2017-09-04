#include "Game.h"
#include "GameState.h"

Game::Game()
{
	window.create(sf::VideoMode(800, 600), "Basic", sf::Style::Close);
	window.setFramerateLimit(60);
}

Game::~Game()
{
	while (!states.empty())
	{
		popState();
	}
}

void Game::pushState(GameState* state)
{
	states.push(state);
}

void Game::popState()
{
	delete states.top();
	states.pop();
}

GameState* Game::peekState()
{
	if (states.empty())
	{
		return nullptr;
	}
	else
	{
		return states.top();
	}
}

void Game::gameLoop()
{
	while (window.isOpen())
	{
		mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

		if (peekState() == nullptr)
		{
			continue;
		}

		peekState()->handleInput();
		peekState()->update();
		peekState()->draw();
	}
}
