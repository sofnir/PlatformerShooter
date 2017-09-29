#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "../CharacterGUI.h"

int main()
{		
	sf::RenderWindow window(sf::VideoMode(400, 300), "CharacterGUI - test");

	Data data;
	CharacterGUI firstPlayerGUI("First player");
	firstPlayerGUI.setPosition(sf::Vector2f(200, 150));
	firstPlayerGUI.setHp(5);

	while (window.isOpen())
	{		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}			
		}

		window.clear();
		window.draw(firstPlayerGUI);
		window.display();
	}
	return 0;
}