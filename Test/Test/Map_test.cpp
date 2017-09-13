#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "../Map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Map - test");
	window.setFramerateLimit(60);

	Map map;
	std::cout << "Platform positions:\n";

	for (auto & platform : map.getPlatforms())
	{
		std::cout << platform.getPosition().x << ", " << platform.getPosition().y << std::endl;		
	}
	

	while (window.isOpen())
	{
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
		window.display();
	}
	return 0;
}