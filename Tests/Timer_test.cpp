#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <memory>
#include "../Timer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(Config::windowSize.x, Config::windowSize.y), "Timer- test");

	Data data;
	std::unique_ptr<Timer> timer = std::make_unique<Timer>();

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

		if (timer)
		{
			timer->update(dt);

			if (timer->getCurrentTime() <= 0)
			{
				timer = nullptr;
			}
		}				

		window.clear();

		if (timer)
		{
			window.draw(*timer);
		}
		
		window.display();
	}
	return 0;
}