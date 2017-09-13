#pragma once
#include <stack>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <memory>

class GameState;

class Game
{
public:
	Game();
	~Game();

	sf::RenderWindow window;
	sf::Vector2f mousePosition;
	sf::Clock clock;

	template<typename T> 
	void pushState(Game * game) 
	{
		states.push(std::make_unique<T>(game));
	}
	
	void popState();
	GameState* peekState();

	void gameLoop();

private:	
	std::stack<std::unique_ptr<GameState>> states;
};