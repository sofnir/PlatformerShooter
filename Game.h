#pragma once
#include <stack>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window\Mouse.hpp>

class GameState;

class Game
{
public:
	Game();
	~Game();

	sf::RenderWindow window;
	sf::Vector2f mousePosition;
	sf::Clock clock;

	void pushState(GameState* state);
	void popState();
	GameState* peekState();

	void gameLoop();

private:
	std::stack<GameState*> states;
};