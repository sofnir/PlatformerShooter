#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <memory>
#include "../Dialog.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Dialog - test");

	Data data;
	std::unique_ptr<Dialog> dialog;

	std::cout << "Press NUM1 - create first dialog\n";
	std::cout << "Press NUM2 - create second dialog\n";
	std::cout << "Press NUM3 - create third dialog\n";

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1)
			{
				dialog = std::make_unique<Dialog>("FIRST TEAM WIN");
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2)
			{
				dialog = std::make_unique<Dialog>("SECOND TEAM WIN");
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num3)
			{
				dialog = std::make_unique<Dialog>("DRAW");
			}
		}

		window.clear();

		if (dialog)
		{
			window.draw(*dialog);
		}		

		window.display();
	}
	return 0;
}