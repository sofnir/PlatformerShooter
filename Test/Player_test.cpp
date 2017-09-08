#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "../Character.h"
#include "../Map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Player - test");
	window.setFramerateLimit(60);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("Data/tux.png");

	Character player;
	Map map;

	while (window.isOpen())
	{				
		player.update();
		player.checkCollision(map.getPlatforms());

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{								
				window.close();
			}				
		}		

		window.clear();
		window.draw(map);
		window.draw(player);		
		window.display();
	}
	return 0;
}