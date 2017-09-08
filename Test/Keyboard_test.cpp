#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "..\KeyboardController.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Keyboard controller - test");
	window.setFramerateLimit(60);

	KeyboardController keyboardController;		
	std::cout << "Using: " << keyboardController.getControllerType() << "\n";
	std::cout << "Press right = Move right!\n";
	std::cout << "Press left = Move left!\n";
	std::cout << "Press space = Jump!\n";

	while (window.isOpen())
	{				
		keyboardController.Control();		
		
		if (keyboardController.getIsJumpClicked())
		{
			std::cout << "Jump!\n";
		}

		if (keyboardController.getMoveDirection() > 0)
		{
			std::cout << "Move right!\n";
		}

		if (keyboardController.getMoveDirection() < 0)
		{
			std::cout << "Move left!\n";
		}

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
		window.display();
	}
	return 0;
}