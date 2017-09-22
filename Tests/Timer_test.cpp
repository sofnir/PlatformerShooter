#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "../Timer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(Config::windowSize.x, Config::windowSize.y), "Timer- test");

	Data data;
	Timer timer;

	sf::Clock clock;

	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}

		timer.update(dt);

		window.clear();
		window.draw(timer);
		window.display();
	}
	return 0;
}