#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "..\KeyboardController.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Keyboard controller - test");
	window.setFramerateLimit(60);

	KeyboardController firstPlayerController(KeyboardController::Keys::ARROWS);
	std::cout << "First player\n";
	std::cout << "Move right: " << "Right arrow\n";
	std::cout << "Move left: " << "Left arrow\n";
	std::cout << "Move down: " << "Down arrow\n";
	std::cout << "Jump: " << "Up arrow\n";
	std::cout << "Shoot: " << "Enter\n\n";

	KeyboardController secondPlayerController(KeyboardController::Keys::WSAD);
	std::cout << "Second player\n";
	std::cout << "Move right: " << "D\n";
	std::cout << "Move left: " << "A\n";
	std::cout << "Move down: " << "S\n";
	std::cout << "Jump: " << "W\n";
	std::cout << "Shoot: " << "Space\n\n";

	while (window.isOpen())
	{								
		if (firstPlayerController.getIsJumpClicked())
		{
			std::cout << "First player: Jump!\n";
		}
		if (firstPlayerController.getMoveDirection() > 0)
		{
			std::cout << "First player: Move right!\n";
		}
		if (firstPlayerController.getMoveDirection() < 0)
		{
			std::cout << "First player: Move left!\n";
		}
		if (firstPlayerController.getIsMoveDownClicked())
		{
			std::cout << "First player: Move down!\n";
		}
		if (firstPlayerController.getIsShootClicked())
		{
			std::cout << "First player: Shoot!\n";
		}

		if (secondPlayerController.getIsJumpClicked())
		{
			std::cout << "Second player: Jump!\n";
		}
		if (secondPlayerController.getMoveDirection() > 0)
		{
			std::cout << "Second player: Move right!\n";
		}
		if (secondPlayerController.getMoveDirection() < 0)
		{
			std::cout << "Second player: Move left!\n";
		}
		if (secondPlayerController.getIsMoveDownClicked())
		{
			std::cout << "Second player: Move down!\n";
		}
		if (secondPlayerController.getIsShootClicked())
		{
			std::cout << "Second player: Shoot!\n";
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

			firstPlayerController.Control(event);
			secondPlayerController.Control(event);
		}		

		window.clear();		
		window.display();
	}
	return 0;
}