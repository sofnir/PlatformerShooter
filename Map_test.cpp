#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "Map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "Map - test");

	sf::Texture tileSet;
	tileSet.loadFromFile("Data/tilesTexture.png");

	Map map;
	map.load("Data/level1.txt");
	map.showValues();
	map.createTiles(tileSet, 70);

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
		window.draw(map);
		window.display();
	}

	return 0;
}