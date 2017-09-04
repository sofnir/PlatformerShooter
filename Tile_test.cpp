#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "Tile.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 300), "Tile - test");

	sf::Texture tilesTexture;
	tilesTexture.loadFromFile("Data/tilesTexture.png");

	Tile tile(tilesTexture);	
	tile.setTextureRect(sf::IntRect(70, 0, 70, 70));
	tile.setPosition(sf::Vector2f(100, 100));
	tile.setType("wall");

	std::cout << "Type: " << tile.getType().toAnsiString();

	while (window.isOpen())
	{		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed &&
				event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(tile);
		window.display();
	}
	return 0;
}